/**
 * @file build_low_tier_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy BuildLowTierAction
 */

#ifndef BOT_MODEL_BUILD_LOW_TIER_ACTION_HPP_
#define BOT_MODEL_BUILD_LOW_TIER_ACTION_HPP_

#include "castle_actions.hpp"

namespace model {

//!  Klasa BuildLowTierAction.
/*!
  Klasa imitująca klasę akcji budowy budynku niskiego poziomu wydanego przez algorytm bota.
*/
class BuildLowTierAction : public CastleAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	BuildLowTierAction( const GameObject& target ) : CastleAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "Build low tier building in my castle in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}



#endif /* BOT_MODEL_BUILD_LOW_TIER_ACTION_HPP_ */
