#include "media_factory.h"

Media * MediaFactory::createDVDMovie(ifstream & infile) {
    return MovieFactory::createMovie(infile);
}