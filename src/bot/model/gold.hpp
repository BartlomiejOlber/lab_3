/**
 * @file gold.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Gold
 */

#ifndef BOT_MODEL_GOLD_HPP_
#define BOT_MODEL_GOLD_HPP_

#include <vector>
#include "game_object.hpp"

namespace model {
//!  Klasa Gold.
/*!
  Klasa złota w rozumieniu bota, będąca obiektem gry, więc publicznie dziedzicząca po klasie GameObject.
*/
class Gold : public GameObject {
	//! Prywatna składowa; ilość złota.
	int quantity_;

public:

    //! Publiczny konstruktor domyślny.
    /*!
      \param quantity ilość złota.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Gold( int quantity = 0, int x = 0, int y = 0) : GameObject(x, y), quantity_( quantity ){}
	//! Getter zwraca ilość złota.
	int get_quantity(){ return quantity_; }

};
//! Wektor złota
typedef std::vector<Gold> GoldContainer;

}//end namespace

#endif /* BOT_MODEL_GOLD_HPP_ */
