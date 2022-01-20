cmake_minimum_required(VERSION 3.9)
project(example)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES /usr/local/lib ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

add_executable(dijkstra_example main.cpp Graph.cpp Edge.cpp Node.cpp)
target_include_directories(dijkstra_example PUBLIC "${CMAKE_SOURCE_DIR}")

# target_link_libraries(dijkstra_example
                        # pthread
                        # ssl
                        # crypto
                        # z)