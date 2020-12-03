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

const int MINID = 1;                    // smallest id
const int MAXID = 9999;                 // max id
const int DEFAULT_ID = 0;               // default id
const string DEFAULT_NAME = "DEFAULT";  // default name

//class Command
class Command;

// Class Hashtable:
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
        void addHistory(Command * command);       // add commands history

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
