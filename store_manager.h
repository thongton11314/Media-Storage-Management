#ifndef _THEATER_MANAGER_
#define _THEATER_MANAGER_
#include <fstream>
#include "customers_collection.h"
#include "media_collection.h"
#include "media_factory.h"
#include "command_factory.h"
using namespace std;

// Class StoreManager:
//  Description:
//   - This class read file from main to initialize customer, movie, commands
//  Implementation:
//   - Process Borrow or Return
//   - Display History
//     - Display all borrow and return of a customer
//   - Display inventory:
//     - Output all Comedy movies, then all Dramas, then all Classics
class StoreManager {
    public:

        // constructor
        StoreManager();

        // destructor 
        ~StoreManager();

        // reads all customers information from text file
        void buildCustomers(ifstream & infile);

        // reads all movies command from text file
        void buildMovies(ifstream & infile);

        // process all commands from file
        void processCommands(ifstream & infile);

    private:

        // hold customers
        CustomerCollection customerCollection;

        // hold medias
        MediaCollection mediaCollection;
};
#endif // !THEATER_MANAGER