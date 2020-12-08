#include "store_manager.h"

//-----------------------------------------------------------------------------
// constructor
StoreManager::StoreManager() {}

//-----------------------------------------------------------------------------
// deconstructor
StoreManager::~StoreManager() {}

//------------------------------------------------------------------------------
// buildCustomers
// read and build a list of customer from the file
void StoreManager::buildCustomers(ifstream & infile) {

    // early exit, and show error message that can not be read
    if (!infile) {
        cout << "Could not read customer file" << endl;
        return;
    }
    
    Customer* ptr;                          // used for create new customer
    bool checkData;                         // used for reading good data
    while (!infile.eof()) {
        ptr = new Customer();               // create new customer object

        // set data for customer
        if (ptr->setData(infile)) {

            // ignore duplicate
            if (!customerCollection.insertCustomer(ptr)) {
                delete ptr;
            }
        }

        // invalid data
        else {
            delete ptr;
        }
    }

    // close files
    infile.close();
}

//-----------------------------------------------------------------------------
// buildMovies
// read and build a list of movie from the file
void StoreManager::buildMovies(ifstream & infile) {

    // check if can read file
    if (!infile) {
        cout << "Could not read Movies file" << endl;
        return;
    }
    
    // use for create, and retrieve movie object    
    Media* obj;
    Media* dup;

    // read file
    while (!infile.eof()) {

        // create new media object
        obj = MediaFactory::createDVDMovie(infile);

        // if object exist
        if (obj != nullptr) {

            // insert, if duplicate add more stock
            if (!mediaCollection.insert(obj)) {
                if (mediaCollection.retrieve(*obj, dup)) {
                    dup->addStock(obj->getStock());
                    delete obj;
                }
            }            
        }
        obj = dup = nullptr;
    }

    // close file
    infile.close();
}

//-----------------------------------------------------------------------------
// processCommands
// get customer commands from the file to process
void StoreManager::processCommands(ifstream & infile) {

    // check if can read file
    if (!infile) {
        cout << "Could not read command file" << endl;
        return;
    }

    // use to create command object
    Command* command;

    // read file
    while (!infile.eof()) {

        // create command
        command = CommandFactory::createCommand(infile);

        // process command
        if (command != nullptr) {
            command->process(mediaCollection, customerCollection);
            command = nullptr;
        }
    }

    // close file
    infile.close();
}