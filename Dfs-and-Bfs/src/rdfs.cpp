#include <search.hpp>

void rdfs(Graph &G, int start, int destination) {
    G.setVisited(start);
    if(start == destination) return;

    int numberOfAdjacencyNodes = G.e[start].size();
    LinkedListNode<int> *p = G.e[start].getRoot();
    for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
        int v = p->value;
        if(G.isVisited(v)) continue;
        rdfs(G, v, destination);
        G.setTrace(start,v);
    }
}
