#ifndef SERVER_H
#define  SERVER_H

#include "main.h"
#include "BLOCK.h"


class Server
{
private:

    int number_of_blocks=0;
    int difficulty_target;    

public:

    static std::list<BLOCK> block_chain;
    static BLOCK next_block;

    // Constructor
    explicit Server(int difficulty_target);
    
    bool verify_proof_of_work();
    void print_last_block();
    void add_block();
    void start();

};  
