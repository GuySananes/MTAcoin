#pragma once
#include <iostream>


class Block {

private:
    int         	height;        // Incrementeal ID of the block in the chain
    int         	timestamp;    // Time of the mine in seconds since epoch
    unsigned int    hash;        // Current block hash value
    unsigned int    prev_hash;    // Hash value of the previous block
    int        	    difficulty;    // Amount of preceding zeros in the hash
    int         	nonce;        // Incremental integer to change the hash value
    int         	relayed_by;    // Miner ID


public:
    Block(unsigned int prev_hash,int height,int difficulty,int nonce,int hash,int relayed_by,int timestamp);
    Block(Block& block)=default;
    void set_difficulty(int difficulty);
    int get_difficulty();
    int get_height();
    int get_relayed_by();
    int get_nonce();
    unsigned int get_hash();
    unsigned int get_prev_hash();
    int get_timestamp();

}; 

