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

class Destroyer : public virtual Ship {
private:
    bool alive;                     /**< */
    bool set;                       /**< */
    static size_t const type = 2;   /**< */
    static size_t const lenght = 3; /**< */
    Square* position[lenght];       /**< */

public:
    Destroyer();
    ~Destroyer();

    size_t get_lenght();
};

#endif // DESTROYER_H
