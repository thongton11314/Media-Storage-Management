// add comments
// class movie type comedy

#ifndef _COMEDY_
#define _COMEDY_
#include "media_movie.h"

// Class Comedy:
//  Description:
//   - This class create a comedy type movie
//  Implementation:
//   - Create comedy:
//     - Create and set movie information related to the file
class Comedy : public Movie {

    friend ostream& operator<<(ostream &, const Comedy &);

public:

    // constructor
    Comedy();

    // copy constructor
    Comedy(const Comedy & other);

    // set data
    bool setData(ifstream & infile);

    // deconstructor
    virtual ~Comedy();

    // getter
    virtual MovieType getMovieType() const;
    virtual string getHashKey() const;

    void print(ostream & out) const;

    // arithmetic operator, sort by title and then year release
    virtual bool operator<(const Media&) const;
    virtual bool operator<=(const Media&) const;
    virtual bool operator>(const Media&) const;
    virtual bool operator>=(const Media&) const;
    virtual bool operator==(const Media&) const;
    virtual bool operator!=(const Media&) const;
    virtual Media & operator=(const Media&);
};

#endif //!_CLASSIC_
