cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.1)

add_executable(helloworld_cli main.cpp)

set_target_properties(helloworld_cli PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON 
)