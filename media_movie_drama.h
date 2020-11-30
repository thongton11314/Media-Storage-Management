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
    virtual MovieType getMovieType() const;
    virtual string getHashKey() const;
    void print(ostream & out) const;

    // arithmetic operator, sort by director and then title
    virtual bool operator<(const Media&) const;
    virtual bool operator<=(const Media&) const;
    virtual bool operator>(const Media&) const;
    virtual bool operator>=(const Media&) const;
    virtual bool operator==(const Media&) const;
    virtual bool operator!=(const Media&) const;
    virtual Media & operator=(const Media&);
};

#endif //!_DRAMA_