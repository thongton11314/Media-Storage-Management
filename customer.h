#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include "media.h"

using namespace std;

// define constant
const int MINID = 1;                    // smallest id
const int MAXID = 9999;                 // max id
const int DEFAULT_ID = 0;               // default id
const string DEFAULT_NAME = "DEFAULT";  // default name

// class identifier
class Command;

// Class Customer:
//  Description:
//   - This class create a a new list of customers into the system
//  Implementation:
//   - Create customers:
//     - create, display and modify customers information in the system
class Customer {

    // display customer information
    friend ostream& operator<<(ostream &, const Customer&);

    public:

        // constructor
        Customer();
        Customer(int id);
        Customer(int id, string first, string last);

        // copy constructor
        Customer(const Customer &other);

        // deconstructor
        ~Customer();

        // setter
        // set id
        void setID(int id);

        // set last name
        void setFirstName(string first);

        // set first name
        void setLastName(string last);

        // fill data from file
        bool setData(ifstream & infile);

        // getter
        // get ID
        int getId() const;

        // get first name
        string getFirstName() const;

        // get last name
        string getLastName() const;

        // get history borrow or return
        const vector<Command*> getHistories() const;

        // function
        // customer has borrowed media
        void borrowMedia(Media * media);

        // customer has returned media
        bool returnMedia(Media * target);

        // add commands history
        void addHistory(Command * command);

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
        vector<Media*> borrowing;   // customer media borrow currently
        vector<Command*> history;   // customer history borrow or return
};
#endif // !_CUSTOMER_
