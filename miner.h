#pragma once
#include <iostream>
#include "block.h"
#include "server.h"
#include <math.h>
#include <zlib.h>
#include <ctime>
#include "global.h"

class Miner
{
private:
    int id;
    int difficulty_target;
    unsigned int last_hash;
    int height_target;
    int nonce=0;
    unsigned int max_hash_val; //we need to check 0s, we want the max number that has these 0s at the start 
    time_t timestamp;
    
public:

    Miner(int id);
    void update_target_parameters();

    [[noreturn]] void start_mining(); //should be a virtual func for the dumb-miner
    bool mined_success(const unsigned int crc_res);
    unsigned int calculate_hash_code();
    int get_id();
    
};


