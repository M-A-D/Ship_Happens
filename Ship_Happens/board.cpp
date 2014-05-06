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

/*
 * std constructor
 */
Board::Board() {
    Board::lenght = 10;
    Board::widht = 10;
    //Board::field[Board::lenght][Board::widht];
}

/*
 * special constructor for a costumized board not ready yet [1]
 */
Board::Board(size_t _x, size_t _y) {
    Board::lenght = _x;
    Board::widht = _y;
    //Board::field[length][widht];
}

/*
 * destructor
 */
Board::~Board() {

}

/*
 * board.draw_board() is a help function for console testing purposes
 * it displays each set field with a 'X' and each free field with 'O'
 */
void Board::draw_board() {
    std::cout << "this is the your board:\n" << "A B C D E F G H I K" << std::endl;
    for(size_t line = 0; line < Board::widht; line++) {
        for(size_t column = 0; column< Board::lenght; column++) {
            if(Board::field [line][column].get_square_set()) {
                std::cout << "X ";
            }

            else
                std:: cout << "O ";
        }
        std::cout << " " << line+1 << "\n";	// print line numbers
    }
    std::cout << std::endl;
}

/*
 * board.show_board() is a help function for console testing purposes
 * it shows each hit field with a 'X' and those who are not with an 'O'
 */
void Board::show_board() {
    std::cout << "this is the enemies board:\n" << "A B C D E F G H I K" << std::endl;
    for(size_t line = 0; line < Board::widht; line++) {
        for(size_t column = 0; column< Board::lenght; column++) {
            if(Board::field [line][column].get_square_hit()) {
                std::cout << "X ";
            }

            else
                std:: cout << "O ";
        }
        std::cout << " " << line+1 << "\n";	// print line numbers
    }
    std::cout << std::endl;
}

/*
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

/*
 * boar.init_board() is a posibillity to add flags to costumize the field
 * (e.g. switch case to decide, where the islands will be set)
 */
bool Board::init_board() {
    bool done = true;

    return done;
}

/*
 * board.set_ship(x1,y1,x2,y2) to set a ship of lenght 2
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2) {
    Board::field[_x1-1][_y1-1].set_square();
    Board::field[_x2-1][_y2-1].set_square();
}

/*
 * board.set_ship(x1,y1,x2,y2,x3,y3) to set a ship of lenght 3
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3) {
    Board::field[_x1-1][_y1-1].set_square();
    Board::field[_x2-1][_y2-1].set_square();
    Board::field[_x3-1][_y3-1].set_square();
}

/*
 * board.set_ship(x1,y1,x2,y2,x3,y3,x4,y4) to set a ship of lenght 4
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3, size_t _x4, size_t _y4) {
    Board::field[_x1-1][_y1-1].set_square();
    Board::field[_x2-1][_y2-1].set_square();
    Board::field[_x3-1][_y3-1].set_square();
    Board::field[_x4-1][_y4-1].set_square();
}

/*
 * board.set_ship(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5) to set a ship of lenght 5
 */
void Board::set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3, size_t _x4, size_t _y4, size_t _x5, size_t _y5) {
    Board::field[_x1-1][_y1-1].set_square();
    Board::field[_x2-1][_y2-1].set_square();
    Board::field[_x3-1][_y3-1].set_square();
    Board::field[_x4-1][_y4-1].set_square();
    Board::field[_x5-1][_y5-1].set_square();
}

/*
 * board.hit_square() enables you to bomb a single square
 */
void Board::hit_square(size_t _x, size_t _y) {
    // if the square is disabled one should not be able to hit it
    if(!Board::field[_x][_y].get_square_disabled()) {
        std::cout << "This field is disabled!" << std::endl;
    }

    // square already hit, exception needed
    else if(Board::field[_x][_y].get_square_hit()) {
        std::cout << "You already bombed this sector!" << std::endl;
    }
    // square
    else {
        Board::field[_x][_y].set_hit();
    }
}

/*
 * board.disable_square() help function for testing purposes,
 * disables a single square
 */
void Board::disable_square(size_t _x, size_t _y) {
    Board::field[_x][_y].set_disabled();
}

