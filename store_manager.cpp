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
            cout << *ptr << endl;
            delete ptr; // delete this if collection is done
            // add customer into collection here
        }
        
        // ignore invalid client
        else {
            delete ptr;
        }
    }
}

void StoreManager::buildMovies(ifstream & infile) {

    /*
    // check if can read file
    if (!infile) {
        cout << "Could not read Movies file" << endl;
        return;
    }
    
    // use for create movie object
    Media* obj;
    bool isDup = false;

    // read entire file information
    while (!infile.eof()) {

        // create new client object
        obj = MediaFactory::createDVDMovie(infile);

        // valid movies
        if(obj != nullptr) {

            // comedy type
            if (dynamic_cast<Movie*>(obj)->getMovieType() == 'F') {              
                isDup = collectionComedies.insert(dynamic_cast<Comedy*>(obj));
            }

            // dramma type
            else if (dynamic_cast<Movie*>(obj)->getMovieType() == 'D') {
                isDup = collectionDramas.insert(dynamic_cast<Drama*>(obj));
            }

            // classic type
            else {
                isDup = collectionClassics.insert(dynamic_cast<Classic*>(obj));
            }
        }

        if (isDup)
            delete obj;
    }
    */
}

void StoreManager::processCommands(ifstream &infile) {
    // read until the end of commands file
    // not need to store commands lines
        // create a command object by CommandFactory::createCommand(infile)
        // process commannd
            // command.processCommand(collectionMedias, collectionCustomers)
}

void StoreManager::test() {
    collectionComedies.display();
    cout << endl;
    collectionDramas.display();
    cout << endl;
    collectionClassics.display();
    cout << endl;
}