cmake_minimum_required(VERSION 2.8)

project(IpcServer)
add_executable(${PROJECT_NAME}
    "main.cpp"
    "jexception.h"  "jexception.cpp"
    "jsccb.h"   "jsccb.cpp"
    "jov2640.h" "jov2640.cpp")
