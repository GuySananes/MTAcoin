#include <pthread.h>

extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
extern bool flag; //if the server is checking a miner's answer.

