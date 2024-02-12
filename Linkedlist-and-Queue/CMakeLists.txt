cmake_minimum_required(VERSION 3.25)
project(HW1_Linkedlist_and_Queue)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(HW1_Linkedlist_and_Queue
        include/graph.hpp
        include/linked_list.hpp
        include/queue.hpp
        src/graph.cpp
        src/linked_list.cpp
        src/main.cpp
        src/queue.cpp src/linked_list.cpp)
