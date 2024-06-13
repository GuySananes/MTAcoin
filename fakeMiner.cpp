#include "fakeMiner.h"

extern pthread_mutex_t print_lock;

[[noreturn]] void fakeMiner::start_mining() {
    while (true) {
        if (height_target - 1 != my_server->get_latest_block_height())
            update_target_parameters();

        pthread_mutex_lock(&print_lock);
        std::cout << "Miner #" << id
                << " mined a new Block #" << std::dec << height_target
                << ", With the hash 0x" << std::hex << fake_hash << std::endl;

        auto new_block = Block(last_hash, height_target, difficulty_target, nonce, fake_hash, id,
                               static_cast<int>(timestamp));
        pthread_mutex_unlock(&print_lock);
        my_server->check_new_block(new_block);
        sleep(1); //1 second delay. 
    }
}
