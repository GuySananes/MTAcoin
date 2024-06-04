

#pragma once
#include "server.h"
#include <iostream>

std::list<Block> Server::block_chain;
Block Server::next_block = Block(0,1,0,0,0,0,0); //first dummy block. start of the chain , height is 1 

//create one dummy node 
Server::Server(int difficulty_target) : difficulty_target(difficulty_target) 
{
    next_block.set_difficulty(difficulty_target);
    block_chain.push_front(next_block);
    
}

void Server::print_last_block()
{

}

bool Server::verify_proof_of_work()
{
    
}


void Server::add_block()
{
    block_chain.push_front(next_block);
    //signals for everyone that there is a new block 
    //calling the print function 
    print_last_block();
}