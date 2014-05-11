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
    Battleship::alive = true;
    Battleship::set   = false;
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
