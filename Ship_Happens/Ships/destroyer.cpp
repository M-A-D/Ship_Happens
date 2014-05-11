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
    Destroyer::alive = true;
    Destroyer::set = false;
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
