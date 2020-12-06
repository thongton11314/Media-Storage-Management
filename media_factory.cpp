#include "media_factory.h"

//-----------------------------------------------------------------------------
// createDVDMovie
// call MovieFactory to create store new movie type from the file to system
Media * MediaFactory::createDVDMovie(ifstream & infile) {
    return MovieFactory::createMovie(infile);
}
