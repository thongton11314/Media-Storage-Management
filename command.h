#ifndef _COMMANDS_
#define _COMMANDS_
#include "customers_collection.h"
#include "media_collection.h"

// add comments here
class Command {

    // print out fulll command
    friend ostream& operator<<(ostream&, const Command&);

    public:

        // constructor
        Command();

        // copy constructor
        Command(const Command &);

        // deconstructor
        virtual ~Command();

        // setter
        void setCommandType(char);
        virtual bool setData(ifstream & infile);

        // getter
        int getCustomerId() const;
        char getCommandType() const;

        // function
        // process
        virtual void process(MediaCollection&, CustomerCollection&);

    protected:
        char type;
        string fullCommand;
        int customerID;

        virtual ostream& out(ostream &) const;
        // add more data if needed
};

#endif // !_COMMANDS_