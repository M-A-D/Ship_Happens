/************************************************************************************
 * board.h 	v0.2																	*
 * Contains the definition of the class board 										*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140404	MP	@all	Definition of the Board class
  * 140501  MP  @get_Square added func.
  *
  ***********************************************************************************/

# ifndef BOARD_H
# define BOARD_H

# include "my_headers.h"
# include "square.h"

/**
 * @brief The Board class
 * a Board consists of a two dimensional array of Squares, the Squares will be adressed
 * using two parameters x for the horizontal (lines) and y for the vertical (collumn) axis
 * the board starts with Sq_1(1,1) in the top left corner and ends with the
 * Sq_n(lenght, widht) in the bottom right corner. That means a board consists of x * y
 * Squares that represent all the possible points to set a players ships on or the
 * points of the enemies board that one could bomb.
 */
class Board {
private:
    size_t lenght;          /**< */
    size_t widht;           /**< */
    Square field[10][10];   /**< */

public:
    Board ();
    Board (size_t _x, size_t _y);
    ~Board ();

    void clear_board();
    bool init_board();

    bool hit_square(size_t _x, size_t _y);
    void disable_square(size_t _x, size_t _y);
    Square* get_Square_ptr(size_t _x, size_t _y);

    // differnt functions for different ship_lenghts
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2);
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3);
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                  size_t _x4, size_t _y4);
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                  size_t _x4, size_t _y4, size_t _x5, size_t _y5);

    // help and test functions for console debugging
    void draw_board();
    void show_board();
};

# endif // BOARD_H
