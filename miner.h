#pragma once
#include <iostream>
#include "block.h"
#include "server.h"
#include <zlib.h>
#include <ctime>
#include "global.h"
#include <pthread.h>

class Miner {
protected:
    //Data members
    int id;
    int difficulty_target = 0;
    unsigned int last_hash = 0;
    int height_target = 1;
    int nonce = 0;
    int timestamp;
    Server *my_server;

public:
    static void *miner_thread_start(void *arg);

    //constructor
    Miner(int id_, Server *my_server_);

    //functions
    void update_target_parameters();

    virtual void start_mining(); //to be overridden by fakeMiner
    unsigned int calculate_hash_code();
};
