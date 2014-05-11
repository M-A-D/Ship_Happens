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

/**
 * std constructor
 * a ship will be createt, which is still unharmed and not set to a specific position
 * @param Ship::alive = true
 * @param Ship::set = false
 */
Ship::Ship() {
    Ship::alive = true;
    Ship::set = false;
}

/**
 * destructor
 */
Ship::~Ship() {

}

/**
 * Set ship back to normal
 */
void Ship::reset_ship() {
    Ship::alive = true;
    Ship::set = false;

    // delete the saved positions of the ship
    for(size_t count = 0; count <= Ship::lenght; count++){
        Ship::position[count] = NULL;
    }
}

/**
 * place a ship on the board
 * Square pointers are used to tell a ship, where on the board it is located
 * this also helps to keep the the Ship::check_ship_stat() simple, because
 * each ship can check each square it sit's on.
 * @param size_t position
 * @param Square* _sqn
 * @param Ship::position[]
 */
void Ship::set_ship(size_t _position, Square* _sqn) {
    Ship::position[_position] = _sqn;
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

/**
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


/**
 * Checks the status of a ship.
 * ship.check_ship_stat() uses the Square* array position
 * to chek if a ship is still alive, if the number of hits
 * is equal to the ships lenght the alive flag will be toggled
 * and the player loses his ship
 */
void Ship::check_ship_stat() {
    size_t comp = 0;
    for(size_t count = 0; count < Ship::lenght; count++) {
        if (Ship::position[count]->get_square_hit()) {
            comp++; // increase the number of hits
        }
    }

    /**
     * compair the ammount of squares that already got hit with the
     * lenght of the ship, if they are equal the ship has been
     * destroyed, the flag Ship::alive will be set to false
     */
     if (comp == (Ship::lenght)) {
         Ship::alive = false;
     }
}

/**
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

/**
 * Get the lenght of a ship in squares.
 * ship.get_lenght() is a simple getter function that returns a ships
 * lenght from it's definition
 * @see Ship::Ship()
 * @return: size_t Ship::lenght
 */
size_t Ship::get_lenght() {
    return Ship::lenght;
}
