cmake_minimum_required (VERSION 3.1)

project (Augur)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

add_executable(augur main.cpp Event.cpp Match.cpp Node.cpp Root.cpp Team.cpp)