#include "media_movie_factory.h"

Movie * MovieFactory::createMovie(ifstream & infile) {
    Movie * newMovie = nullptr;
    MovieType movieType;

    // get movie type
    infile >> movieType;

    // if fail to read movie type
    if (infile.fail()) {
        infile.clear();
        infile.ignore(99, '\n');        
		return nullptr;
    }

    // specific type
    switch (movieType) {    
    case COMEDY:
        newMovie = createMovieComedy(infile);
        break;    
    case CLASSIC:
        newMovie = createMovieClassic(infile);
        break;
    case DRAMA:
        newMovie = createMovieDrama(infile);
        break;
    default:
        errorType(movieType, infile);
        break;
    }    
    return newMovie;
}

Movie * MovieFactory::createMovieComedy(ifstream & infile) {
    Movie * comedy = new Comedy();
    if (comedy->setData(infile))
        return comedy;
    delete comedy;
    return nullptr;
}

Movie * MovieFactory::createMovieDrama(ifstream & infile) {
    Movie * drama = new Drama();
    if (drama->setData(infile))
        return drama;
    delete drama;
    return nullptr;
}

Movie * MovieFactory::createMovieClassic(ifstream & infile) {
    Movie * classic = new Classic();
    if (classic->setData(infile))
        return classic;
    delete classic;
    return nullptr;
}

void MovieFactory::errorType(const char& mType, ifstream& infile) {
    string fullInfor;
    getline(infile, fullInfor);
    cerr << "Media, type \'" << mType << "\' is not recognized:"
        << '\n' << "  " << mType << fullInfor << endl;
}
