#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "media.h"

using namespace std;

class Command;

const int MINID = 1;                    // smallest id
const int MAXID = 9999;                 // max id
const int DEFAULT_ID = 0;               // default id
const string DEFAULT_NAME = "DEFAULT";  // default name

// add comments
class Customer {

    // display customer information
    friend ostream& operator<<(ostream &, const Customer&);

    public:

        // constructor
        Customer();

        // copy constructor
        Customer(const Customer &other);

        // deconstructor
        ~Customer();

        // setter
        void setID(int id);                     // set id
        void setFirstName(string first);        // set last name
        void setLastName(string last);          // set first name
        bool setData(ifstream & infile);        // fill data from file
        
        // getter
        int getId() const;                      // get ID
        string getFirstName() const;            // get first name
        string getLastName() const;             // get last name

        // get history borrow or return
        const vector<Command*> getHistories() const;

        // function
        void borrowMedia(Media * media);        // customer has borrowed media
        bool returnMedia(Media * target);       // customer has returned media
        void addHistory(Command * command);     // add commands history

        // operator in case needed
        bool operator<(const Customer&) const;
        bool operator<=(const Customer&) const;
        bool operator>(const Customer&) const;
        bool operator>=(const Customer&) const;
        bool operator==(const Customer&) const;
        bool operator!=(const Customer&) const;

    private:
        int id;                     // customer ID
        string firstName;           // customer first name
        string lastName;            // customer last name
        vector<Command*> history;   // customer history borrow or return
        vector<Media*> borrowing;   // customer media borrow currently
};
#endif // !_CUSTOMER_
