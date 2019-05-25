/**
 * @file fight_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy FightAction
 */

#ifndef BOT_MODEL_FIGHT_ACTION_HPP_
#define BOT_MODEL_FIGHT_ACTION_HPP_

#include "hero_action.hpp"

namespace model {
//!  Klasa FightAction.
/*!
  Klasa imitująca klasę akcji walki z danym celem wydaną przez algorytm bota.
*/
class FightAction : public HeroAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	FightAction( const GameObject& target ) : HeroAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "my hero fight in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}



#endif /* BOT_MODEL_FIGHT_ACTION_HPP_ */
