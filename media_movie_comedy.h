// add comments
// class movie type comedy

#ifndef _COMEDY_
#define _COMEDY_
#include "media_movie.h"

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
    virtual char getMovieType() const;
    void print(ostream & out) const;

    // arithmetic operator, sort by title and then year release
    virtual bool operator<(const Media&) const;
    virtual bool operator<=(const Media&) const;
    virtual bool operator>(const Media&) const;
    virtual bool operator>=(const Media&) const;
    virtual bool operator==(const Media&) const;
    virtual bool operator!=(const Media&) const;
};

#endif //!_CLASSIC_