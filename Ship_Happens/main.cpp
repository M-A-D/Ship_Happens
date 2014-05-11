/**********************************************************************************
 * Main Board including testing v0.5													  *
 * 																				  *
 * Matthias Pfitzmayer		PM SoSe 2014							  04.04.2014  *
 **********************************************************************************/

/***********************************************************************************
  * Changelog:
  * 140511  @all    started using doxygen documentation functions
  * 140511  @player.h   tried to work around the player.set_ship problem didn't
  *                     work so well...
  *
  *
  **********************************************************************************/

/***********************************************************************************
 * to do:
 * 140511 @player.h
 * 140511 @player.cpp   find a secure and fast way to set all ships in one member
 *                      func. of player, that fixes a ship on the board and sets
 *                      all flags needed, that may be used for each kind of ship
 *
 *
 **********************************************************************************/

# include "my_headers.h"
# include "player.h"

using namespace std;

int main () {
    Player player_1;

    player_1.set_name("Herbert");
    Player player_2("Spieler 2");
    cout << player_1.check_lose() << endl;
    cout << player_1.get_name() << endl;
    cout << player_2.check_lose() << endl;
    cout << player_2.get_name() << endl;
    Ship* _ship = player_1.get_ship_ptr(1,1);
    cout << _ship->get_lenght() << endl;
    _ship = player_2.get_ship_ptr(2,1);
    cout << _ship->get_lenght() << endl;
    _ship = player_1.get_ship_ptr(3,1);
    cout << _ship->get_lenght() << endl;
    _ship = player_2.get_ship_ptr(4,1);
    cout << _ship->get_lenght() << endl;
    player_1.show_field();
    player_1.show_enemy_field(player_2.return_board_ref());
    player_1.set_ship(player_1.get_ship_ptr(1,1), 1, 1, 2, 1);
    player_1.set_ship(player_1.get_ship_ptr(1,2), 3, 2, 4, 2);
    player_1.set_ship(player_1.get_ship_ptr(1,3), 5, 2, 6, 2);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 2, 2);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 10, 10);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 4, 4);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 5, 5);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 6, 6);
    player_1.show_field();
    player_1.show_enemy_field(player_2.return_board_ref());
    player_1.show_ships();
    return 0;
}
