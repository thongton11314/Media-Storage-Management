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
        ptr = new Customer();               // create new client object
        
        // must have setData implementation of client
        checkData = ptr->setData(infile);   // fill the client object
        
        // add valid client
        if (checkData) {
            //cout << *ptr << endl;
            //delete ptr; // delete this if collection is done
            // add customer into collection here
            checkData = customerCollection.insertCustomer(ptr);
        }
        
        // ignore invalid client
        else {
            delete ptr;
        }
    }
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
    cout << "After Insert, total: " << mediaCollection.getTotalMedia() << endl;
    mediaCollection.display();
    infile.close();
}

void StoreManager::processCommands(ifstream &infile) {

    // check if can read file
    if (!infile) {
        cout << "Could not read command file" << endl;
        return;
    }

    Command* command;

    // use for create, and retrieve movie object    

    while (!infile.eof()) {

        // create new media object
        command = CommandFactory::createCommand(infile);

        // if object exist
        if (command != nullptr) {
            cout << *command << endl;
            //command->process(mediaCollection, customerCollection);
        }
        delete command;
    }
}

/*
void StoreManager::testRemove(ifstream& infile) {

    // check if can read file
    if (!infile) {
        cout << "Could not read Movies file" << endl;
        return;
    }

    // use for create, and retrieve movie object    
    Media* obj;
    while (!infile.eof()) {

        // create new media object
        obj = MediaFactory::createDVDMovie(infile);

        // if object exist
        if (obj != nullptr) {
            mediaCollection.remove(*obj);
        }
        delete obj;
    }
    cout << "After Remove, total: " << ClassicCollection.getTotalNode() << endl;
    ClassicCollection.display();
    infile.close();
}
*/