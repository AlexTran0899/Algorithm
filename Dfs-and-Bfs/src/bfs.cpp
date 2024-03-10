#include <search.hpp>

void bfs(Graph &G, int start, int destination) {
    Queue<int> queue;
    G.reset();
    queue.push(start);

    G.setVisited(start);

    while (!queue.empty()) {
        int u = queue.pop();
        if(u == destination) break;

        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();

        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            if(!G.isVisited(v)){
                G.setTrace(u,v);
                G.setVisited(v);
                queue.push(v);
            }
        }
    }
}

//
//const arr = [
//[1],
//[3,2,0],
//[5,4,1],
//[4,1],
//[5,3,2],
//[4,2]
//]
//
//const bfs = (arr, start, end) => {
//const queue = [start]
//const trace = Array(arr.length).fill(-1);
//const visited = Array(arr.length).fill(false);
//let counter = 50;
//visited[start] = true
//while(queue.length > 0 && counter > 0) {
//counter -= 1
//const curr = queue.shift()
//if(curr == end) {break};
//
//
//const list = arr[curr]
//
//for(let i = 0; i < list.length; i++) {
//const num = list[i]
//if(visited[num]) continue
//visited[num] = true
//queue.push(num)
//trace[num] = curr
//}
//}
//
//console.log(trace)
//
//let curr = end
//const path = []
//
//while(curr != -1){
//path.push(curr)
//curr = trace[curr]
//}
//
//console.log(path.reverse())
//}
//
//bfs(arr,0,5)
//

