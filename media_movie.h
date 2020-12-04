// add comments here
// parents class of comedy, drama, classical class. This is pure virtual function
// this class function will hold commonds function for inherited class which are classic, comedy, drama

#ifndef _MOVIE_
#define _MOVIE_
#include "media.h"

// Class Movie:
//  Description:
//   - This class controll and modify movies in the system
//   - parent function of comedy,drama and classic
//  Implementation:
//   - Create movie:
//     - get and set movie information in the system
class Movie : public Media {
    
    // use to use << opertor
    friend ostream& operator<<(ostream & out, const Movie & Movie);
public:

    // destructor, for late biding
    virtual ~Movie();
    
    // setter
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setYear(int year);

    // getter
    virtual string getDirector() const;
    virtual string getTitle() const; 
    virtual int getYear() const;
    virtual bool setData(ifstream & infile) = 0;
    
    // pure virtual function
    virtual MovieType getMovieType() const = 0;
    virtual MediaType getMediaType() const;
    virtual string getHashKey() const = 0;

    // arithmetic operator
    virtual bool operator<(const Media&) const = 0;
    virtual bool operator<=(const Media&) const = 0;
    virtual bool operator>(const Media&) const = 0;
    virtual bool operator>=(const Media&) const = 0;
    virtual bool operator==(const Media&) const = 0;
    virtual bool operator!=(const Media&) const = 0;
    virtual Media & operator=(const Media&) = 0;

protected:
    MovieType type;
    string director;
    string title;
    int year;
    virtual void print(ostream & out) const = 0;
};
#include "media_movie_comedy.h"
#include "media_movie_classic.h"
#include "media_movie_drama.h"
#endif // !_MOVIE_
