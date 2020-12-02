#include "store_manager.h"

StoreManager::StoreManager() {}

StoreManager::~StoreManager() {}

void StoreManager::buildCustomers(ifstream & infile) {

    // early exit, and show error message that can not be read
    if (!infile) {
        cout << "Could not read customer file" << endl;
        return;
    }
    
    Customer* ptr;
    bool checkData;                         // used for reading good data
    while (!infile.eof()) {
        ptr = new Customer();               // create new customer object
        
        // must have setData implementation of client
        checkData = ptr->setData(infile);   // fill the customer object
        
        // add valid client
        if (checkData) {
            checkData = customerCollection.insertCustomer(ptr);
        }
        
        // ignore invalid client
        else {
            delete ptr;
        }
    }
    infile.close();
}

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

            // process comand and delete if fail to process
            // if succesful, return or borrow commands will be assign to customer
            if (!command->process(mediaCollection, customerCollection)) {
                delete command;
                command = nullptr;
            }

            // history and inventory will be deleted, 
            // since commands not assign to customer
            else if (command->getCommandType() == HISTORY
                || command->getCommandType() == INVENTORY) {
                delete command;
                command = nullptr;
            }
        }        
    }
    infile.close();
}