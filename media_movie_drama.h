// add comments
// class movie type drama

#ifndef _DRAMA_
#define _DRAMA_
#include "media_movie.h"

class Drama : public Movie {

    friend ostream& operator<<(ostream &, const Drama &);
    
public:

    // constructor
    Drama();

    // copy constructor
    Drama(const Drama &drama);

    // set data
    bool setData(ifstream & infile);

    // deconstructor
    virtual ~Drama();

    // getter
    virtual char getMovieType() const;
    void print(ostream & out) const;

    // arithmetic operator, sort by director and then title
    virtual bool operator<(const Media&) const;
    virtual bool operator<=(const Media&) const;
    virtual bool operator>(const Media&) const;
    virtual bool operator>=(const Media&) const;
    virtual bool operator==(const Media&) const;
    virtual bool operator!=(const Media&) const;
};

#endif //!_DRAMA_