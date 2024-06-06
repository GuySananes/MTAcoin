

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
    if(next_block.get_difficulty()!=difficulty_target)
        return false;
    else if(next_block.get_height()!=number_of_blocks+1)
        return false;
    else if(next_block.get_prev_hash()!=block_chain.front().get_hash())
        return false;

    unsigned int hash_test = //this calculates the hash, again.. :) 
        hash(next_block.get_height(),next_block.get_nonce(),static_cast<time_t>(next_block.get_timestamp()),
                 next_block.get_prev_hash(),next_block.get_relayed_by());
    
    if(hash_test!=next_block.get_hash())
        return false;
    else if(hash_test<=max_hash_calculator(difficulty_target))
        return false;

    return true; //if we survived all the checks.

}


void Server::add_block()
{
    block_chain.push_front(next_block);
    //signals for everyone that there is a new block 
    //calling the print function 
    print_last_block();
}

void Server::start()
{
    
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond,&mutex); //waiting for a block to check
    if(verify_proof_of_work())
    {
        add_block();
    }

    pthread_mutex_unlock(&mutex);





}