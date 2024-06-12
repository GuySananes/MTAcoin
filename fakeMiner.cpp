#include "fakeMiner.h"


void fakeMiner::start_mining() 
{
    while(true)
    {   
        if(height_target-1 != Server::block_chain.front().get_height()) 
            update_target_parameters();
        
            std::cout<<"Miner #"<<id
            <<" mined a new Block #"<<std::dec<<height_target
            <<", With the hash 0x"<<std::hex<<fake_hash<<std::endl;
            Server::next_block= Block(last_hash,height_target,difficulty_target,nonce,fake_hash,id,static_cast<int>(timestamp)); 
            pthread_cond_signal(&cond);
            sleep(1); //1 second delay.
    } 
}