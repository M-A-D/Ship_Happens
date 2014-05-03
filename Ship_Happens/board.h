/************************************************************************************
 * board.h 	v0.2																	*
 * Contains the definition of the class board 										*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140404	MP	@all	Definition of the Board class
  *
  *
  ***********************************************************************************/

# ifndef BOARD_H
# define BOARD_H

# include "my_headers.h"
# include "square.h"

class Board {
private:
    size_t lenght;
    size_t widht;
    Square field[10][10];

public:
    Board ();
    Board (size_t _x, size_t _y);
    ~Board ();

    void draw_board();
    void show_board();
    void clear_board();
    bool init_board();

    void hit_square(size_t _x, size_t _y);
    void disable_square(size_t _x, size_t _y);

    // differnt functions for different ship_lenghts
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2);
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3);
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3, size_t _x4, size_t _y4);
    void set_ship(size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3, size_t _x4, size_t _y4, size_t _x5, size_t _y5);

};

# endif // BOARD_H
