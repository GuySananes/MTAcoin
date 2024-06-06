#include <pthread.h>

extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
extern bool flag; //if the server is checking a miner's answer. 


unsigned int hash(int height,int nonce, time_t timestamp, unsigned int last_hash,int id)
{
    std::string data_to_hash = std::to_string(nonce) + std::to_string(timestamp) + std::to_string(last_hash) + std::to_string(id);
    unsigned int crc_res = crc32(0,reinterpret_cast<const Bytef*>(data_to_hash.c_str()),data_to_hash.size());
    //reinterpret cast is used to cast the pointer.
    return crc_res;
}

unsigned int max_hash_calculator(int difficulty)
{
    return static_cast<unsigned int>((std::pow(2,32-difficulty))-1);
}