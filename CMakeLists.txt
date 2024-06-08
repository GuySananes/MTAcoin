cmake_minimum_required(VERSION 3.28)
project(cryptocurrency_mining_linux_thread_proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cryptocurrency_mining_linux_thread_proj
        BLOCK.cpp
        BLOCK.h
        fakeMiner.cpp
        fakeMiner.h
        global.h
        main.cpp
        miner.cpp
        miner.h
        server.cpp
        server.h
        blockChain.cpp
        blockChain.h
        main.h)
