// add comments
// class movie type classis

#ifndef _CLASSIC_
#define _CLASSIC_
#include "media_movie.h"

// Class Classic:
//  Description: 
//   - This class create a classic type movie
//  Implementation:
//   - Create classic:
//     - Create and set the movie name and type related to the file
class Classic : public Movie {

    friend ostream& operator<<(ostream &, const Classic &);
    
public:

    // constructor
    Classic();

    // copy constructor
    Classic(const Classic & classic);
    
    // initial data from movie file
    bool setData(ifstream & infile);

    // deconstructor
    virtual ~Classic();

    // setter
    void setMonth(int month);
    void setMajorActorFirst(string name);
    void setMajorActorLast(string name);

    // getter
    int getMonth() const;
    string getMajorActorFirst() const;
    string getMajorActorLast() const;
    virtual MovieType getMovieType() const;
    virtual string getHashKey() const;

    // function
    void print(ostream & out) const;

    // arithmetic operator, sort by release date and major actor
    virtual bool operator<(const Media&) const;
    virtual bool operator<=(const Media&) const;
    virtual bool operator>(const Media&) const;
    virtual bool operator>=(const Media&) const;
    virtual bool operator==(const Media&) const;
    virtual bool operator!=(const Media&) const;
    virtual Media & operator=(const Media&);

private:
    string majorActorFirst; 
    string majorActorLast;
    int month;
};
#endif //!_CLASSIC_
