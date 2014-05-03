/************************************************************************************
 * player.h v0.3																	*
 * Contains the definition of the player class 										*
 * Matthias Pfitzmayer		140415		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140415	MP	@all	Definition of the Board class
  *
  *
  ***********************************************************************************/

# ifndef PLAYER_H
# define PLAYER_H

# include "my_headers.h"
# include "board.h"
# include "submarine.h"


class Player {
private:
    std::string name;
    bool lost;
    bool ready;
    Board own_field;

public:

    Player ();
    Player (std::string _name);
    ~Player ();

    void set_name();
    void set_name(std::string _name);
    std::string get_name();

    bool check_lose();
    void bomb_enemy_field(Board& _en_field, size_t _x, size_t _y);
    void set_ship(size_t len, size_t _x1, size_t _y1, size_t _x2, size_t _y2);

    Board& return_board_ref();

};

# endif // PLAYER_H
