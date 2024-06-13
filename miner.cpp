#include "miner.h"

extern pthread_mutex_t print_lock;

void *Miner::miner_thread_start(void *arg) {
    auto *miner = static_cast<Miner *>(arg);
    miner->start_mining();
    return nullptr; //only for the void* to work. it won't return null ever.
}

Miner::Miner(int id_, Server *my_server_): id(id_), my_server(my_server_) {
}


void Miner::update_target_parameters() {
    difficulty_target = my_server->get_latest_block_difficulty();
    height_target = my_server->get_latest_block_height() + 1;
    last_hash = my_server->get_latest_block_hash();
    nonce = 0; //init nonce
}

unsigned int Miner::calculate_hash_code() {
    timestamp = std::time(nullptr); //take the current time since 1970 (unix epoch)
    return hash(height_target, nonce, timestamp, last_hash, id);
}


void Miner::start_mining() {
    while (true) {
        if (height_target - 1 != my_server->get_latest_block_height())
            update_target_parameters();

        unsigned int crc_res = calculate_hash_code(); //this also updates the timestamp
        //if the miner hits the right hash:
        if ((crc_res >> (32 - difficulty_target)) == 0) //update the server "socket" or "mail-box"
        {
            pthread_mutex_lock((&print_lock));
            std::cout << "Miner #" << id
                    << " mined a new Block #" << std::dec << height_target
                    << ", With the hash 0x" << std::hex << crc_res << std::endl;

            pthread_mutex_unlock(&print_lock);
            //update and send block to server
            auto new_block = Block(last_hash, height_target, difficulty_target, nonce, crc_res, id,
                                   static_cast<int>(timestamp));
            my_server->check_new_block(new_block);
        }
        //the miners mine all the time, therefor while sending
        //the new block to the server it will increase the nonce
        //to try different nonce
        ++nonce;
    }
}
