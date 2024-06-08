
#include "blockChain.h"

void BlockChain::addBlockToChain(const BLOCK &BLOCK)
{
    //lock_guard<mutex> lock(bL_mtx); //chatgpt suggestion for mutex lock and unlock
    pthread_mutex_lock(&bl_mtx);
    this->blockChain.push_front(BLOCK);
    if (blockChain.size() <= MAX_BLOCKCHAIN_SIZE)
    {
        this->blockChain.pop_back();
    }
    pthread_mutex_unlock(&bl_mtx);
}

void BlockChain::printLastBlock()
{

}

unsigned int BlockChain::calculate_hash(BLOCK &BLOCK) {
    string data = to_string(BLOCK.hash) + to_string(BLOCK.timestamp) +
                  to_string(BLOCK.prev_hash) + to_string(BLOCK.nonce) +
                  to_string(BLOCK.relayed_by);
    return crc32(0L, reinterpret_cast<const unsigned char*>(data.c_str()), data.length());
}