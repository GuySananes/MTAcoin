#include "miner.h"


class fakeMiner : private Miner
{
    private:
    unsigned int fake_hash = 0xffffffff; //no zeros at all.

    public:
    void start_mining() override;
    fakeMiner(int id_, Server* my_server_) : Miner(id_, my_server_) {}
};


