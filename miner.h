#pragma once
#include <iostream>
#include "block.h"
#include "server.h"
#include <zlib.h>
#include <ctime>
#include "global.h"

class Miner
{
protected:
    int id;
    int difficulty_target=0;
    unsigned int last_hash=0;
    int height_target=1;
    int nonce=0;
    unsigned int mask=1;
    time_t timestamp;
    Server *my_server;


public:

    static void* miner_thread_start(void* arg);

    Miner(int id_, Server *my_server_);

    void update_target_parameters();

    virtual void start_mining(); //should be a virtual func for the dumb-miner
    bool mined_success(const unsigned int crc_res) const;
    unsigned int calculate_hash_code();
    int get_id();
    
};


