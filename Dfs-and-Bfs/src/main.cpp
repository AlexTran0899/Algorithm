#include <iostream>
#include <vector>
#include <linked_list.hpp> 
#include <graph.hpp> 
#include <string>
#include <map>
#include <fstream>
#include <search.hpp>

#ifdef OPENCV
#include <opencv2/opencv.hpp>
#endif

bool testGraph(std::string algName) {
    Graph G(6);
    G.insertEdge(0, 1);
    G.insertEdge(1, 2);
    G.insertEdge(1, 3);
    G.insertEdge(2, 4);
    G.insertEdge(2, 5);
    G.insertEdge(4, 3);
    G.insertEdge(4, 5);

    for(int i = 0; i < G.e.size(); i++) {
        std::cout << "[ " << i << " ] ";
        G.e[i].print();
    }

    void (*searchfn)(Graph &, int, int);
    if (algName == "bfs")
        searchfn = bfs;
    else if (algName == "dfs")
        searchfn = dfs;
    else
        searchfn = rdfs;


    std::cout << "Path from 0 to 5 by " << algName << ": " ;
    std::vector<int> path = G.search(0, 5, searchfn);
    for (int i = 0; i < path.size(); ++i) 
        std::cout << path[i] << " ";
    std::cout << "\n";
    
    return true;
}

void searchOnCampus(std::string start = "BELL", std::string destination = "HAPG", std::string algName = "bfs") {
    std::ifstream reader("assets/map_info.txt");
    int n, m;
    reader >> n >> m;
    std::map<std::string, int> name2index;
    std::map<int, std::string> index2name;
    std::vector<int> xs;
    std::vector<int> ys;
    for (int i = 0; i < n; ++i) {
        int index, x, y;
        std::string name;
        reader >> index >> name >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        name2index[name] = index;
        index2name[index] = name;
    }

    Graph G(n);

    void (*searchfn)(Graph &, int, int);
    if (algName == "bfs")
        searchfn = bfs;
    else if (algName == "dfs")
        searchfn = dfs;
    else
        searchfn = rdfs;


    for (int i = 0; i < m; ++i) {
        int u, v;
        reader >> u >> v;
        G.insertEdge(u, v);
    }

    std::vector<int> path = G.search(name2index[start], name2index[destination], searchfn);

    std::cout << "Path from " << start  << " to " << " detination: " << start ;
    for (int i = 1; i < path.size(); ++i)
        std::cout << " -> " << index2name[path[i]];
    
    std::cout << "\n";

#ifdef OPENCV
    cv::Mat image = cv::imread("assets/map.png");
    for (int i = 0; i < n; ++i) {
        cv::circle(image, cv::Point(xs[i], ys[i]), 10, cv::Scalar(255, 0, 0), -1);
        cv::putText(image, index2name[i],  cv::Point(xs[i], ys[i]-10),  cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255, 0, 0), 1);
    }

    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) 
            cv::line(image, cv::Point(xs[path[i]], ys[path[i]]), cv::Point(xs[path[i-1]], ys[path[i-1]]), cv::Scalar(255, 0, 0), 4);
    }
    cv::imshow("Path from " + start + " to " + destination, image);
    cv::waitKey(0);

#else
    std::cout << "You have to use OpenCV to visualize your map road\n";
#endif


}
int main(int argc, char **args) {
    std::string algName("bfs");

    
    std::cout << "Perform unit test on your " << algName << " implementation" << std::endl;
    testGraph(algName);
    
    std::cout << "\n\n";
    
    searchOnCampus("JBHT", "HAPG", algName);

    std::cout << "\n";
    
}
