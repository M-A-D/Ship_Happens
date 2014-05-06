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

/*
 * std constructor
 */
Battleship::Battleship() {
    Battleship::alive = true;
    Battleship::set   = false;
}

/*
 * destructor
 */
Battleship::~Battleship() {

}
