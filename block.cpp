#include "block.h"

Block::Block() {
    this->prev_hash = 0;
    this->height = 1;
    this->difficulty = 0;
    this->nonce = 0;
    this->hash = 0;
    this->relayed_by = 0;
    this->timestamp = 0;
}


//creating a block - mostly used by the miners.
Block::Block(unsigned int prev_hash, int height, int difficulty, int nonce, int hash, int relayed_by, int timestamp) {
    this->prev_hash = prev_hash;
    this->height = height;
    this->difficulty = difficulty;
    this->nonce = nonce;
    this->hash = hash;
    this->relayed_by = relayed_by;
    this->timestamp = timestamp;
}

//get methods
unsigned int Block::get_hash() const {
    return hash;
}

int Block::get_difficulty() const {
    return difficulty;
}

int Block::get_height() const {
    return height;
}

int Block::get_relayed_by() const {
    return relayed_by;
}

int Block::get_nonce() const {
    return nonce;
}

unsigned int Block::get_prev_hash() const {
    return prev_hash;
}

int Block::get_timestamp() const {
    return timestamp;
}

//set method
void Block::set_difficulty(int difficulty_) {
    this->difficulty = difficulty_;
}
