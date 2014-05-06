/************************************************************************************
 * ship.cpp     v0.5																*
 * Contains the members and memberfunctions of the ship class, a superclass that    *
 * also implements a lot of it's subclasses functions e.g. "ship.set_ship()"        *
 *                                                                                  *
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

 # include "ship.h"

/*
 * std constructor
 */
Ship::Ship() {
    Ship::alive = true;
    Ship::set = false;
}

/*
 * destructor
 */
Ship::~Ship() {

}

/*
 * ship.set_ship(sq1,sq2) for a ship of lenght 2, the ship knows the Squares
 * it sits on, a simple way to check a ships status, without using
 * another registry.
 * (submarine)
 */
void Ship::set_ship(Square* _sq1, Square* _sq2) {
    Ship::position[0] = _sq1;
    Ship::position[1] = _sq2;
}

/*
 * ship.set_ship(q1,sq2,sq3) for a ship of lenght 3, in this case the
 * ship gets connected to the Squares it sits on as well and same goes
 * for the following versions of this function
 * (destroyer)
 */
void Ship::set_ship(Square *_sq1, Square *_sq2, Square *_sq3) {
    Ship::position[0] = _sq1;
    Ship::position[1] = _sq2;
    Ship::position[2] = _sq3;
}

/*
 * ship.set_ship(sq1,sq2,sq3,sq4) for a ship of lenght 4
 * (battleship)
 */
void Ship::set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4) {
    Ship::position[0] = _sq1;
    Ship::position[1] = _sq2;
    Ship::position[2] = _sq3;
    Ship::position[3] = _sq4;
}

/*
 * ship.set_ship(sq1,sq2,sq3,sq4,sq5) for a ship of lenght 5
 * (AirCarrier)
 */
void Ship::set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4, Square* _sq5) {
    Ship::position[0] = _sq1;
    Ship::position[1] = _sq2;
    Ship::position[2] = _sq3;
    Ship::position[3] = _sq4;
    Ship::position[4] = _sq5;
}


/*
 * ship.check_ship_stat() uses the Square* array position
 * to chek if a ship is still alive, if the number of hits
 * is equal to the ships lenght the alive flag will be toggled
 * and the player loses his ship
 */
void Ship::check_ship_stat() {
    size_t comp = 0;
    for(size_t count = 0; count < Ship::lenght; count++) {
        if (Ship::position[count]->get_square_hit()) {
            comp++;
        }
        else {
            comp--;
        }
        if (comp == (Ship::lenght)) {
            Ship::alive = false;
        }
    }
}

/*
 * ship.display_ship() is another function for console testing purposes
 * each square of a ship, that has already been hit will be displayed as
 * "X" the unharmed ones as "o"
 */
void Ship::display_ship() {
    for(size_t count = 0; count < (Ship::lenght); count++) {
        if (Ship::position[count]->get_square_hit()) {
            std::cout << "X";
        }
        else {
            std::cout << "o";
        }
        std::cout << std::endl;
    }
}

/* @return: size_t
 * ship.get_lenght() is a simple getter function that returns a ships
 * lenght from it's definition
 */
size_t Ship::get_lenght() {
    return Ship::lenght;
}
