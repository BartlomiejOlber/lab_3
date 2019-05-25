/**
 * @file travel_to_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy TravelToAction
 */


#ifndef BOT_MODEL_TRAVEL_TO_ACTION_HPP_
#define BOT_MODEL_TRAVEL_TO_ACTION_HPP_

#include "hero_action.hpp"

namespace model {
//!  Klasa TravelToAction.
/*!
  Klasa imitująca klasę akcji podróżowania bohatera do danego celu wydanego przez algorytm bota.
*/
class TravelToAction : public HeroAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	TravelToAction( const GameObject& target ) : HeroAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "my hero travel to location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}



#endif /* BOT_MODEL_TRAVEL_TO_ACTION_HPP_ */
