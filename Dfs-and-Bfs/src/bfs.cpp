#include <search.hpp>

void bfs(Graph &G, int start, int destination) {
    Queue<int> queue;
    G.reset();
    queue.push(start);

    while (!queue.empty()) {
        int u = queue.pop();
        if(u == destination) break;

        G.setVisited(u);
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();

        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            if(G.isVisited(v)) continue;
            queue.push(v);
            G.setTrace(u, v);
        }
    }
}
