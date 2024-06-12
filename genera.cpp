#include "global.h"
#include "zlib.h"

unsigned int hash(int height,int nonce, time_t timestamp, unsigned int last_hash,int id)
{
    std::string data_to_hash = std::to_string(height) + std::to_string(nonce) + std::to_string(timestamp) + std::to_string(last_hash) + std::to_string(id);
    uLong crc_res = 0;
    crc_res = crc32(crc_res, reinterpret_cast<const Bytef *>(data_to_hash.c_str()), data_to_hash.size());
    //reinterpret cast is used to cast the pointer.
    return crc_res;
}
