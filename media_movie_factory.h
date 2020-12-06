#ifndef _MEDIA_MOVIE_FACTORY_
#define _MEDIA_MOVIE_FACTORY_
#include "media_movie.h"
#include "media_movie_comedy.h"
#include "media_movie_drama.h"
#include "media_movie_classic.h"

// Class MovieFactory:
//  Description:
//   - This class create a new movie from the file
//  Implementation:
//   - Create Movie:
//     - create new movie for Comedy, Drama, and Classic
class MovieFactory {
public:
    //Read the file and check which movie it is
    static Movie * createMovie(ifstream & infile);
private:
    
    //If type is F, create a new comedy movie
    static Movie * createMovieComedy(ifstream & infile);
    
    //If type is D, create a new drama movie
    static Movie * createMovieDrama(ifstream & infile);
    
    //If type is C, create a new classic movie
    static Movie * createMovieClassic(ifstream & infile);
    
    //Check for any movie type that is not in the system
    static void errorType(const char& cType, ifstream& infile);
};
#endif //!_MEDIA_MOVIE_FACTORY_