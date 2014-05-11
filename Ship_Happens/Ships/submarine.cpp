/************************************************************************************
 * submarine.cpp     v0.5															*
 * Contains the members and memberfunctions of the submarine class, a subclass of   *
 * the ship class. The main difference between each kind of ship in this game is    *
 * the lenght and a submarine is a ship with 2 squares lenght.                      *
 *                                                                                  *
 *                                                                                  *
 * Matthias Pfitzmayer		140501		madmayer@gmx.net							*
 ************************************************************************************/

/***********************************************************************************
 * Changelog:
 * 140501  MP  @all    Created constructor an destructor
 * 140510  MP  @const  Reworked the constructor now using the ship.reset_ship for
 *                     params and settings
 *
 *
 *
 ***********************************************************************************/

# include "submarine.h"

/**
 * @brief Submarine::Submarine
 * std constructor
 * in this case the constructor calls the ship.reset_ship() member func. to get each
 * ship in a defined state, which is ship.alive = true, ship.set = false and
 * ship.position[0] = NULL till ship.position[ship.lenght] = NULL
 */
Submarine::Submarine() {
    Submarine::reset_ship();
}

/**
 * @brief Submarine::~Submarine
 * destructor
 */
Submarine::~Submarine() {

}

/**
 * @brief Submarine::get_lenght
 *
 * @return size_t Submarine::lenght
 */
size_t Submarine::get_lenght() {
    return Submarine::lenght;
}
