#pragma once
#include <iostream>
#include <list>
#include "block.h"
#include <zlib.h>
#include "global.h"

class Server {
private:
    //Data members
    int number_of_blocks = 1;
    const int difficulty_target;
    std::list<Block> block_chain;
    Block next_block;

    //pthread objects
    pthread_mutex_t bl_lock{};
    pthread_cond_t cond{};

private: //Private functions
    bool verify_proof_of_work_(Block &block_to_check);

    void add_block_(Block &block_to_add);

    void print_last_block_(Block &block_added);

public:
    // Constructor
    explicit Server(int difficulty_target);

    //destructor
    ~Server();

    //Member functions
    static void *server_thread_start(void *arg);

    [[noreturn]] void start();

    void check_new_block(Block &new_block);

    //Block data getters
    int get_latest_block_height();

    unsigned int get_latest_block_hash();

    int get_latest_block_difficulty();
};
