#pragma once
#include <pthread.h>
#include <zlib.h>
#include <string>
#include "zlib.h"
#include <iostream>

#define MAX_CHAIN_SIZE 100

unsigned int hash(int height, int nonce, time_t timestamp, unsigned int last_hash, int id);

void processArguments(int number_of_arguments, char *the_arguments[]);
