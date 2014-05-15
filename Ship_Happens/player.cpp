/************************************************************************************
 * player.cpp	v0.3																*
 * Contains the definition of the member and member functions of the player class.	*
 * A Player should be able to set and change his name, set ships and bomb the 		*
 * enemies field 																	*
 * A Player should know if he stil has ships left, where to find his board and how	*
 * to bomb his oponents field.														*
 * Matthias Pfitzmayer		140415		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140415	MP	@all	Definition of the Player class
  * 140416	MP	@all	Implementing Memberfunc of th Player class
  *
  ***********************************************************************************/

 /***********************************************************************************
  * to do:
  * [1]	MP	implement the player.set_ship(_len, _x1, _y1, _x2, _y2)
  *
  *
  ***********************************************************************************/

# include "my_headers.h"
# include "player.h"

/**
 * @brief Player::Player
 * std constructor
 * @param Player::name
 * @param Player::lost = false
 * @param Player::ready = false
 * @param Player::own_field
 */
Player::Player() {
    Player::name = "Spieler_1";
    Player::lost = false;
    Player::ready = false;
    Player::own_field.clear_board();
}

/**
 * @brief Player::Player
 * special constructor using a given name
 * @param std::string _name
 */
Player::Player(std::string _name) {
    Player::name = _name;
    Player::lost = false;
    Player::ready = false;
}

/**
 * @brief Player::~Player
 * destructor
 */
Player::~Player() {

}

/**
 * @brief Player::set_name
 * @param std::string _name
 */
void Player::set_name(std::string _name) {
    Player::name = _name;
}

/**
 * @brief Player::check_lose
 * @return bool Player::lost;
 */
bool Player::check_lose() {
    return Player::lost;
}

/**
 * @brief Player::get_name
 * a member function that returns the players name
 * @return std::string Player::name
 */
std::string Player::get_name() {
    return Player::name;
}

/*

 */
/**
 * @brief Player::bomb_enemy_field
 * enables the player to bomb the enemies field directly using the koordinates x and y
 * @param _en_field
 * @param _x
 * @param _y
 */
void Player::bomb_enemy_field(Board& _en_field, size_t _x, size_t _y) {
    _en_field.hit_square(_x, _y);
}



/**
 * Get a reference of a players board.
 * To avoid copying the whole Board into the enemies data, and to enable direct "bombing" of the enemies
 * filed we return a reference to the board
 * @return Board& _field
 */
Board& Player::return_board_ref() {
    Board& _field = Player::own_field;
    return _field;
}


// help functions for console debugging purposes
/**
 * @brief Player::show_field
 * print the players field on the terminal
 */
void Player::show_field() {
    Player::own_field.draw_board();
}

/**
 * @brief Player::show_enemy_field
 * print the enemies field in the terminal
 * @param _en_field
 */
void Player::show_enemy_field(Board &_en_field) {
    _en_field.show_board();
}

/**
 * @brief Player::show_ships
 * prints a players ships in the terminal, 'o' means this part of a ship has not
 * been hit so far 'X' signals that this part is already destroyed
 */
void Player::show_ships() {
    for(size_t count = 0; count < Player::num_subm; count++) {
        std::cout << count + 1 << "  ";
        Player::subm[count].display_ship();
    }

    for(size_t count = 0; count < Player::num_dest; count++) {
        std::cout << count +1 << "  ";
        Player::dest[count].display_ship();
    }

    for(size_t count = 0; count < Player::num_bash; count++) {
        std::cout << count + 1 << "  ";
        Player::bash[count].display_ship();
    }

    for(size_t count = 0; count < Player::num_airc; count++) {
        std::cout << count + 1 << "  ";
       Player::airc[count].display_ship();
    }
}

/**
 * @brief Player::get_ship_ptr
 * returns the adress of a single ship
 * @param _type
 * @param _num
 * @return *_ship
 */
Ship* Player::get_ship_ptr(size_t _type, size_t _num) {
    Ship* _ship;
    switch(_type) {
    case 1:
        _ship = &(Player::subm[_num]);
        break;

    case 2:
        _ship = &(Player::dest[_num]);
        break;

    case 3:
        _ship = &(Player::bash[_num]);
        break;

    case 4:
        _ship = &(Player::airc[_num]);
        break;

    default:
        std::cout << _type << " is not a valid ship_type" << std::endl;
    }
    return _ship;
}

/**
 * @brief Player::place_ship
 * this function may be used for all kind of ships, thats why x3 to x5 and y3 to y5 are
 * pinned to zero, because a ship needs at least two Squares of space (Submarine),
 * for each Square more another kind of ship needs to be set. Later if we work with
 * a graphic surface we will be able to replace this func. with a version working directly
 * with Squares, instead of coordinates.
 * @param _type
 * @param _num
 * @param _x1
 * @param _y1
 * @param _x2
 * @param _y2
 * @param _x3
 * @param _y3
 * @param _x4
 * @param _y4
 * @param _x5
 * @param _y5
 * @return
 */
bool Player::place_ship(size_t _type, size_t _num, size_t _x1, size_t _y1, size_t _x2, size_t _y2,
                   size_t _x3, size_t _y3, size_t _x4, size_t _y4, size_t _x5, size_t _y5) {
    bool _set = false;
    Square* _sq1 = Player::own_field.get_Square_ptr(_x1, _y1);
    Square* _sq2 = Player::own_field.get_Square_ptr(_x2, _y2);
    Square* _sq3 = Player::own_field.get_Square_ptr(_x3, _y3);
    Square* _sq4 = Player::own_field.get_Square_ptr(_x4, _y4);
    Square* _sq5 = Player::own_field.get_Square_ptr(_x5, _y5);

    switch (_type) {

    // type 1 = submarine -> lenght = 2
    case 1:
        if(Player::own_field.get_square_empty(_sq1, _sq2)) {
            Player::own_field.set_ship(_x1, _y1, _x2, _y2);
            Player::subm[_num - 1].set_ship(Player::own_field.get_Square_ptr(_x1, _y1),
                                            Player::own_field.get_Square_ptr(_x2, _y2));

        }

        break;

    // type 2 = destroyer -> lenght = 3
    case 2:
        if(Player::own_field.get_square_empty(_sq1, _sq2, _sq3)) {
            Player::dest[_num - 1].set_ship(Player::own_field.get_Square_ptr(_x1, _y1),
                                            Player::own_field.get_Square_ptr(_x2, _y2),
                                            Player::own_field.get_Square_ptr(_x3, _y3));
            Player::own_field.set_ship(_x1, _y1, _x2, _y2, _x3, _y3);
        }

        break;

     // type 3 = battleship -> lenght = 4
     case 3:
        if(Player::own_field.get_square_empty(_sq1, _sq2, _sq3, _sq4)) {
            Player::bash[_num -1].set_ship(Player::own_field.get_Square_ptr(_x1, _y1),
                                           Player::own_field.get_Square_ptr(_x2, _y2),
                                           Player::own_field.get_Square_ptr(_x3, _y3),
                                           Player::own_field.get_Square_ptr(_x4, _y4));
            Player::own_field.set_ship(_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4);
        }

        break;

    // type 4 = air carrier -> lenght = 5
    case 4:
        if(Player::own_field.get_square_empty(_sq1, _sq2, _sq3, _sq4, _sq5)) {
            Player::airc[_num - 1].set_ship(Player::own_field.get_Square_ptr(_x1, _y1),
                                            Player::own_field.get_Square_ptr(_x2, _y2),
                                            Player::own_field.get_Square_ptr(_x3, _y3),
                                            Player::own_field.get_Square_ptr(_x4, _y4),
                                            Player::own_field.get_Square_ptr(_x5, _y5));
            Player::own_field.set_ship(_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4, _x5, _y5);
        }

        break;
    // default for wrong ship type
    default:
        std::cout << _num << " is not a ship type" << std::endl;
    }
    return _set;
}

/**
 * @brief Player::get_Submarine_ref
 * Returns a reference to a Submarine from the players submarine array Player::subm[_num - 1]
 * @param _num
 * @return Submarine& _subm
 */
Submarine& Player::get_Submarine_ref(size_t _num) {
    Submarine& _subm = Player::subm[_num - 1];
    return _subm;
}

/**
 * @brief Player::get_Destroyer_ref
 * Returns a reference to a destroyer from the players destroyer array Player::dest[_num - 1];
 * @param _num
 * @return Destroyer& _dest
 */
Destroyer& Player::get_Destroyer_ref(size_t _num) {
    Destroyer& _dest = Player::dest[_num - 1];
    return _dest;
}

/**
 * @brief Player::get_BattleShip_ref
 * Returns a reference to a battleship from the players battleship array Player::bash[_num - 1]
 * @param _num
 * @return Battleship& _bash
 */
Battleship& Player::get_BattleShip_ref(size_t _num) {
    Battleship& _bash = Player::bash[_num - 1];
    return _bash;
}

/**
 * @brief Player::get_AirCarrier_ref
 * Returns a reference to the players air carrier from the air carrier array Player::airc[_num - 1]
 * this function should be quiet valueable for the following game class
 * @param _num
 * @return AirCarrier& _airc
 */
AirCarrier& Player::get_AirCarrier_ref(size_t _num) {
    AirCarrier& _airc = Player::airc[_num - 1];
    return _airc;
}
