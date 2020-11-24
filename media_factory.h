#ifndef _MEDIA_FACTORY_
#define _MEDIA__FACTORY_
#include "media_movie_factory.h"

class MediaFactory {
public:
    static Media * createDVDMovie(ifstream & infile);
    // further media type add here
};

#endif //!_MEDIA_FACTORY_