/**********************************************************************************
 * Main Player including testing v0.5											  *
 * 																				  *
 * Matthias Pfitzmayer		PM SoSe 2014							  15.05.2014  *
 **********************************************************************************/

/***********************************************************************************
  * Changelog:
  * 140511  MP  @all        started using doxygen documentation functions
  * 140511  MP  @player.h   tried to work around the player.set_ship problem didn't
  *                         work so well...
  * 140515  MP  @player.h   player.set_ship works finally...
  *
  **********************************************************************************/

/***********************************************************************************
 * to do:
 * 140515   @player.h   rework the player.set_ship() for the use of Square* and Ship&
 *
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

    player_1.show_field();
    player_1.show_enemy_field(player_2.return_board_ref());

    player_1.place_ship(1, 1, 1, 1, 2, 1);
    player_1.place_ship(1, 2, 4, 2, 4, 3);
    player_1.place_ship(1, 3, 10, 2, 10, 3);
    player_1.place_ship(1, 4, 1, 3, 1, 4);
    player_1.place_ship(1, 5, 4, 6, 5, 6);

    player_1.place_ship(2, 1, 6, 8, 7, 8, 8, 8);
    player_1.place_ship(2, 2, 7, 1, 7, 2, 7, 3);
    player_1.place_ship(2, 3, 3, 4, 4, 4, 4, 5);
    player_1.place_ship(2, 4, 3, 8, 3, 9, 3, 10);

    player_1.place_ship(3, 1, 9, 3, 9, 4, 9, 5, 9, 6);
    player_1.place_ship(3, 2, 6, 9, 7, 9, 8, 9, 9, 9);
    player_1.place_ship(3, 3, 7, 4, 7, 5, 7, 6, 7, 7);

    player_1.place_ship(4, 1, 6, 1, 6, 2, 6, 3, 6, 4, 6, 5);

    player_2.bomb_enemy_field(player_1.return_board_ref(), 2, 2);
    player_2.bomb_enemy_field(player_1.return_board_ref(), 2, 3);
    player_2.bomb_enemy_field(player_1.return_board_ref(), 3, 8);
    player_2.bomb_enemy_field(player_1.return_board_ref(), 6, 5);
    player_2.bomb_enemy_field(player_1.return_board_ref(), 4, 2);
    player_2.bomb_enemy_field(player_1.return_board_ref(), 7, 9);

    player_1.bomb_enemy_field(player_2.return_board_ref(), 2, 2);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 10, 10);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 4, 4);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 5, 5);
    player_1.bomb_enemy_field(player_2.return_board_ref(), 6, 5);
    player_1.show_field();
    player_1.show_enemy_field(player_2.return_board_ref());
    player_1.show_ships();
    return 0;
}
