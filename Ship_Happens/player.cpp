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
 * player.set_ship enables a player to place a shipt on the field by soely using
 * two x and y coordinates and a the lenght right now it is used with a fix lenght
 * param, later the lenght flag should be set by the ship used by the player
 */
//void Player::set_ship(Ship& _ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2) {
//    Player::own_field.set_ship(_x1, _y1, _x2, _y2);
//    _ship.set_ship(Player::own_field.get_Square(_x1, _y1), Player::own_field.get_Square(_x2, _y2));
//}

/**
 * @brief Player::set_ship
 * @param _ship
 * @param _x1
 * @param _y1
 * @param _x2
 * @param _y2
 */
void Player::set_ship(Ship* _ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2) {

    /**
     * Toggle the set flags of two of the Boards Squares, by using their _x and _y coordinates
     */
    Player::own_field.set_ship(_x1, _y1, _x2, _y2);
    _ship->set_ship(Player::own_field.get_Square_ptr(_x1, _y1), Player::own_field.get_Square_ptr(_x2, _y2));
}

/**
 *
 *
 * @param Ship *_ship
 * @param size_t _x1
 * @param size_t _y1
 * @param size_t _x2
 * @param size_t _y2
 * @param size_t _x3
 * @param size_t _y3
 */
void Player::set_ship(Ship *_ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3) {

    /**
     * Toggle the set flags of three of the Boards Squares, by using their _x and _y coordinates
     */
    Player::own_field.set_ship(_x1, _y1, _x2, _y2, _x3, _y3);
    _ship->set_ship(Player::own_field.get_Square_ptr(_x1, _y1), Player::own_field.get_Square_ptr(_x2,_y2),
                    Player::own_field.get_Square_ptr(_x3, _y3));
}

/**
 *
 * @param Ship *_ship
 * @param size_t _x1
 * @param size_t _y1
 * @param size_t _x2
 * @param size_t _y2
 * @param size_t _x3
 * @param size_t _y3
 * @param size_t _x4
 * @param size_t _y4
 */
void Player::set_ship(Ship *_ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                      size_t _x4, size_t _y4) {
    /**
     * Toggle the set flags of four of the Boards Squares, by using their _x and _y coordinates
     */
    Player::own_field.set_ship(_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4);

    _ship->set_ship(Player::own_field.get_Square_ptr(_x1, _y1), Player::own_field.get_Square_ptr(_x2, _y2),
                    Player::own_field.get_Square_ptr(_x3, _y3), Player::own_field.get_Square_ptr(_x4, _y4));
}

/**
 *
 * @param Ship *_ship
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
void Player::set_ship(Ship *_ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                      size_t _x4, size_t _y4, size_t _x5, size_t _y5) {
    /**
     * Toggle the set flags of five of the Boards Squares, by using their _x and _y coordinates
     */
    Player::own_field.set_ship(_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4, _x5, _y5);

    /**
     * set the ships Square* position [] to the actual Squares the ship has been placed on
     */
    _ship->set_ship(Player::own_field.get_Square_ptr(_x1, _y1), Player::own_field.get_Square_ptr(_x2, _y2),
                    Player::own_field.get_Square_ptr(_x3, _y3), Player::own_field.get_Square_ptr(_x4, _y4),
                    Player::own_field.get_Square_ptr(_x5, _y5));
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
