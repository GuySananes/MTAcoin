#include "miner.h"


class fakeMiner : private Miner
{
    private:
    unsigned int fake_hash = 0xffffffff; //no seros at all. 

    public:
    void start_mining() override;
    fakeMiner(int id) : Miner(id) {}
};


