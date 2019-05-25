/**
 * @file recruit_high_tier_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy RecruitHighTierAction
 */

#ifndef BOT_MODEL_RECRUIT_HIGH_TIER_ACTION_HPP_
#define BOT_MODEL_RECRUIT_HIGH_TIER_ACTION_HPP_

#include "castle_actions.hpp"

namespace model {
//!  Klasa RecruitHighTierAction.
/*!
  Klasa imitująca klasę akcji rekrutacji jednostek wysokiego poziomu wydanego przez algorytm bota.
*/
class RecruitHighTierAction : public CastleAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	RecruitHighTierAction( const GameObject& target ) : CastleAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "recruit high tier troop in my castle in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}



#endif /* BOT_MODEL_RECRUIT_HIGH_TIER_ACTION_HPP_ */
