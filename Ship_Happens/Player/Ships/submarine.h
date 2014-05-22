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


/**
 * @brief The Submarine class
 *
 */
class Submarine : public virtual Ship {
private:
    bool alive;
    bool set;
    static size_t const type = 1;
    static size_t const lenght = 2;
    Square *position[lenght];

public:
    Submarine();
    ~Submarine();

    size_t get_lenght();
    bool get_ship_set();
    bool get_ship_alive();
    void display_ship();
    void reset_ship();
    void check_ship_stat();
    void set_ship(Square* _sq1, Square* _sq2);

    // help func for terminal testing purposes
    void print_ship();
};

#endif // SUBMARINE_H
