/************************************************************************************
 * battleship.h                                                             		*
 * Contains the definition of the class battleship, which is a kind of ship     	*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Definition of the ship sub class battleship
  * 140510  MP  @all    added comments
  *
  ***********************************************************************************/

# ifndef BATTLESHIP_H
# define BATTLESHIP_H

# include "my_headers.h"
# include "ship.h"

/**
 * @brief The Battleship class
 *
 */
class Battleship : public virtual Ship {
private:
    bool alive;                     /**< */
    bool set;                       /**< */
    static size_t const type = 3;   /**< */
    static size_t const lenght = 4; /**< */
    Square* position[lenght];       /**< */

public:
    Battleship();
    ~Battleship();

    size_t get_lenght();
    void reset_ship();
    void display_ship();
    void set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4);
};

#endif // BATTLESHIP_H
