
#include <iostream>
#include "server.h"
#include <pthread.h>
#include "miner.h"
#include "fakeMiner.h"


#define NUMBERS_OF_MINERS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;



int main(int argc,char* argv[])
{
    pthread_t server_thread, real_miner[4], fake_miner_thread; // the fake miner will send wrong answers sometimes.
    pthread_mutex_init(&mutex,nullptr);
    pthread_cond_init(&cond,nullptr);

    Server* server= new Server(20) ; //1 server
    Miner* miners[NUMBERS_OF_MINERS]; //5 miners -> the 5th is the fake_miner.

    for(int i=0;i<NUMBERS_OF_MINERS;++i)
        miners[i]= new Miner(i);

    fakeMiner* fake_miner= new fakeMiner(5);
    
    pthread_create(&server_thread,nullptr,&Server::server_thread_start,server);

    for(int i=0;i<NUMBERS_OF_MINERS;++i)
        pthread_create(&real_miner[i],nullptr,&Miner::miner_thread_start,miners[i]);

    pthread_create(&fake_miner_thread,nullptr,&Miner::miner_thread_start,fake_miner);

    pthread_join(server_thread,nullptr);

    for(int i=0;i<NUMBERS_OF_MINERS-1;++i)
        pthread_join(real_miner[i],nullptr);

    pthread_join(fake_miner_thread,nullptr);
    
    //free/delete all the threads

    return 0;


}
