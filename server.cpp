#include "server.h"


std::list<Block> Server::block_chain;
Block Server::next_block = Block(0,1,0); //first dummy block. start of the chain


Server::Server(int difficulty_target) : difficulty_target(difficulty_target) 
{
    block_chain.push_front(next_block);
}

