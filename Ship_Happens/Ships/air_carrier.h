/************************************************************************************
 * air_carrier.h																	*
 * Contains the definition of the class air_carrier, which is a kind of ship		*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Definition of the ship sub class air_carrier
  *
  *
  ***********************************************************************************/

# ifndef AIRCARRIER_H
# define AIRCARRIER_H

# include "my_headers.h"
# include "ship.h"

/**
 * @brief The AirCarrier class
 *
 */
class AirCarrier : public virtual Ship {
private:
    bool alive;                     /**< */
    bool set;                       /**< */
    static size_t const type = 3;   /**< */
    static size_t const lenght = 5; /**< */
    Square* position[lenght];       /**< */

public:
    AirCarrier();
    ~AirCarrier();

    size_t get_lenght();
};

# endif // AIRCARRIER_H
