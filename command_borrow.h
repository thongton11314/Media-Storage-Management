// add comments here

#ifndef _COMMAND_BORROW_
#define _COMMAND_BORROW_
#include "command.h"

// add comments here
class Borrow : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Borrow&);

public:

    // constructor
    Borrow();

    // deconstructor
    ~Borrow();

    bool setData(ifstream& infile);

    // setter
    void setMedia(Media* media);
    bool setCustomerID(int id);
    void setMediaType(MediaType type);
    void setMovieType(MovieType type);

    // getter
    int getCustomerID() const;
    MediaType getMediaType() const;
    MovieType getMovieType() const;
    const Media & getMedia() const;

    bool processBorrow(Media*, Customer*); // part of process function

private:
    int customerID;
    MediaType mediaType;
    MovieType movieType;
    Media * media;
    virtual ostream& out(ostream &) const override;
};

#endif //!_COMMAND_BORROW_