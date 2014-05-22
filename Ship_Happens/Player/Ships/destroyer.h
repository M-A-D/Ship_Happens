/************************************************************************************
 * destroyer.h																		*
 * Contains the definition of the sub class destroyer, which is a kind of ship		*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Definition of the ship subclass Destroyer
  * 140510  MP  @all    added comments
  *
  ***********************************************************************************/

# ifndef DESTROYER_H
# define DESTROYER_H

# include "my_headers.h"
# include "ship.h"


/**
 * @brief The Destroyer class
 */
class Destroyer : public virtual Ship {
private:
    bool alive;                     /**< indicates if the ship already sunk*/
    bool set;                       /**< indicates if the ship has already been placed on the field*/
    static size_t const type = 2;   /**< */
    static size_t const lenght = 3; /**< the lenght of a ship meassured in squares*/
    Square* position[lenght];       /**< an array of pointers to the squares the ship has been placed on*/

public:
    Destroyer();
    ~Destroyer();

    size_t get_lenght();
    bool get_ship_set();
    bool get_ship_alive();
    void display_ship();
    void check_ship_stat();
    void set_ship(Square* _sq1, Square* _sq2, Square* _sq3);
    void reset_ship();

    // help func for terminal testing purposes
    void print_ship();
};

#endif // DESTROYER_H
