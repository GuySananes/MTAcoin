#pragma once
#include <pthread.h>
#include <cmath>
#include <zlib.h>
#include <string>

#define MAX_CHAIN_SIZE 100

unsigned int hash(int height,int nonce, time_t timestamp, unsigned int last_hash,int id);

