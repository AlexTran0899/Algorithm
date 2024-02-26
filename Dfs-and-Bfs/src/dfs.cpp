#include <search.hpp>

void dfs(Graph &G, int start, int destination) {
    Stack<int> stack;
    G.reset();
    stack.push(start);

    while (!stack.empty()) {
        int u = stack.pop();
        if(u == destination) break;
        G.setVisited(u);

        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();

        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            if(G.isVisited(v)) continue;
            stack.push(v);
            G.setTrace(u, v);
        }
    }
}
