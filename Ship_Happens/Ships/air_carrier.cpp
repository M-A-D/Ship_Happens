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

/**
 * @brief AirCarrier::AirCarrier
 * std constructor
 * @param bool AirCarrier::alive = true
 * @param bool AirCarrier::set = false
 */
AirCarrier::AirCarrier() {
    AirCarrier::alive = true;
    AirCarrier::set = false;
}

/**
 * @brief AirCarrier::~AirCarrier()
 * destructor
 */
AirCarrier::~AirCarrier() {

}

/**
 * @brief AirCarrier::get_lenght
 * @return size_t AirCarrier::lenght
 */
size_t AirCarrier::get_lenght() {
    return AirCarrier::lenght;
}
