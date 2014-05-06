/************************************************************************************
 * ship.h 																			*
 * Contains the definition of the class ship, it's members and member-functions		*
 * Matthias Pfitzmayer		140404		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Definition of the Ship Class
  *
  *
  ***********************************************************************************/

 # ifndef SHIP_H
 # define SHIP_H

 # include "my_headers.h"
 # include "square.h"

 class Ship {
 private:
     bool alive;
     bool set;
     static size_t const lenght = 2;
     Square *position[lenght];

 public:
     Ship();
     ~Ship();
     /*
      * a member function for every Ship_lenght
      */
     void set_ship(Square* _sq1, Square* _sq2);
     void set_ship(Square* _sq1, Square* _sq2, Square* _sq3);
     void set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4);
     void set_ship(Square* _sq1, Square* _sq2, Square* _sq3, Square* _sq4, Square* _sq5);
     void check_ship_stat();
     void display_ship();

     size_t get_lenght();
 };

 # endif // SHIP_H
