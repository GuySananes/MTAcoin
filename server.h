#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <list>
#include "block.h"

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
    
    bool verify_proof_of_work(/*some hash*/);
    void init_first_block();
    void print_last_block();

};  

#endif //SERVER_H