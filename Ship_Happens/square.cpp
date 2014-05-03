
/************************************************************************************
 * square.cpp																		*
 * Contains the members and member functions of the square class 					*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140424	MP	@all		Created std. get-er and set-er func.
  * 140404	MP	@all		Tested std. func.
  * 140408	MP	@set_ship	a few smal adjustments
  *
  ***********************************************************************************/

# include "square.h"

// Constructor
Square::Square() {
    Square::set = false;
    Square::hit = false;
    Square::disabled = false;
}

// Constructor for specific purposes (testing)
Square::Square(bool _set,bool _hit,bool _disabled) {
    Square::set = _set;
    Square::hit = _hit;
    Square::disabled = _disabled;
}

// Destructor
Square::~Square() {

}

// Set a ship onto a sqare
void Square::set_square() {
    if (Square::legal()) {
        Square::set = true;
    }
    // exeption for repeated try needed
    else if (Square::set == true) {
        std::cout << "this square already is in use!" << std::endl;
    }
    // exeption for disabled square needed
}

// removes set flag from square
void Square::un_set_square() {
    Square::set = false;

}
// checks if square is set
bool Square::get_square_set() {
    return Square::set;
}

// square got hit
void Square::set_hit() {
    if(Square::legal()) {
            Square::hit = true;
    }
}

// removes hit from square
void Square::un_set_hit() {
    Square::hit = false;
}

// checks if square is hit
bool Square::get_square_hit() {
    return Square::hit;
}

// disable square
void Square::set_disabled () {
    Square::disabled = true;
}

// enables square
void Square::un_set_disabled() {
    Square::disabled = false;
}

// checks if square is disabled
bool Square::get_square_disabled() {
    return Square::disabled;
}

// if the square is disabled this func will return false
bool Square::legal() {
    if (Square::disabled) {
        return false;
    }
    return true;
}
