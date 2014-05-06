/************************************************************************************
 * submarine.h																		*
 * Contains the definition of the sub class submarien, which is a kind of ship		*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Definition of the ship subclass submarine
  *
  *
  ***********************************************************************************/

#ifndef SUBMARINE_H
#define SUBMARINE_H

# include "my_headers.h"
# include "ship.h"

class Submarine : public virtual Ship {
private:
    bool alive;
    bool set;
    static size_t const lenght = 2;
    Square *position[lenght];
public:
    Submarine();
    ~Submarine();

};

#endif // SUBMARINE_H
