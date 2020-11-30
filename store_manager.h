#ifndef _THEATER_MANAGER_
#define _THEATER_MANAGER_
#include <fstream>
#include <iostream>
#include "command.h"
#include "customers_collection.h"
#include "media_collection.h"
#include "media_factory.h"
#include "command_factory.h"
using namespace std;

// Class TheaterManager:
//  Description:
//   - This class read file from main to initialize customer, movie, commands
//  Implementation:
//   - Display inventory:
//     - Output all Comedy movies, then all Dramas, then all Classics.
class StoreManager {
    public:
        StoreManager();   // constructor
        ~StoreManager();  // destructor 

        // reads all customers information from text file
        void buildCustomers(ifstream & infile);

        // reads all movies command from text file
        void buildMovies(ifstream & infile);

        // process all commands from file
        void processCommands(ifstream & infile);

        //void testRemove(ifstream& infile);
    private:
        CustomerCollection customerCollection;
        MediaCollection mediaCollection;
};
#endif // !THEATER_MANAGER