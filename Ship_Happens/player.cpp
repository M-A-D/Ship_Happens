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

/*
 * std constructor
 */
Player::Player() {
    Player::name = "Spieler_1";
    Player::lost = false;
    Player::ready = false;
}

/*
 *
 */
Player::Player(std::string _name) {
    Player::name = _name;
    Player::lost = false;
    Player::ready = false;
}

/*
 * std destructor
 */
Player::~Player() {

}

/*
 * player.set_name(_name) member func to change the players name.
 */
void Player::set_name(std::string _name) {
    Player::name = _name;
}

/*
 * player.check_lose() Check if there are still ships available
 */
bool Player::check_lose() {
    return Player::lost;
}

/*
 * player.get_name() returns the players Name
 */
std::string Player::get_name() {
    return Player::name;
}

/*
 * player.bomb_enemy_field() enables the player to bomb the enemies field
 * using x and y to flag the fields.
 */
void Player::bomb_enemy_field(Board& _en_field, size_t _x, size_t _y) {
    _en_field.hit_square(_x, _y);
}

/*
 * player.set_ship enables a player to place a shipt on the field by soely using
 * two x and y coordinates and a the lenght right now it is used with a fix lenght
 * param, later the lenght flag should be set by the ship used by the player
 */
void Player::set_ship(size_t _len, size_t _x1, size_t _y1, size_t _x2, size_t y2) {
    //[1] func. needs to be done
}

Board& Player::return_board_ref() {
    Board& _field = Player::own_field;
    return _field;
}
