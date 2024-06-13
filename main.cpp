#include <iostream>
#include "server.h"
#include <pthread.h>
#include "miner.h"
#include "fakeMiner.h"
#include "sched.h"

#define NUMBERS_OF_MINERS 4
#define SERVER_PRIORITY 20
//global print_block
pthread_mutex_t print_lock = PTHREAD_MUTEX_INITIALIZER;

struct sched_param max_prio = {sched_get_priority_max(SCHED_FIFO)};
struct sched_param min_prio = {sched_get_priority_min(SCHED_RR)};

int main(int argc, char *argv[]) {
    //makeing sure the user puts difficulty number! 
    try {
        processArguments(argc, argv);
    } catch (...) //catch any throw..
    {
        exit(-1);
    }

    pthread_attr_t attr_for_server; // Attributes for the server thread 
    sched_param sch_params;
    pthread_attr_init(&attr_for_server);
    pthread_attr_setschedpolicy(&attr_for_server, SCHED_FIFO);
    sch_params.sched_priority = SERVER_PRIORITY;

    pthread_attr_setschedparam(&attr_for_server, &sch_params); //Priority value for the server

    // The fake miner will send wrong blocks every 1 sec.
    pthread_t server_thread, real_miner[NUMBERS_OF_MINERS], fake_miner_thread;

    auto server = new Server(std::stoi(argv[1])); // 1 server
    Miner *miners[NUMBERS_OF_MINERS]; // 5 miners -> the 5th is the fake_miner.

    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        miners[i] = new Miner(i + 1, server); //4 normal miners

    auto fake_miner = new fakeMiner(5, server); //1 fake miner

    pthread_create(&server_thread, &attr_for_server, &Server::server_thread_start, server);

    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        pthread_create(&real_miner[i], nullptr, &Miner::miner_thread_start, miners[i]);

    pthread_create(&fake_miner_thread, nullptr, &Miner::miner_thread_start, fake_miner);
    pthread_join(server_thread, nullptr);

    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        pthread_join(real_miner[i], nullptr);

    pthread_join(fake_miner_thread, nullptr);

    //Delete dynamically allocated objects 
    delete server;
    delete fake_miner;
    for (int i = 0; i < NUMBERS_OF_MINERS; ++i)
        delete miners[i];

    //Clean up thread attributes, mutex and cond.
    pthread_attr_destroy(&attr_for_server);
    pthread_mutex_destroy(&print_lock);
    return 0;
}
