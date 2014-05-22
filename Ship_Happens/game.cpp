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

# include "game.h"
# include "my_headers.h"


/**
 * @brief Game::Game
 * std. constructor
 */
Game::Game(){

}


/**
 * @brief Game::~Game
 * destructor
 */
Game::~ Game() {

}


/**
 * @brief Game::init_game
 * put the Game into a defined status, where Player 1, the host is activ and Player 2 is waiting
 * for Player 1 to finish
 */
void Game::init_game() {
    Game::player.change_activ_status();
    Game::enemy.change_activ_status();
}


/**
 * @brief Game::change_player_names
 */
void Game::change_player_names() {
    std::string player_name;
    std::string enemy_name;
    std::cout << "please enter the first players name:" << std::endl;
    std::cin >> player_name;
    Game::player.set_name(player_name);
    std::cout << "please enter the second players name:" << std::endl;
    std::cin >> enemy_name;
    Game::enemy.set_name(enemy_name);
}


/**
 * @brief Game::set_ship_routine
 * defines a prototype routine, that can be used to set a ship from the graphic surface
 */
bool Game::place_ships(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4, Square* _sq5) {
    if(Game::player.return_board_ref().get_square_empty(_sq1, _sq2, _sq3, _sq4, _sq5)) {
        Game::player.place_ship(_sq1, _sq2, _sq3, _sq4, _sq5);
    }
    return true;
}


/**
 * @brief Game::set_ship_routine
 *
 */
void Game::player_set_ship_routine() {
    Board& field = Game::player.return_board_ref();
    size_t xa, ya, xe, ye, x3, y3, x4, y4, x5, y5;
    size_t& _xa = xa;
    size_t& _ya = ya;
    size_t& _xe = xe;
    size_t& _ye = ye;
    size_t& _x3 = x3;
    size_t& _y3 = y3;
    size_t& _x4 = x4;
    size_t& _y4 = y4;
    size_t& _x5 = x5;
    size_t& _y5 = y5;

    Square *_sq1, *_sq2, *_sq3, *_sq4, *_sq5;

    std::cout << Game::player.get_name() << " place your ships on the field" << std::endl;

    for(size_t count = 1; count <= Game::player.get_num_submarines(); count++) {
        Submarine& subm_ref = Game::player.get_Submarine_ref(count);
        while(!(subm_ref.get_ship_set())) {
            Game::read_ship_coordinates(_xa, _ya, _xe, _ye);
            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(xe, ye);

              if(Game::player.place_ship(_sq1, _sq2)) {
                subm_ref.set_ship(_sq1, _sq2);
            }
        }
    }

    Game::player.print_field();

    for(size_t count = 1; count <= Game::player.get_num_destroyer(); count++) {
        Destroyer& dest_ref = Game::player.get_Destroyer_ref(count);
        while(!(dest_ref.get_ship_set())) {
            Game::read_ship_coordinates(_xa, _ya, _xe, _ye, _x3, _y3);

            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(x3, y3);
            _sq3 = field.get_Square_ptr(xe, ye);

            if(Game::player.place_ship(_sq1, _sq2, _sq3)) {
                dest_ref.set_ship(_sq1, _sq2, _sq3);
            }
        }
    }

    Game::player.print_field();

    for(size_t count = 1; count <= Game::player.get_num_battleships(); count++) {
        Battleship& bash_ref = Game::player.get_BattleShip_ref(count);
        while(!(bash_ref.get_ship_set())) {
            Game::read_ship_coordinates(_xa, _ya, _xe, _ye, _x3, _y3, _x4, _y4);
            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(x3, y3);
            _sq3 = field.get_Square_ptr(x4, y4);
            _sq4 = field.get_Square_ptr(xe, ye);


            if(Game::player.place_ship(_sq1, _sq3, _sq4, _sq2)) {
                bash_ref.set_ship(_sq1, _sq3, _sq4, _sq2);
            }
        }
    }

    Game::player.print_field();

    for(size_t count = 1; count <= Game::player.get_num_aircarrier(); count++) {
        AirCarrier& airc_ref = Game::player.get_AirCarrier_ref(count);
        while(!(airc_ref.get_ship_set())) {
            Game::read_ship_coordinates(_xa, _ya, _xe, _ye, _x3, _y3, _x4, _y4, _x5, _y5);
            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(x3, y3);
            _sq3 = field.get_Square_ptr(x4, y4);
            _sq4 = field.get_Square_ptr(x5, y5);
            _sq5 = field.get_Square_ptr(xe, ye);

            if(Game::player.place_ship(_sq1, _sq2, _sq3, _sq4, _sq5)) {
                airc_ref.set_ship(_sq1, _sq2, _sq3, _sq4, _sq5);
            }
        }
    }

    Game::player.change_activ_status();
    Game::player.print_field();
    Game::player.print_ships();
}


/**
 * @brief Game::enemy_set_ship_routine
 */
void Game::enemy_set_ship_routine() {
    Board& field = Game::enemy.return_board_ref();
    size_t xa, ya, xe, ye, x3, y3, x4, y4, x5, y5;
    size_t& _xa = xa;
    size_t& _ya = ya;
    size_t& _xe = xe;
    size_t& _ye = ye;
    size_t& _x3 = x3;
    size_t& _y3 = y3;
    size_t& _x4 = x4;
    size_t& _y4 = y4;
    size_t& _x5 = x5;
    size_t& _y5 = y5;

    Square *_sq1, *_sq2, *_sq3, *_sq4, *_sq5;

    std::cout << Game::enemy.get_name() << " place your ships on the field" << std::endl;

    for(size_t count = 1; count <= Game::enemy.get_num_submarines(); count++) {
        Submarine& subm_ref = Game::enemy.get_Submarine_ref(count);
        while(!(subm_ref.get_ship_set())) {

            while(!(Game::read_ship_coordinates(_xa, _ya, _xe, _ye))) {
                std::cout << "try again:" << std::endl;
            }

            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(xe, ye);

              if(Game::enemy.place_ship(_sq1, _sq2)) {
                subm_ref.set_ship(_sq1, _sq2);
            }
        }
    }

    Game::enemy.print_field();

    for(size_t count = 1; count <= Game::enemy.get_num_destroyer(); count++) {
        Destroyer& dest_ref = Game::enemy.get_Destroyer_ref(count);
        while(!(dest_ref.get_ship_set())) {

            while(!(Game::read_ship_coordinates(_xa, _ya, _xe, _ye, _x3, _y3))) {
                std::cout << "try again:" << std::endl;
            }

            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(x3, y3);
            _sq3 = field.get_Square_ptr(xe, ye);

            if(Game::enemy.place_ship(_sq1, _sq2, _sq3)) {
                dest_ref.set_ship(_sq1, _sq2, _sq3);
            }
        }
    }

    Game::enemy.print_field();

    for(size_t count = 1; count <= Game::enemy.get_num_battleships(); count++) {
        Battleship& bash_ref = Game::enemy.get_BattleShip_ref(count);
        while(!(bash_ref.get_ship_set())) {

            while(!(Game::read_ship_coordinates(_xa, _ya, _xe, _ye, _x3, _y3, _x4, _y4))) {
                std::cout << "try again:" << std::endl;
            }

            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(x3, y3);
            _sq3 = field.get_Square_ptr(x4, y4);
            _sq4 = field.get_Square_ptr(xe, ye);


            if(Game::enemy.place_ship(_sq1, _sq3, _sq4, _sq2)) {
                bash_ref.set_ship(_sq1, _sq3, _sq4, _sq2);
            }
        }
    }

    Game::enemy.print_field();

    for(size_t count = 1; count <= Game::enemy.get_num_aircarrier(); count++) {
        AirCarrier& airc_ref = Game::enemy.get_AirCarrier_ref(count);
        while(!(airc_ref.get_ship_set())) {

            while(!(Game::read_ship_coordinates(_xa, _ya, _xe, _ye, _x3, _y3, _x4, _y4, _x5, _y5))) {
                std::cout << "try again:" << std::endl;
            }

            _sq1 = field.get_Square_ptr(xa, ya);
            _sq2 = field.get_Square_ptr(x3, y3);
            _sq3 = field.get_Square_ptr(x4, y4);
            _sq4 = field.get_Square_ptr(x5, y5);
            _sq5 = field.get_Square_ptr(xe, ye);

            if(Game::enemy.place_ship(_sq1, _sq2, _sq3, _sq4, _sq5)) {
                airc_ref.set_ship(_sq1, _sq2, _sq3, _sq4, _sq5);
            }
        }
    }

    Game::enemy.change_activ_status();
    Game::enemy.print_field();
    Game::enemy.print_ships();
}


/**
 * @brief Game::bomb_field_routine
 */
void Game::bomb_field_routine() {
    size_t xb, yb;
    size_t& _xb = xb;
    size_t& _yb = yb;

    while(!(Game::player.check_lose()) & !(Game::enemy.check_lose())) {

        Game::player.change_activ_status();
        std::cout << Game::player.get_name() << " please select the field you want to bomb" << std::endl;
        while(!(Game::read_bomb_coordinates(_xb, _yb))) {
            std::cout << "Try again:" << std::endl;
        }

        std::cout << "Now the field should be bombed" << std::endl;
        Game::player.bomb_enemy_field(Game::enemy.return_board_ref(), xb, yb);


        Game::player_print_boards();
        Game::player_print_ships();
        //Game::player.print_enemy_field(Game::enemy.return_board_ref());

        Game::player.change_activ_status();


        Game::enemy.change_activ_status();
        std::cout << Game::enemy.get_name() << " please select the field you want to bomb" << std::endl;
        while(!(Game::read_bomb_coordinates(_xb, _yb))) {
            std::cout << "Try again:" << std::endl;
        }

        Game::enemy.bomb_enemy_field(Game::player.return_board_ref(), xb, yb);


        Game::enemy_print_boards();
        Game::enemy_print_ships();
        //Game::enemy.print_enemy_field(Game::player.return_board_ref());

        Game::player.change_activ_status();
    }
}


/**
 * @brief Game::read_ship_coordinates
 * @param lenght
 * @param _xa
 * @param _ya
 * @param _xe
 * @param _ye
 * @return
 */
bool Game::read_ship_coordinates(size_t &_xa, size_t &_ya, size_t &_xe, size_t &_ye) {
    bool legal = false;

    std::cout << "enter the first 'x' cordinate:    ";
    std::cin >> _xa;

    std::cout << "enter the first 'y' cordinate:    ";
    std::cin >> _ya;

    std::cout << "enter the second 'x' coordinate:  ";
    std::cin >> _xe;

    std::cout << "enter the second 'y' coordinate:  ";
    std::cin >> _ye;

    if(_xe == _xa) {
        std::cout << "vertically" << std::endl;
        _ye = (_ya + 1);

    }

    else if(_ye == _ya) {
        std::cout << "horizontally" << std::endl;
        _xe = (_xa + 1);
    }

    else {
        std::cout << "Ship must be set vertically" << std::endl;
        return legal;
    }

    if((_xe <= 10) & (_ye <= 10) & (_xa <= 10) & (_ya <= 10)) {
        legal = true;
    }

    std::cout << legal << std::endl;
    return legal;
}


/**
 * @brief Game::read_ship_coordinates
 * @param lenght
 * @param _xa
 * @param _ya
 * @param _xe
 * @param _ye
 * @param _x3
 * @param _y3
 * @return
 */
bool Game::read_ship_coordinates(size_t &_xa, size_t &_ya, size_t &_xe, size_t &_ye, size_t &_x3, size_t &_y3) {
    bool legal = false;

    std::cout << "enter the first 'x' cordinate:    ";
    std::cin >> _xa;

    std::cout << "enter the first 'y' cordinate:    ";
    std::cin >> _ya;

    std::cout << "enter the second 'x' coordinate:  ";
    std::cin >> _xe;

    std::cout << "enter the second 'y' coordinate:  ";
    std::cin >> _ye;

    if(_xe == _xa) {
        std::cout << "vertically" << std::endl;
        _x3 = _xa;

        _ye = (_ya + 2);
        _y3 = (_ya + 1);
    }

    if(_ye == _ya) {
        std::cout << "horizontally" << std::endl;
        _y3 = _ya;

        _xe = (_xa + 2);
        _x3 = (_xa + 1);
    }
    if((_xe <= 10)& (_ye <= 10) & (_xa <= 10) & (_ya <= 10) & (_x3 <= 10) & (_y3 <= 10)) {
        legal = true;
    }

    std::cout << legal << std::endl;
    return legal;
}


/**
 * @brief Game::read_ship_coordinates
 * @param lenght
 * @param _xa
 * @param _ya
 * @param _xe
 * @param _ye
 * @param _x3
 * @param _y3
 * @param _x4
 * @param _y4
 * @return
 */
bool Game::read_ship_coordinates(size_t &_xa, size_t &_ya, size_t &_xe, size_t &_ye, size_t &_x3, size_t &_y3, size_t &_x4, size_t &_y4) {
    bool legal = false;

    std::cout << "enter the first 'x' cordinate:    ";
    std::cin >> _xa;

    std::cout << "enter the first 'y' cordinate:    ";
    std::cin >> _ya;

    std::cout << "enter the second 'x' coordinate:  ";
    std::cin >> _xe;

    std::cout << "enter the second 'y' coordinate:  ";
    std::cin >> _ye;

    if(_xe == _xa) {
        std::cout << "vertically" << std::endl;
        _x3 = _xa;
        _x4 = _xa;

        _ye = (_ya + 3);
        _y3 = (_ya + 1);
        _y4 = (_ya + 2);
    }

    if(_ye == _ya) {
        std::cout << "horizontally" << std::endl;
        _y3 = _ya;
        _y4 = _ya;

        _xe = (_xa + 3);
        _x3 = (_xa + 1);
        _x4 = (_xa + 2);
    }
    if((_xe <= 10) & (_ye <= 10) & (_xa <= 10) & (_ya <= 10) & (_x3 <= 10) & (_y3 <= 10)
      &(_x4 <= 10) & (_y4 <=10)) {
        legal = true;
    }

    std::cout << legal << std::endl;

    return legal;
}


/**
 * @brief Game::read_ship_coordinates
 * @param lenght
 * @param _xa
 * @param _ya
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
bool Game::read_ship_coordinates(size_t &_xa, size_t &_ya, size_t &_xe, size_t &_ye, size_t &_x3, size_t &_y3, size_t &_x4, size_t &_y4, size_t &_x5, size_t &_y5) {
    bool legal = false;

    std::cout << "enter the first 'x' cordinate:    ";
    std::cin >> _xa;

    std::cout << "enter the first 'y' cordinate:    ";
    std::cin >> _ya;

    std::cout << "enter the second 'x' coordinate:  ";
    std::cin >> _xe;

    std::cout << "enter the second 'y' coordinate:  ";
    std::cin >> _ye;

    if(_xe == _xa) {
        std::cout << "vertically" << std::endl;
        _x3 = _xa;
        _x4 = _xa;
        _x5 = _xa;

        _ye = (_ya + 4);
        _y3 = (_ya + 1);
        _y4 = (_ya + 2);
        _y5 = (_ya + 3);
    }

    if(_ye == _ya) {
        std::cout << "horizontally" << std::endl;
        _y3 = _ya;
        _y4 = _ya;
        _y5 = _ya;

        _xe = (_xa + 4);
        _x3 = (_xa + 1);
        _x4 = (_xa + 2);
        _x5 = (_xa + 3);
    }

    if((_xe <= 10) & (_ye <= 10) & (_xa <= 10) & (_ya <= 10) & (_x3 <= 10) & (_y3 <= 10)
      &(_x4 <= 10) & (_y4 <=10) & (_x5 <= 10) & (_y5 <= 10)) {
        legal = true;
    }
    std::cout << legal << std::endl;
    return legal;
}


/**
 * @brief Game::read_bomb_coordinates
 * @param _xb
 * @param _yb
 * @return bool legal
 */
bool Game::read_bomb_coordinates(size_t &_xb, size_t &_yb) {
    bool legal = false;
    std::cout << "enter the 'x' cordinate:    ";
    std::cin >> _xb;

    std::cout << "enter the 'y' cordinate:    ";
    std::cin >> _yb;

    std::cout << _xb << "   " << _yb << std::endl;

    if((_xb <= 10) & (_yb <= 10)) {
        legal = true;
    }

    std::cout << legal << std::endl;

    return legal;
}


/**
 * @brief Game::player_print_boards
 */
void Game::player_print_boards() {
    Game::player.print_field();
    Game::player.print_enemy_field(Game::enemy.return_board_ref());
}


/**
 * @brief Game::player_print_ships
 */
void Game::player_print_ships() {
    Game::player.print_ships();
}


/**
 * @brief Game::enemy_print_boards
 */
void Game::enemy_print_boards() {
    Game::player.print_field();
    Game::player.print_enemy_field(Game::player.return_board_ref());
}


/**
 * @brief Game::enemy_print_ships
 */
void Game::enemy_print_ships() {
    Game::enemy.print_ships();
}


/**
 * @brief Game::player_set_ship_test
 *
 * this is the your board:
 * A B C D E F G H I K
 *|X| |X|X| | |X|X|X| | 1
 *|X| | | | | | | | | | 2
 *| | |X| |X|X|X|X| | | 3
 *|X| |X| | | | | | | | 4
 *|X| |X| |X| | |X| | | 5
 *| | | | |X| | |X| | | 6
 *|X| |X| |X| | |X| |X| 7
 *|X| |X| |X| | |X| |X| 8
 *| | |X| | | | |X| |X| 9
 *|X|X| | |X|X|X| | |X| 10
 */
void Game::player_set_ship_test() {

    /**
     * set submarines
     */
    Game::player.place_ship(1, 1, 1, 1, 1, 2);
    Game::player.place_ship(1, 2, 1, 4, 1, 5);
    Game::player.place_ship(1, 3, 1, 7, 1, 8);
    Game::player.place_ship(1, 4, 1, 10, 2, 10);
    Game::player.place_ship(1, 5, 3, 1, 4, 1);

    /**
     * set destroyer
     */
    Game::player.place_ship(2, 1, 3, 3, 3, 4, 3, 5);
    Game::player.place_ship(2, 2, 3, 7, 3, 8, 3, 9);
    Game::player.place_ship(2, 3, 7, 1, 8, 1, 9, 1);
    Game::player.place_ship(2, 4, 5, 10, 6, 10, 7, 10);

    /**
     * set all battleships
     */
    Game::player.place_ship(3, 1, 5, 3, 6, 3, 7, 3, 8, 3);
    Game::player.place_ship(3, 2, 5, 5, 5, 6, 5, 7, 5, 8);
    Game::player.place_ship(3, 3, 10, 7, 10, 8, 10, 9, 10, 10);

    /**
     * set the air carrier
     */
    Game::player.place_ship(4, 1, 8, 5, 8, 6, 8, 7, 8, 8, 8, 9);

    Game::player.print_field();
}

/**
 * @brief Game::enemy_set_ship_test
 *
 * this is the your board:
 *  A B C D E F G H I K
 * |X| |X|X| | |X|X|X| | 1
 * |X| | | | | | | | | | 2
 * | | |X| |X|X|X|X| | | 3
 * |X| |X| | | | | | | | 4
 * |X| |X| |X| | |X| | | 5
 * | | | | |X| | |X| | | 6
 * |X| |X| |X| | |X| |X| 7
 * |X| |X| |X| | |X| |X| 8
 * | | |X| | | | |X| |X| 9
 * |X|X| | |X|X|X| | |X| 10
 */

void Game::enemy_set_ship_test() {
    /**
     * set submarines
     */
    Game::enemy.place_ship(1, 1, 1, 1, 1, 2);
    Game::enemy.place_ship(1, 2, 1, 4, 1, 5);
    Game::enemy.place_ship(1, 3, 1, 7, 1, 8);
    Game::enemy.place_ship(1, 4, 1, 10, 2, 10);
    Game::enemy.place_ship(1, 5, 3, 1, 4, 1);

    /**
     * set destroyer
     */
    Game::enemy.place_ship(2, 1, 3, 3, 3, 4, 3, 5);
    Game::enemy.place_ship(2, 2, 3, 7, 3, 8, 3, 9);
    Game::enemy.place_ship(2, 3, 7, 1, 8, 1, 9, 1);
    Game::enemy.place_ship(2, 4, 5, 10, 6, 10, 7, 10);

    /**
     * set all battleships
     */
    Game::enemy.place_ship(3, 1, 5, 3, 6, 3, 7, 3, 8, 3);
    Game::enemy.place_ship(3, 2, 5, 5, 5, 6, 5, 7, 5, 8);
    Game::enemy.place_ship(3, 3, 10, 7, 10, 8, 10, 9, 10, 10);

    /**
     * set the air carrier
     */
    Game::enemy.place_ship(4, 1, 8, 5, 8, 6, 8, 7, 8, 8, 8, 9);

    Game::enemy.print_field();
}
