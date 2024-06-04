#pragma once
#include <iostream>
#include <list>
#include "block.h"
#include <zlib.h>

class Server
{
private:

    int number_of_blocks=0;
    int difficulty_target;    

public:

    static std::list<Block> block_chain;
    static Block next_block;

    // Constructor
    Server(int difficulty_target);
    
    bool verify_proof_of_work();
    void print_last_block();
    void add_block();

};  
