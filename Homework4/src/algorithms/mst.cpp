#include <graph.hpp> 
#include <sort.hpp> 

int find(int u, std::vector<int> &parent) {
    if (parent[u] == -1)
        return u;
    else
        return parent[u] = find(parent[u], parent);
}

std::vector<Edge> mst(Graph G) {
    std::vector<Edge> edges;
    int n = G.n;
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < G.e[u].size(); i += 1)
            edges.push_back(Edge(G.e[u][i])); 
    }

    std::vector<int> parent(n, -1);
    sort(edges, 0, edges.size()-1);
    std::vector<Edge> tree;
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu != pv) {
            parent[pu] = pv;
            tree.push_back(Edge(edges[i]));
        } 
    }
    return tree;
}

