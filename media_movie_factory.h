#ifndef _MEDIA_MOVIE_FACTORY_
#define _MEDIA_MOVIE_FACTORY_
#include "media_movie.h"
#include "media_movie_comedy.h"
#include "media_movie_drama.h"
#include "media_movie_classic.h"

class MovieFactory {
public:
    static Movie * createMovie(ifstream & infile);
private:
    static Movie * createMovieComedy(ifstream & infile);
    static Movie * createMovieDrama(ifstream & infile);
    static Movie * createMovieClassic(ifstream & infile);
    static void errorType(const char& cType, ifstream& infile);
};

#endif //!_MEDIA_MOVIE_FACTORY_