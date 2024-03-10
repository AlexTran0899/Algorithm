#include <search.hpp>

void dfs(Graph &G, int start, int destination) {
    Stack<int> stack;
    G.reset();
    stack.push(start);
    G.setVisited(start);

    while (!stack.empty()) {
        int u = stack.pop();
        if(u == destination) break;
//        std::cout << "looking at node: " << u << std::endl;


        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();

        Stack<int> temp;
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            if(!G.isVisited(v)){
                G.setVisited(v);
                G.setTrace(u, v);
                temp.push(v);
            }
        }
        while(!temp.empty()){
            stack.push(temp.pop());
        }
    }
}
