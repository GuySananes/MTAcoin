#pragma once
#include <iostream>
#include <list>
#include "block.h"
#include <zlib.h>
#include "global.h"


class Server
{
private:

    int number_of_blocks = 1;
    const int difficulty_target;
    const unsigned int bit_mask = 0;

    std::list<Block> block_chain;
    Block next_block;

    pthread_mutex_t bl_lock = PTHREAD_MUTEX_INITIALIZER;
    //pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


private: //Private functions
    bool verify_proof_of_work_(Block & block_to_check);
    void add_block_(Block & block_to_add);

public:


    // Constructor
    Server(int difficulty_target);
    static void* server_thread_start(void* arg);
    void print_last_block(Block& block_added);
    void start();

    void check_new_block(Block &new_block);

    //Block data getters
    int get_latest_block_height();
    int get_latest_block_timestamp();
    unsigned int get_latest_block_hash();
    unsigned int get_latest_block_prev_hash();
    int get_latest_block_difficulty();
    int get_latest_block_nonce();
    int get_latest_block_relayed_by();

    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

};  
