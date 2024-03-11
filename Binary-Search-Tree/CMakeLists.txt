cmake_minimum_required(VERSION 3.25)
project(Binary_Search_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Binary_Search_Tree
        assets/map.png
        assets/map_info.txt
        assets/view.py
        include/bst.hpp
        include/graph.hpp
        include/linked_list.hpp
        include/queue.hpp
        include/search.hpp
        include/stack.hpp
        src/bfs.cpp
        src/bst.cpp
        src/graph.cpp
        src/linked_list.cpp
        src/main.cpp
        src/queue.cpp
        src/stack.cpp)
