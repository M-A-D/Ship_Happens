/************************************************************************************
 * battleship.cpp       v0.5														*
 * the battleship class is the subclass of ship, it is the largest of the 4 with    *
 * a lenght of 5.                                                                   *
 *                                                                                  *
 * Matthias Pfitzmayer		140401		madmayer@gmx.net							*
 ************************************************************************************/

 /***********************************************************************************
  * Changelog:
  * 140501  MP  @all    Created constructor an destructor
  *
  *
  *
  ***********************************************************************************/

# include "air_carrier.h"

/*
 * std constructor
 */
AirCarrier::AirCarrier() {
    AirCarrier::alive = ture;
    AirCarrier::set = false;
}

/*
 * destructor
 */
AirCarrier::~AirCarrier() {

}
