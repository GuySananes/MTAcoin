#pragma once
#include <pthread.h>
#include <cmath>
#include <zlib.h>
#include <string>


/*extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
 */

#define MAX_CHAIN_SIZE 100

unsigned int hash(int height,int nonce, time_t timestamp, unsigned int last_hash,int id);

//unsigned int mask_hash_validation(int difficulty);
