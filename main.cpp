
#include <iostream>
#include "server.h"
#include <pthread.h>
#include "miner.h"
#include "fakeMiner.h"
#include "sched.h" 

#define NUMBERS_OF_MINERS 1

struct sched_param max_prio = {sched_get_priority_max(SCHED_FIFO)};
struct sched_param min_prio = {sched_get_priority_min(SCHED_RR)};

/*
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
*/

int main(int argc, char* argv[])
{
    pthread_attr_t attr_for_server; // Attributes for the server thread 
   // pthread_attr_t miner_attr;
    sched_param sch_params;
   // sched_param sch_params_miner;
    pthread_attr_init(&attr_for_server);
   // pthread_attr_init(&miner_attr);
    pthread_attr_setschedpolicy(&attr_for_server, SCHED_FIFO);
    //pthread_attr_setschedpolicy(&miner_attr, SCHED_FIFO);
    sch_params.sched_priority = 99;
    //sch_params_miner.sched_priority = 1;
     // Priority value for the server (real-time)
    pthread_attr_setschedparam(&attr_for_server, &sch_params);
   // pthread_attr_setschedparam(&miner_attr,&sch_params_miner);

    pthread_t server_thread, real_miner[NUMBERS_OF_MINERS];//, fake_miner_thread; // The fake miner will send wrong answers sometimes.
    //pthread_mutex_init(&mutex, nullptr);
    //pthread_cond_init(&cond, nullptr);

    Server* server = new Server(16); // 1 server
    Miner* miners[NUMBERS_OF_MINERS]; // 5 miners -> the 5th is the fake_miner.

    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        miners[i] = new Miner(i + 1, server);

    //fakeMiner* fake_miner = new fakeMiner(5, server);
    pthread_create(&server_thread, &attr_for_server, &Server::server_thread_start, server);
    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        pthread_create(&real_miner[i], nullptr, &Miner::miner_thread_start, miners[i]);

    //pthread_create(&fake_miner_thread, nullptr, &Miner::miner_thread_start, fake_miner);
    pthread_join(server_thread, nullptr);

    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        pthread_join(real_miner[i], nullptr);

    //pthread_join(fake_miner_thread, nullptr);
    
    // Delete dynamically allocated objects 
    delete server;
    //delete fake_miner;
    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        delete miners[i];

    // Clean up thread attributes, mutex and cond.
    pthread_attr_destroy(&attr_for_server);
    //pthread_mutex_destroy(&mutex);
    //pthread_cond_destroy(&cond);

    return 0;
}
