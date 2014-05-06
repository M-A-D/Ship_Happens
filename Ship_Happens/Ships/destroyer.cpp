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

/*
 * std constructor
 */
Destroyer::Destroyer() {
    Destroyer::alive = true;
    Destroyer::set = false;
}

/*
 * destructor
 */
Destroyer::~Destroyer() {

}
