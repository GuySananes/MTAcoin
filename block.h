#pragma once
#include <iostream>


class Block {
private:
    int height; // Incremental ID of the block in the chain
    int timestamp; // Time of the mine in seconds since epoch
    unsigned int hash; // Current block hash value
    unsigned int prev_hash; // Hash value of the previous block
    int difficulty; // Amount of preceding zeros in the hash
    int nonce; // Incremental integer to change the hash value
    int relayed_by; // Miner ID


public:
    Block(); // empty constructor
    Block(unsigned int prev_hash, int height, int difficulty, int nonce, int hash, int relayed_by,
          int timestamp); //constructor
    Block(const Block &block) = default; //copy constructor
    //get methods
    int get_difficulty() const;

    int get_height() const;

    int get_relayed_by() const;

    int get_nonce() const;

    unsigned int get_hash() const;

    unsigned int get_prev_hash() const;

    int get_timestamp() const;

    //set method
    void set_difficulty(int difficulty_);
};
