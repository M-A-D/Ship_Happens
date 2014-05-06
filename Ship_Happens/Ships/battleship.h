/************************************************************************************
 * battleship.h                                                             		*
 * Contains the definition of the class battleship, which is a kind of ship     	*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Definition of the ship sub class battleship
  *
  *
  ***********************************************************************************/

# ifndef BATTLESHIP_H
# define BATTLESHIP_H

# include "my_headers.h"
# include "square.h"
# include "ship.h"

class Battleship : public virtual Ship {
    bool alive;
    bool set;
    static size_t const lenght = 4;
    Square* position[lenght];

public:
    Battleship();
    ~Battleship();
};

#endif // BATTLESHIP_H
