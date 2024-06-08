cmake_minimum_required(VERSION 3.28)
project(cryptocurrency_mining_linux_thread_proje)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cryptocurrency_mining_linux_thread_proje
        block.cpp
        block.h
        fakeMiner.cpp
        fakeMiner.h
        genera.cpp
        global.h
        main.cpp
        miner.cpp
        miner.h
        server.cpp
        server.h)
