#include <search.hpp>

void rdfs(Graph &G, int start, int destination) {
    if(start == destination) return;
    G.setVisited(start);

    int numberOfAdjacencyNodes = G.e[start].size();
    LinkedListNode<int> *p = G.e[start].getRoot();

    for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
        int v = p->value;
        if(!G.isVisited(v)){
            G.setTrace(start,v);
            return rdfs(G, v, destination);
        }
    }
}