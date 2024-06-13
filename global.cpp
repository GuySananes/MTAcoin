#include "global.h"

unsigned int hash(int height, int nonce, time_t timestamp, unsigned int last_hash, int id) {
    std::string data_to_hash = std::to_string(height) + std::to_string(nonce) + std::to_string(timestamp) +
                               std::to_string(last_hash) + std::to_string(id);
    uLong crc_res = 0;
    crc_res = crc32(crc_res, reinterpret_cast<const Bytef *>(data_to_hash.c_str()), data_to_hash.size());
    //reinterpret cast is used to cast the pointer.
    return crc_res;
}

void processArguments(int number_of_arguments, char *the_arguments[]) {
    try {
        if (number_of_arguments < 2) {
            //We did not get the difficulty
            throw std::string("No argument provided***\nPlease run the program again with difficulty number.\n");
        }

        int difficulty = std::stoi(the_arguments[1]);

        if (difficulty <= 0) {
            throw std::string(
                "Difficulty has to be positive!***\nPlease run the program again with difficulty number.\n");
        }
    } catch (const std::string &error) {
        std::cout << "Error!!!:\n ***" << error << std::endl;
        throw; // Rethrow the exception to be caught in the calling context
    }
}
