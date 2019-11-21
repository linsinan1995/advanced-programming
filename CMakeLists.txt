cmake_minimum_required(VERSION 3.14)
# 项目信息
project (MyProject)
# 指定生成目标
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
# set(CMAKE_CXX_FLAGS   "-std=c++17")             # c++17
# set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
# set(CMAKE_CXX_FLAGS   "-Wall -Werror")          # 开启所有警告
# set(CMAKE_CXX_FLAGS_DEBUG   "-O0" )             # 调试包不优化
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG " )   # release包优化

add_executable(${PROJECT_NAME} use_list_build_stack.cpp)

# // rm -r build && mkdir build; cd build; cmake ..; make; ./MyProject; cd ..
# rm -r build && mkdir build; cd build; cmake -DCMAKE_BUILD_TYPE=Release ..; make; ./MyProject; cd ..
