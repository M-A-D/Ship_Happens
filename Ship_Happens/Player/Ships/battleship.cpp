/************************************************************************************
 * battleship.cpp       v0.5														*
 * the battleship class, a subclass of ship with a lenght of 4 squares.             *                                                            *
 *                                                                                  *
 * Matthias Pfitzmayer		140401		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Created std. logic and func.
  *
  *
  *
  ***********************************************************************************/

# include "battleship.h"

/**
 * @brief Battleship::Battleship
 * std constructor
 * @param bool Battleship::alive = true
 * @param bool Battleship::set = false
 */
Battleship::Battleship() {
    Battleship::reset_ship();
}


/**
 * @brief Battleship::~Battleship
 * destructor
 */
Battleship::~Battleship() {

}


/**
 * @brief Battleship::get_lenght
 * @return size_t Battleship::lenght
 */
size_t Battleship::get_lenght() {
    return Battleship::lenght;
}


/**
 * @brief Battleship::get_ship_set
 * @return
 */
bool Battleship::get_ship_set() {
    return Battleship::set;
}


/**
 * @brief Battleship::get_ship_alive
 * @return Battleship::alive
 */
bool Battleship::get_ship_alive() {
    return Battleship::alive;
}



void Battleship::check_ship_stat() {
    size_t comp = 0;
    for(size_t count = 0; count < Battleship::lenght; count++) {
        if (Battleship::position[count]->get_square_hit()) {
            comp++; // increase the number of hits
        }
    }

    /**
     * compair the ammount of squares that already got hit with the
     * lenght of the ship, if they are equal the ship has been
     * destroyed, the flag Ship::alive will be set to false
     */
     if (comp == (Battleship::lenght)) {
         Battleship::alive = false;
     }
}


/**
 * @brief Battleship::reset_ship
 */
void Battleship::reset_ship() {
    Battleship::alive = true;
    Battleship::set = false;

    // delete the saved positions of the ship
    for(size_t count = 0; count < Battleship::lenght; count++){
        Battleship::position[count] = NULL;
    }
}


/**
 * @brief Battleship::set_ship
 * @param _sq1
 * @param _sq2
 * @param _sq3
 * @param _sq4
 */
void  Battleship::set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4) {
  Battleship::position[0] = _sq1;
  Battleship::position[1] = _sq2;
  Battleship::position[2] = _sq3;
  Battleship::position[3] = _sq4;
  Battleship::set = true;
}


/**
 * @brief Battleship::print_ship
 */
void Battleship::print_ship() {
    if(Battleship::set) {
        for(size_t count = 0; count < (Battleship::lenght); count++) {
            if (Battleship::position[count]->get_square_hit()) {
                std::cout << "X";
            }
            else {
                std::cout << "o";
            }
        }
        std::cout << std::endl;
    }
}
