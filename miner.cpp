#pragma once
#include "miner.h"



Miner::Miner(int id):id(id){}

void Miner::update_target_parameters()
{
   difficulty_target=Server::block_chain.front().get_difficulty();
   height_target=Server::block_chain.front().get_height() +1;
   last_hash=Server::block_chain.front().get_hash();
   max_hash_val = static_cast<unsigned int>(std::pow(2,31-difficulty_target));
}


unsigned int Miner::calculte_hash_code()
{
    timestamp = std::time(nullptr);
    std::string data_to_hash = std::to_string(nonce) + std::to_string(timestamp) + std::to_string(last_hash) + std::to_string(id);
    unsigned int crc_res = crc32(0,reinterpret_cast<const Bytef*>(data_to_hash.c_str()),data_to_hash.size());
    //reinterpret cast is used to cast the pointer.
    return crc_res;

}

void Miner::start_mining() //need thread things.
{
    while(true)
    {
        unsigned int crc_res = calculte_hash_code();
        bool hit = mined_success(crc_res);
        if(hit) //update the server "socket" or mail-box :)
        {
            Server::next_block= Block(last_hash,height_target,difficulty_target,nonce,crc_res,id,static_cast<int>(timestamp)); 
            //tell the server there is something for him.
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