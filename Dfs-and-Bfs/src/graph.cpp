#include <graph.hpp>

Graph::Graph(int n) {
    this->n = n;
    this->e = std::vector<LinkedList<int> >(n, LinkedList<int>());
    this->reset();
}

Graph::~Graph() {
    this->e.clear();
    this->traces.clear();
    this->visited.clear();
}

void Graph::reset() {
    this->visited = std::vector<bool>(n, false);
    this->traces = std::vector<int>(n, -1);
}

bool Graph::isVisited(int v) {
    return this->visited[v];
}

void Graph::setVisited(int v) {
    this->visited[v] = true;
}
        
int Graph::trace(int u) {
    return this->traces[u];
}

void Graph::setTrace(int u, int v) {
    this->traces[v] = u;
}

void Graph::insertEdge(int u, int v, bool directed) {
    this->e[u].insert(v);
    if (not directed)
        this->e[v].insert(u);
}

std::vector<int> Graph::search(int start, int destination, void (*searchfn)(Graph &, int, int)) {
    searchfn(*this, start, destination); 
    std::vector<int> path;

    int u = destination;
    int counter = 10 + destination;
    while (u != -1 && counter > 0) {
        counter--;
        path.push_back(u);
        u = this->trace(u);
    }

    std::reverse(path.begin(), path.end());

    return path;
}
