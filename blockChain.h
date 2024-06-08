#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "main.h"


class BlockChain {
public:
    list<BLOCK> blockChain;
    pthread_mutex_t bl_mtx;

    static void addBlockToChain(const BLOCK &BLOCK);
    void printLastBlock();
    static unsigned int calculate_hash(BLOCK &BLOCK);

};

#endif //BLOCKCHAIN_H
