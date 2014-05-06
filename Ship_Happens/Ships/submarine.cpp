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
 *
 *
 *
 ***********************************************************************************/

# include "submarine.h"

/*
 * std constructor
 */
Submarine::Submarine() {
    Submarine::alive = true;
    Submarine::set   = false;
}

/*
 * destructor
 */
Submarine::~Submarine() {

}
