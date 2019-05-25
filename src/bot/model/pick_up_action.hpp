/**
 * @file pick_up_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy PickUpAction
 */

#ifndef BOT_MODEL_PICK_UP_ACTION_HPP_
#define BOT_MODEL_PICK_UP_ACTION_HPP_


#include "hero_action.hpp"

namespace model {
//!  Klasa PickUpAction.
/*!
  Klasa imitująca klasę akcji podniesienia danych surowców na mapie wydanego przez algorytm bota.
*/
class PickUpAction : public HeroAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	PickUpAction( const GameObject& target ) : HeroAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "my hero pick up in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}


#endif /* BOT_MODEL_PICK_UP_ACTION_HPP_ */
