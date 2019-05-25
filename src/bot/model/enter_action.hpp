/**
 * @file enter_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy EnterAction
 */

#ifndef BOT_MODEL_ENTER_ACTION_HPP_
#define BOT_MODEL_ENTER_ACTION_HPP_


#include "hero_action.hpp"

namespace model {
//!  Klasa EnterAction.
/*!
  Klasa imitująca klasę akcji wejścia bohatera do danego celu wydanego przez algorytm bota.
*/
class EnterAction : public HeroAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	EnterAction( const GameObject& target ) : HeroAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "my hero enter object in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}


#endif /* BOT_MODEL_ENTER_ACTION_HPP_ */
