#ifndef _MEDIA_
#define _MEDIA_
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;

const int DEFAULT_STOCK = 0;
const string DEFAULT_TITLE = "DEFAULT";
const string DEFAULT_PERSON = "DEFAULT";
const int DEFAULT_NUM = 0;

namespace Types {

    enum MediaType : char {
        DVDMovieType = 'D',
        DefaultMediaType = '!'
    };

    enum MovieType : char {
        ComedyType = 'F',
        ClassicType = 'C',
        DramaType = 'D',
        DefaultMovieType = '!'
    };
}

using namespace Types;

// Class Media:
//  Description:
//   - A parent class of movie
//  Implementation:
//   - Create media:
//     - Control and modify the movie section
class Media {
    
    // use to use << opertor
    friend ostream& operator<<(ostream & out, const Media & media);
    
public :

    // deconstructor, for late binding
	virtual ~Media();

    // setter
    virtual void setStock(unsigned int amount);
    virtual bool setData(ifstream & infile) = 0;
	
    // getter
    virtual int getStock() const;

    // function
    virtual void addStock(unsigned int amount);
    virtual bool reduceStock(int amount);
    
    // pure virtual function
    virtual MediaType getMediaType() const = 0;

    // arithmetic operator    
    virtual bool operator<(const Media&) const = 0;
    virtual bool operator<=(const Media&) const = 0;
    virtual bool operator>(const Media&) const = 0;
    virtual bool operator>=(const Media&) const = 0;
    virtual bool operator==(const Media&) const = 0;
    virtual bool operator!=(const Media&) const = 0;
    virtual Media & operator=(const Media&) = 0;
    
protected:
    int stock;
    MediaType mediaType;

    // subfunction for operator<<
    virtual void print(ostream & out) const = 0;
};
#include "media_movie.h"
#endif //!_MEDIA_
