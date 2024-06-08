#ifndef MINER_H
#define MINER_H

#include "BLOCK.h"
#include "server.h"
#include "global.h"
#include "blockChain.h"

class Miner
{
private:
    int id;
    BlockChain *blockChain;
    /*int difficulty_target{};
    unsigned int last_hash{};
    int height_target{};
    int nonce=0;
    unsigned int max_hash_val{}; //we need to check 0s, we want the max number that has these 0s at the start
    time_t timestamp{};*/
    
public:

    explicit Miner(int id);
    void update_target_parameters();

    [[noreturn]] virtual void start_mining(); //should be a virtual func for the dumb-miner
    static void* miner_thread_start(void* arg);
    static bool mined_success(unsigned int crc_res);
    //unsigned int calculate_hash_code();
    BLOCK createNewBlock();
    int get_id();
    
};

#endif //MINEr_H
