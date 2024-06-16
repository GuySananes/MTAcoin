Hey! 
This is a summary for the program in this repository. 
Thank you for reading! :) 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
This C++ program, written with object-oriented programming (OOP) principles on a Linux machine, simulates a cryptocurrency blockchain network with multiple threads. 
It includes a server thread that manages the blockchain and four miner threads that compute hashes for new blocks. 
The program utilizes pthread locks and condition variables to ensure proper synchronization between the threads on a single-core system.
Miners start from the current block, increment the nonce, update the timestamp, and calculate a hash using the crc32 function. 
Valid blocks are added to the blockchain by the server, which also handles invalid block submissions and includes error handling and validation for both the server and miners.
The server thread uses a condition variable to wait for notifications from miner threads about successfully mined blocks. 
When a valid block is received, the server appends it to the blockchain, and the miners check for the updated blockchain to start mining on the new block.
An additional miner thread is included to test the server's ability to handle invalid block submissions by sending an invalid block every second.
The program can be run using the provided Makefile, requiring g++ and ZLIB. It follows safe thread coding practices and demonstrates the use of condition variables and mutexes for synchronizing access to shared resources between multiple threads.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
