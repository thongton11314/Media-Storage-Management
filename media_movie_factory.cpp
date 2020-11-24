#include "media_movie_factory.h"

Movie * MovieFactory::createMovie(ifstream & infile) {
    Movie * newMovie = nullptr;
    char movieType;

    // get movie type
    infile >> movieType;

    // if fail to read movie type
    if (infile.fail()) {
        infile.clear();
        infile.ignore(99, '\n');        
		return nullptr;
    }
    switch (movieType) {    
    case 'F':
        newMovie = createMovieComedy(infile);
        break;
    case 'D':
       newMovie = createMovieDrama(infile);
        break;    
    case 'C':
        newMovie = createMovieClassic(infile);
        break;
    default:
        string fullInfor;
        getline(infile, fullInfor);
        cerr << "Type \"" << movieType << "\" is not recognized: "
            << movieType << fullInfor << endl;     
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