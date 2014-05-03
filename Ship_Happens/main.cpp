/**********************************************************************************
 * Main Board including testing													  *
 * 																				  *
 * Matthias Pfitzmayer		PM SoSe 2014							  04.04.2014  *
 **********************************************************************************/

/***********************************************************************************
  * Changelog:
  * 140404	MP	@all	Tested std. func.
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

}
