/************************************************************************************
 * player.h v0.3																	*
 * Contains the definition of the player class 										*
 *                                                                                  *
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
# include "Ships/submarine.h"
# include "Ships/destroyer.h"
# include "Ships/battleship.h"
# include "Ships/air_carrier.h"

class Player {
private:
    std::string name;
    bool lost;
    bool ready;
    Board own_field;
    Submarine subm1, subm2, subm3, subm4, subm5;
    Destroyer dest1, dest2, dest3, dest5;
    Battleship bash1, bash2, bash3;
    AirCarrier airc;

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
    void show_field();
    void show_enemy_field(Board& _en_field);
};

# endif // PLAYER_H
