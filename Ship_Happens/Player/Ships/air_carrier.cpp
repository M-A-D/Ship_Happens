/************************************************************************************
 * battleship.cpp       v0.5														*
 * the battleship class is the subclass of ship, it is the largest of the 4 with    *
 * a lenght of 5.                                                                   *
 *                                                                                  *
 * Matthias Pfitzmayer		140401		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Created constructor an destructor
  *
  *
  *
  ***********************************************************************************/

# include "air_carrier.h"


/**
 * @brief AirCarrier::AirCarrier
 * std constructor
 * @param bool AirCarrier::alive = true
 * @param bool AirCarrier::set = false
 */
AirCarrier::AirCarrier() {
    AirCarrier::reset_ship();
}


/**
 * @brief AirCarrier::~AirCarrier()
 * destructor
 */
AirCarrier::~AirCarrier() {

}


/**
 * @brief AirCarrier::get_lenght
 * @return size_t AirCarrier::lenght
 */
size_t AirCarrier::get_lenght() {
    return AirCarrier::lenght;
}


/**
 * @brief AirCarrier::get_ship_set
 * @return AirCarrier::set
 */
bool AirCarrier::get_ship_set() {
    return AirCarrier::set;
}



void AirCarrier::check_ship_stat() {
    size_t comp = 0;
    for(size_t count = 0; count < AirCarrier::lenght; count++) {
        if (AirCarrier::position[count]->get_square_hit()) {
            comp++; // increase the number of hits
        }
    }

    /**
     * compair the ammount of squares that already got hit with the
     * lenght of the ship, if they are equal the ship has been
     * destroyed, the flag Ship::alive will be set to false
     */
     if (comp == (AirCarrier::lenght)) {
         AirCarrier::alive = false;
     }
}


/**
 * @brief AirCarrier::get_ship_alive
 * @return AirCarrier::alive
 */
bool AirCarrier::get_ship_alive() {
    return AirCarrier::alive;
}


/**
 * @brief AirCarrier::reset_ship
 */
void AirCarrier::reset_ship() {
    AirCarrier::alive = true;
    AirCarrier::set = false;

    // delete the saved positions of the ship
    for(size_t count = 0; count < AirCarrier::lenght; count++){
        AirCarrier::position[count] = NULL;
    }
}


/**
 * @brief AirCarrier::set_ship
 * @param _sq1
 * @param _sq2
 * @param _sq3
 * @param _sq4
 * @param _sq5
 */
void AirCarrier::set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4, Square* _sq5) {
  AirCarrier::position[0] = _sq1;
  AirCarrier::position[1] = _sq2;
  AirCarrier::position[2] = _sq3;
  AirCarrier::position[3] = _sq4;
  AirCarrier::position[4] = _sq5;
  AirCarrier::set = true;
}


/**
 * @brief AirCarrier::print_ship
 * help function for terminal debuging prints the ship in the terminal, using 'X' for destroyed
 * parts and 'o' for the oters, each char represents a square the ship is placed on.
 */
void AirCarrier::print_ship() {
    if(AirCarrier::set) {
        for(size_t count = 0; count < (AirCarrier::lenght); count++) {
            if (AirCarrier::position[count]->get_square_hit()) {
                std::cout << "X";
            }
            else {
                std::cout << "o";
            }
        }
        std::cout << std::endl;
    }
}
