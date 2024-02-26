cmake_minimum_required(VERSION 3.25)
project(Dfs_and_Bfs)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Dfs_and_Bfs
        assets/map.png
        assets/map_info.txt
        assets/view.py
        include/graph.hpp
        include/linked_list.hpp
        include/queue.hpp
        include/search.hpp
        include/stack.hpp
        src/bfs.cpp
        src/dfs.cpp
        src/graph.cpp
        src/linked_list.cpp
        src/main.cpp
        src/queue.cpp
        src/rdfs.cpp
        src/stack.cpp)
