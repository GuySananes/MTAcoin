
#include "miner.h"



Miner::Miner(int id):id(id){}

void Miner::update_target_parameters()
{
   difficulty_target=Server::block_chain.front().get_difficulty();
   height_target=Server::block_chain.front().get_height() +1;
   last_hash=Server::block_chain.front().get_hash();
   max_hash_val = max_hash_calculator(difficulty_target);
   nonce =0;
}


unsigned int Miner::calculate_hash_code()
{
    timestamp = std::time(nullptr);
    return hash(height_target,nonce,timestamp,last_hash,id);
}

void Miner::start_mining() //need thread things.
{
    while(true)
    {   
        if(height_target-1 != Server::block_chain.front().get_height()) 
            update_target_parameters();
        
        unsigned int crc_res = calculate_hash_code(); //this also updats the timestamp
        bool hit = mined_success(crc_res);

        if(hit) //update the server "socket" or "mail-box"
        {
            std::cout<<"Miner #"<<id
            <<" mined a new Block #"<<height_target
            <<", With the hash "<<crc_res<<std::endl;
            Server::next_block= Block(last_hash,height_target,difficulty_target,nonce,crc_res,id,static_cast<int>(timestamp)); 
            pthread_cond_broadcast(&cond); // in case there is more than 1 server..
                                            //we could use signal because only 1 server is waiting.
        }
        else
            ++nonce;
    } 
}

bool Miner::mined_success(const unsigned int crc_res)
{
    return (crc_res<=max_hash_val);
}

int Miner::get_id()
{
    return id;
}