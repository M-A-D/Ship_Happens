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

/**
 * @brief The Player class
 */
class Player {
private:
    std::string name;   /**< Player name. */
    bool lost;          /**< Bool lost. */
    bool ready;         /**< Bool ready. indicates if a player is ready with his turn*/
    Board own_field;    /**< Board. */
    static size_t const num_subm = 5;   /**< The number of Submarines*/
    static size_t const num_dest = 4;   /**< The number of Destoyer*/
    static size_t const num_bash = 3;   /**< The number of Battleships*/
    static size_t const num_airc = 1;   /**< The number of Air Carriers*/

    Submarine subm[num_subm];
    Destroyer dest[num_dest];
    Battleship bash[num_bash];
    AirCarrier airc[num_airc];

public:

    Player ();                      // std. constructor
    Player (std::string _name);     // specific constructor using a given name
    ~Player ();                     // destructor

    // manipulation Player::name
    void set_name();
    void set_name(std::string _name);
    std::string get_name();

    // basic player abilitie
    bool check_lose();
    void bomb_enemy_field(Board& _en_field, size_t _x, size_t _y);

    //bool place_ship(Ship::type, Square* _sq1, Square* _sq2, Square* _sq3 = NULL, Square* _sq4 = NULL, Square* _sq5 = NULL);

    bool place_ship(size_t _type, size_t _num, size_t _x1, size_t _y1, size_t _x2, size_t _y2,
                    size_t _x3 = 0, size_t _y3 = 0, size_t _x4 = 0, size_t _y4 = 0, size_t _x5 = 0, size_t _y5 = 0);


    // member func. that return references to the players large Objects
    // to enable easy and direct interaction
    Board& return_board_ref();
    Submarine& get_Submarine_ref(size_t _num);
    Destroyer& get_Destroyer_ref(size_t _num);
    Battleship& get_BattleShip_ref(size_t _num);
    AirCarrier& get_AirCarrier_ref(size_t _num);

    Ship* get_ship_ptr(size_t _type, size_t _num);

    // member func. for testing purposes
    void show_field();
    void show_enemy_field(Board& _en_field);
    void show_ships();

};

# endif // PLAYER_H
