/************************************************************************************
 * board.cpp 	v0.2																*
 * Contains the definition of the members and member functions of the Board class. 	*
 * A board consists of a definit number of Squares organized in a field of 			*
 * [x] * [y] tiles. Each of this squares can be manipulated with the Square member 	*
 * function.																		*
 *                                                                                  *
 *    A   B   C   D   E   F   G   H   I   K     <- _x                               *
 *   -----------------------------------------                                      *
 *  1|a1 |b1 |c1 |d1 |e1 |f1 |g1 |h1 |i1 |k1 |       std board                      *
 *   -----------------------------------------                                      *
 *  2|a2 |b2 |c2 |d2 |e2 |f2 |g2 |h2 |i2 |k2 |                                      *
 *   -----------------------------------------                                      *
 *  3|a3 |b3 |c3 |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 *  4|a4 |b4 |c4 |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 *  5|a5 |b5 |   |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 *  6|   |   |   |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 *  7|   |   |   |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 *  8|   |   |   |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 *  9|   |   |   |   |   |   |   |   |   |   |                                      *
 *   -----------------------------------------                                      *
 * 10|   |   |   |   |   |   |   |   |   |   | <- _x = 10 field[9][widht]           *
 *   -----------------------------------------                                      *
 *  ^                                      ^ _y = 10 field[lenght][9]               *
 *  _y                                                                              *
 *                                                                                  *
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140404	MP	@all	Created std. logic and func.
  * 140501  MP  @draw_board     changed notation
  * 140501  MP  @clear_board    changed notation
  * 140501  MP  @
  *
  ***********************************************************************************/

  /**********************************************************************************
   * to do:
   * [1]	MP 		Initialize the board with variable lenght and widht
   *
   *
   **********************************************************************************/

# include "my_headers.h"
# include "board.h"

/**
 * std constructor
 * @param Board::lenght =  10
 * @param Board::widht = 10
 */
Board::Board() {
    Board::lenght = 10;
    Board::widht = 10;
}

/**
 * special constructor for a costumized board not ready yet [1]
 * @param size_t _x
 * @param size_t _y
 * @param Board::lenght = _x
 * @param Board::lenght = _y
 */
Board::Board(size_t _x, size_t _y) {
    Board::lenght = _x;
    Board::widht = _y;
}

/**
 * destructor
 */
Board::~Board() {

}


/**
 * board.clear_board() removes all the flags that were previously set
 * in the squares (e.g. "hit", "set", "disabled")
 */
void Board::clear_board() {
    for(size_t line = 0; line < Board::widht; line++) {
        for(size_t column = 0; column < Board::lenght; column++) {
            Board::field [line][column].un_set_square();
            Board::field [line][column].un_set_hit();

        }
    }
}

/**
 * board.init_board() is a posibillity to add flags to costumize the field
 * (e.g. switch case to decide, where the islands will be set)
 */
bool Board::init_board() {
    bool done = true;

    return done;
}


/**
 * Disable a single square.
 * board.disable_square() help function for testing purposes,
 * disables a single square
 *
 * @param size_t _x
 * @param size_t _y
 */
void Board::disable_square(size_t _x, size_t _y) {
    _x = _x-1;
    _y = _y-1;
    Board::field[_x][_y].set_disabled();
}

/**
 * @brief Board::get_square_empty
 * @param _sq1
 * @param _sq2
 * @param _sq3
 * @param _sq4
 * @param _sq5
 * @return bool empty
 */
bool Board::get_square_empty(Square *_sq1, Square *_sq2, Square *_sq3, Square *_sq4, Square *_sq5) {
    bool empty, em3, em4, em5;

    empty = (!(_sq1->get_square_set()) & !(_sq2->get_square_set()));

    /**
     * If a third Square is needed, check if it is empty as well,
     */
    if(_sq3 != NULL) {
        em3 = !(_sq3->get_square_set());
        empty = (empty & em3);
    }

    /**
     * same goes for the fourth Square
     */
    if(_sq4 != NULL) {
        em4 = !(_sq4->get_square_set());
        empty = (empty & em4);
    }

    /**
     * and the fifth.
     */
    if(_sq5 != NULL) {
        em5 = !(_sq5->get_square_set());
        empty = (empty & em5);
    }
    return empty;
}

/**
 * @brief Board::set_ship
 * @param _sq1
 * @param _sq2
 */
void Board::set_ship(Square* _sq1, Square* _sq2) {
    _sq1->set_square();
    _sq2->set_square();
}

/**
 * @brief Board::set_ship
 * @param _sq1
 * @param _sq2
 * @param _sq3
 */
void Board::set_ship(Square* _sq1, Square* _sq2, Square* _sq3) {
    _sq1->set_square();
    _sq2->set_square();
    _sq3->set_square();
}

/**
 * @brief Board::set_ship
 * @param _sq1
 * @param _sq2
 * @param _sq3
 * @param _sq4
 */
void Board::set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4) {
    _sq1->set_square();
    _sq2->set_square();
    _sq3->set_square();
    _sq4->set_square();
}

/**
 * @brief Board::set_ship
 * @param _sq1
 * @param _sq2
 * @param _sq3
 * @param _sq4
 * @param _sq5
 */
void Board::set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4, Square* _sq5) {
    _sq1->set_square();
    _sq2->set_square();

    if(_sq3 != NULL) {
        _sq3->set_square();
    }

    if(_sq4 != NULL) {
        _sq4->set_square();
    }

    if(_sq5 != NULL) {
        _sq5->set_square();
    }
}


/**
 * @brief Board::hit_square
 * @param _sq
 * @return
 */
bool Board::hit_square(Square* _sq) {
   // if the square is disabled one should not be able to hit it
   if(_sq->get_square_disabled()) {
       std::cout << "This field is disabled!" << std::endl;
       return false;
   }
   // square already hit, exception needed
   else if(_sq->get_square_hit()) {
       std::cout << "You already bombed this sector!" << std::endl;
       return false;
   }
   // toggle square.hit flag
   else {
       _sq->set_hit();
       return true;
   }
}


/*
 * Help functions for console debugging
 */


/**
 * board.draw_board() is a help function for console testing purposes
 * it displays each set field with a 'X' and each free field with 'O'
 */
void Board::print_own_board() {
    std::cout << "this is the your board:\n" << " A B C D E F G H I K" << std::endl;
    for(size_t line = 0; line < Board::widht; line++) {
        for(size_t column = 0; column< Board::lenght; column++) {
            if(Board::field [column][line].get_square_set()) {
                std::cout << "|X";
            }

            else
                std:: cout << "| ";
        }
        std::cout << "| " << line+1 << "\n";	// print line numbers
    }
    std::cout << std::endl;
}


/**
 * board.show_board() is a help function for console testing purposes
 * it shows each hit field with a 'X' and those who are not with an 'O'
 */
void Board::print_enemy_board() {
    std::cout << "this is the enemies board:\n" << " A B C D E F G H I K" << std::endl;
    for(size_t line = 0; line < Board::widht; line++) {
        for(size_t column = 0; column< Board::lenght; column++) {
            if((Board::field [column][line].get_square_hit()) &
               (Board::field [column][line].get_square_set())) {
                std::cout << "|X";
            }

            else if(Board::field[column][line].get_square_hit()) {
                std::cout << "|o";
            }
            else
                std:: cout << "| ";
        }
        std::cout << "| " << line+1 << "\n";	// print line numbers
    }
    std::cout << std::endl;
}


/**
 * Get the adress of a specific Square in the Board.
 * in this Board member func. the x and y parameter are used to get the
 * adress of a single field starting with Sq(1,1) in the top left corner.
 *
 * @param size_t _x
 * @param size_t _y
 * @return Square* Board::field[_x][_y]
 */
Square* Board::get_Square_ptr(size_t _x, size_t _y) {
    return &(Board::field[_x-1][_y-1]);
}


/**
 * set a square hit.
 * board.hit_square() enables you to bomb a single square using the
 * boards x and y parameter, if the hit flag could be toggled to
 * true the func. will return true as well.
 *
 * @param size_t _x
 * @param size_t _y
 */
bool Board::hit_square(size_t _x, size_t _y) {
    // if the square is disabled one should not be able to hit it
    if(Board::field[_x-1][_y-1].get_square_disabled()) {
        std::cout << "This field is disabled!" << std::endl;
        return false;
    }

    // square already hit, exception needed
    else if(Board::field[_x-1][_y-1].get_square_hit()) {
        std::cout << "You already bombed this sector!" << std::endl;
        return false;
    }

    // toggle square.hit flag
    else {
        Board::field[_x-1][_y-1].set_hit();
        return true;
    }
}


/**
 * board.set_ship(x1,y1,x2,y2) to set a ship of lenght 2
 * @param size_t _x1
 * @param size_t _y1
 * @param size_t _x2
 * @param size_t _y2
 */
 void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2) {
     Board::field[_x1-1][_y1-1].set_square();
     Board::field[_x2-1][_y2-1].set_square();
}


/**
 * board.set_ship(x1,y1,x2,y2,x3,y3) to set a ship of lenght 3
 * @param size_t _x1
 * @param size_t _y1
 * @param size_t _x2
 * @param size_t _y2
 * @param size_t _x3
 * @param size_t _y3
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3) {
     Board::field[_x1-1][_y1-1].set_square();
     Board::field[_x2-1][_y2-1].set_square();
     Board::field[_x3-1][_y3-1].set_square();
}


/**
 * board.set_ship(x1,y1,x2,y2,x3,y3,x4,y4) to set a ship of lenght 4
 * @param size_t _x1
 * @param size_t _y1
 * @param size_t _x2
 * @param size_t _y2
 * @param size_t _x3
 * @param size_t _y3
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                      size_t _x4, size_t _y4) {
     Board::field[_x1-1][_y1-1].set_square();
     Board::field[_x2-1][_y2-1].set_square();
     Board::field[_x3-1][_y3-1].set_square();
     Board::field[_x4-1][_y4-1].set_square();
}


/**
 * board.set_ship(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5) to set a ship of lenght 5
 * @param size_t _x1
 * @param size_t _y1
 * @param size_t _x2
 * @param size_t _y2
 * @param size_t _x3
 * @param size_t _y3
 * @param size_t _x4
 * @param size_t _y4
 * @param size_t _x5
 * @param size_t _y5
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                       size_t _x4, size_t _y4, size_t _x5, size_t _y5) {
     Board::field[_x1-1][_y1-1].set_square();
     Board::field[_x2-1][_y2-1].set_square();
     Board::field[_x3-1][_y3-1].set_square();
     Board::field[_x4-1][_y4-1].set_square();
     Board::field[_x5-1][_y5-1].set_square();
}
