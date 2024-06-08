/*
#ifndef BLOCK_H
#define  BLOCK_H
#include "main.h"


class BLOCK {

private:
    int         	height;        // Incremental ID of the BLOCK in the chain
    int         	timestamp;    // Time of the mine in seconds since epoch
    unsigned int    hash;        // Current BLOCK hash value
    unsigned int    prev_hash;    // Hash value of the previous BLOCK
    int        	    difficulty;    // Amount of preceding zeros in the hash
    int         	nonce;        // Incremental integer to change the hash value
    int         	relayed_by;    // Miner ID


public:
    BLOCK(int height,int timestamp, int hash, unsigned int prev_hash,int difficulty,int nonce,int relayed_by);
    BLOCK(const BLOCK& BLOCK)=default;
    void set_difficulty(int difficulty);
    int get_difficulty() const;
    int get_height() const;
    int get_relayed_by() const;
    int get_nonce() const;
    unsigned int get_hash() const;
    unsigned int get_prev_hash() const;
    int get_timestamp() const;

};

#endif //BLOCK_H*/
