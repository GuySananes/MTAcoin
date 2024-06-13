#include "miner.h"

class fakeMiner final : public Miner
{
    private:
    unsigned int fake_hash = 0xffffffff; //no zeros at all.

    public:
    [[noreturn]] void start_mining() override;
    fakeMiner(int id_, Server* my_server_) : Miner(id_, my_server_) {}//inherit Miner constructor
};


