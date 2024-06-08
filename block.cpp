/*
#include "BLOCK.h"

BLOCK::BLOCK(int height,int timestamp, int hash, unsigned int prev_hash,int difficulty,int nonce,int relayed_by)
{
    this->height=height;
    this->timestamp = timestamp;
    this->hash=hash;
    this->prev_hash=prev_hash;
    this->difficulty=difficulty;
    this->nonce=nonce;
    this->relayed_by=relayed_by;

}
unsigned int BLOCK::get_hash() const
 {
    return hash;
 }
int BLOCK::get_difficulty() const
{
    return difficulty;
}
int BLOCK::get_height() const
{
    return height;
}
void BLOCK::set_difficulty(int diff)
{
    this->difficulty = diff;
}
int BLOCK::get_relayed_by() const

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