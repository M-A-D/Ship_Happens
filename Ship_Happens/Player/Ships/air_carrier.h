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
    bool get_ship_set();
    bool get_ship_alive();
    void reset_ship();
    void check_ship_stat();
    void display_ship();
    void set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4, Square* _sq5);

    // help func for terminal testing purposes
    void print_ship();

};

# endif // AIRCARRIER_H
