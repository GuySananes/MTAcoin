#include <iostream>
#include "block.h"

class miner
{
private:
    //Block* last_block;
    int id;
    int difficulty_target;
    int height_target;
    int nonce=0;
    unsigned int difficulty_mask;
    
public:

    miner(int id);
    void update_target_parameters();
    void start_mining();
    bool mined_success();
    
};


