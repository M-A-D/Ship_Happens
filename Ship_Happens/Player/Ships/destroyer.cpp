/************************************************************************************
 * destroyer.cpp        v0.5    													*
 * The destroyer class is a subclass of ship, with a lenght of 3                    *
 *                                                                                  *
 * Matthias Pfitzmayer		140401		madmayer@gmx.net							*
 ************************************************************************************/

/************************************************************************************
 * Changelog:
 * 140501  MP  @all    Created constructor an destructor
 *
 *
 *
 ************************************************************************************/

#include "destroyer.h"


/**
 * @brief Destroyer::Destroyer
 * std constuctor
 * @param bool Destroyer::alive = true
 * @param bool Destroyer::set = false
 */
Destroyer::Destroyer() {
    Destroyer::reset_ship();
    //Destroyer::alive = true;
    //Destroyer::set = false;
}


/**
 * @brief Destroyer::~Destroyer
 * destructor
 */
Destroyer::~Destroyer() {

}


/**
 * @brief Destroyer::get_lenght
 * @return size_t Destroyer::lenght
 */
size_t Destroyer::get_lenght() {
    return Destroyer::lenght;
}


/**
 * @brief Destroyer::get_ship_set
 * @return Destroyer::set
 */
bool Destroyer::get_ship_set() {
    return Destroyer::set;
}


/**
 * @brief Destroyer::check_ship_stat
 */
void Destroyer::check_ship_stat() {
    size_t comp = 0;
    for(size_t count = 0; count < Destroyer::lenght; count++) {
        if (Destroyer::position[count]->get_square_hit()) {
            comp++; // increase the number of hits
        }
    }

    /**
     * compair the ammount of squares that already got hit with the
     * lenght of the ship, if they are equal the ship has been
     * destroyed, the flag Ship::alive will be set to false
     */
     if (comp == (Destroyer::lenght)) {
         Destroyer::alive = false;
     }
}


/**
 * @brief Destroyer::get_ship_alive
 * @return Destroyer::alive
 */
bool Destroyer::get_ship_alive() {
    return Destroyer::alive;
}


/**
 * @brief Destroyer::set_ship
 * @param _sq1
 * @param _sq2
 * @param _sq3
 */
void Destroyer::set_ship(Square* _sq1, Square* _sq2, Square* _sq3) {
    Destroyer::position[0] = _sq1;
    Destroyer::position[1] = _sq2;
    Destroyer::position[2] = _sq3;
    Destroyer::set = true;
}


/**
 * @brief Destroyer::reset_ship
 */
void Destroyer::reset_ship() {
     Destroyer::alive = true;
     Destroyer::set = false;

     // delete the saved positions of the ship
     for(size_t count = 0; count < Destroyer::lenght; count++){
         Destroyer::position[count] = NULL;
     }
}


/**
 * @brief Destroyer::display_ship
 */
void Destroyer::print_ship() {
    for(size_t count = 0; count < (Destroyer::lenght); count++) {
        if (Destroyer::position[count]->get_square_hit()) {
            std::cout << "X";
        }
        else {
            std::cout << "o";
        }
    }
    std::cout << std::endl;
}
