#pragma once
#include "block.h"

Block::Block(unsigned int prev_hash,int height,int difficulty,int nonce,int hash,int relayed_by,int timestamp)
{
    this->prev_hash=prev_hash;
    this->height=height;
    this->difficulty=difficulty;
    this->nonce=nonce;
    this->hash=hash;
    this->relayed_by=relayed_by;
    this->timestamp = timestamp;
}
unsigned int Block::get_hash()
 {
    return hash;
 }
int Block::get_difficulty()
{
    return difficulty;
}
int Block::get_height()
{
    return height;
}
void Block::set_difficulty(int difficulty)
{
    this->difficulty=difficulty;
}
int Block::get_relayed_by()

{
    return relayed_by;
} 
int Block::get_nonce()
{
    return nonce; 
}
unsigned int Block::get_prev_hash()
{
    return prev_hash;
}
int Block::get_timestamp()
{
    return timestamp;
}