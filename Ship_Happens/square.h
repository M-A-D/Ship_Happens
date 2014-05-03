/************************************************************************************
 * square.h 																		*
 * Contains the definition of the class square 										*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140404	MP	@all	Definition of the Square class
  *
  *
  ***********************************************************************************/

# ifndef SQUARE_H
# define SQUARE_H

# include "my_headers.h"

class Square{
private:
    bool set;
    bool hit;
    bool disabled;

public:
    Square ();											// std constructor
    Square (bool _set, bool _hit, bool _disabled);		// constructor with params
    ~Square ();											// destructor

    // setting ships
    void set_square ();
    void un_set_square ();
    bool get_square_set ();

    // hitting squares
    void set_hit ();
    void un_set_hit ();
    bool get_square_hit ();

    // disable squares so that they can't be hit or set anymore
    void set_disabled ();
    void un_set_disabled ();
    bool get_square_disabled ();

    bool legal ();
};

# endif // SQUARE_H
