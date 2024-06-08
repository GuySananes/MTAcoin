#pragma once
#include <iostream>
#include <list>
#include "block.h"
#include <zlib.h>
#include "global.h"


class Server
{
private:

    int number_of_blocks=0;
    int difficulty_target;    
    pthread_mutex_t bl_lock = PTHREAD_MUTEX_INITIALIZER;

public:

    static std::list<Block> block_chain;
    static Block next_block;

    // Constructor
    Server(int difficulty_target);
    
    bool verify_proof_of_work(Block & block_to_check);
    void print_last_block(Block& block_added);
    void add_block(Block & block_to_add);
    void start();

};  
