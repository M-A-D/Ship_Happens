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
    static size_t const num_subm = 4;
    static size_t const num_dest = 3;
    static size_t const num_bash = 2;
    static size_t const num_airc = 1;

    Submarine subm[num_subm];
    Destroyer dest[num_dest];
    Battleship bash[num_bash];
    AirCarrier airc[num_airc];

    // all ships
    //Submarine subm1;    /**< Submarine 1. */
    //Submarine subm2;    /**< Submarine 2. */
    //Submarine subm3;    /**< Submarine 3. */
    //Submarine subm4;    /**< Submarine 4. */
    //Submarine subm5;    /**< Submarine 5. */
    //Destroyer dest1;    /**< Destroyer 1. */
    //Destroyer dest2;    /**< Destroyer 2. */
    //Destroyer dest3;    /**< Destroyer 3. */
    //Destroyer dest4;    /**< Destroyer 4. */
    //Battleship bash1;   /**< Battleship 1. */
    //Battleship bash2;   /**< Battleship 2. */
    //Battleship bash3;   /**< Battleship 3. */
    //AirCarrier airc;    /**< Air carrier. */

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

    // player.set_ship() with a specific lenght for each function
    void set_ship(Ship* _ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2);
    void set_ship(Ship* _ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3);
    void set_ship(Ship* _ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                  size_t _x4, size_t _y4);
    void set_ship(Ship* _ship, size_t _x1, size_t _y1, size_t _x2, size_t _y2, size_t _x3, size_t _y3,
                  size_t _x4, size_t _y4, size_t _x5, size_t _y5);

    // member func. that returns a reference to the players board
    // just to enable the enemy to bomb the field directly
    Board& return_board_ref();    

    // member func. for testing purposes
    void show_field();
    void show_enemy_field(Board& _en_field);
    void show_ships();

    Ship* get_ship_ptr(size_t _type, size_t _num);
};

# endif // PLAYER_H
