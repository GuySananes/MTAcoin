#ifndef BITCOIN_MAIN_H
#define BITCOIN_MAIN_H

#include <iostream>
#include <zlib.h>
#include <list>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <ctime>
#include <chrono>
#include <cmath>


#define NUM_MINERS 4
#define INVALID_MINER 1
#define MAX_BLOCKCHAIN_SIZE 100

using namespace std;
//in case we want to use struct instead of class BLOCK
typedef struct {
    int height;            // Incremental ID of the BLOCK in the chain
    int timestamp;         // Time of the mine in seconds since epoch
    unsigned int hash;     // Current BLOCK hash value
    unsigned int prev_hash;// Hash value of the previous BLOCK
    int difficulty;        // Amount of preceding zeros in the hash
    int nonce;             // Incremental integer to change the hash value
    int relayed_by;        // Miner ID
} BLOCK;

#endif //BITCOIN_MAIN_H
