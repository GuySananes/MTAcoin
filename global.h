#pragma once
#include <pthread.h>
#include <cmath>
#include <zlib.h>
#include <string>


extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
extern bool flag; //if the server is checking a miner's answer. 

#define MAX_CHAIN_SIZE 10

unsigned int hash(int height,int nonce, time_t timestamp, unsigned int last_hash,int id);

unsigned int max_hash_calculator(int difficulty);
