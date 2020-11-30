#ifndef _COMMANDS_
#define _COMMANDS_
#include "customers_collection.h"
#include "media_collection.h"
#include "media_movie_comedy.h"
#include "media_movie_classic.h"
#include "media_movie_drama.h"

const char BORROW = 'B';
const char RETURN = 'R';
const char HISTORY = 'H';
const char INVENTORY = 'I';
const char DEFAULT_TYPE = '!';
const string DEFAULT_FULLCOMMAND = "DEFAULT";

typedef char CommandType;

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

        // getter
        CommandType getCommandType() const;

        // function
        // process
        virtual void process(MediaCollection&, CustomerCollection&);

    protected:
        CommandType type;
        string fullCommand;
        virtual ostream& out(ostream &) const;
        // add more data if needed
};
#endif // !_COMMANDS_