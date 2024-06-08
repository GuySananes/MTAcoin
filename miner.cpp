#include "miner.h"

Miner::Miner(int id):id(id){}

/*
void Miner::update_target_parameters()
{
   difficulty_target=Server::block_chain.front().get_difficulty();
   height_target=Server::block_chain.front().get_height() +1;
   last_hash=Server::block_chain.front().get_hash();
   max_hash_val = max_hash_calculator(difficulty_target);
}
*/


/*
unsigned int Miner::calculate_hash_code()
{
    timestamp = std::time(nullptr);
    return hash(height_target,nonce,timestamp,last_hash,id);
}
*/

 void Miner::start_mining() //need thread things.
{
     BLOCK new_block = createNewBlock();
    while(true)
    {   
        //if there is a new BLOCK
        //update_target_parameters()
        new_block.nonce++;
        new_block.timestamp = time(NULL);
        unsigned int crc_res = blockChain->calculate_hash(new_block); //this also updates the timestamp
        bool hit = mined_success(crc_res);
        if(hit) //update the server "socket" or "mail-box"
        {
            Server::next_block= BLOCK(last_hash,height_target,difficulty_target,nonce,crc_res,id,static_cast<int>(timestamp));
            //tell the server there is something for him.
            //signal
        }
        else
            ++nonce;
    }
}

void* Miner::miner_thread_start(void* arg)
{
    auto* miner= static_cast<Miner*>(arg);
    miner->start_mining();
    return nullptr;
}


bool Miner::mined_success(const unsigned int crc_res)
{
    return (crc_res<=max_hash_val);
}

int Miner::get_id()
{
    return id;
}

BLOCK Miner::createNewBlock() {
    BLOCK last_block = ;
    BLOCK new_block;
    new_block.height = last_block.height + 1;
    new_block.prev_hash = last_block.hash;
    new_block.difficulty = last_block.difficulty;
    new_block.nonce = 0;
    new_block.relayed_by = this->id;
    return new_block;
}
