#include <iostream>
#include <fstream>
#include <ostream>
#include "store_manager.h"
#include "bst.h"
using namespace std;
int main () {

    // instantiate theater manager class
    StoreManager storeManager;

    // instantiate file stream for setting data
    ifstream customerFile("data4customers.txt"),  // customer file
             movieFile("data4movies.txt"),        // movies file
             commandFile("data4commands.txt");    // command file

    // reads all customers information from text file
    storeManager.buildCustomers(customerFile);
    
    // reads all movies command from text file
    storeManager.buildMovies(movieFile);

    // process all commands from file
    storeManager.processCommands(commandFile);
    return 0;
}