/**
 * @file recruit_mid_tier_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy RecruitMidTierAction
 */

#ifndef BOT_MODEL_RECRUIT_MID_TIER_ACTION_HPP_
#define BOT_MODEL_RECRUIT_MID_TIER_ACTION_HPP_


#include "castle_actions.hpp"

namespace model {
//!  Klasa RecruitMidTierAction.
/*!
  Klasa imitująca klasę akcji rekrutacji jednostek średniego poziomu wydanego przez algorytm bota.
*/
class RecruitMidTierAction : public CastleAction {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	RecruitMidTierAction( const GameObject& target ) : CastleAction( target ){}
	//! Wirtualna metoda print.
	/*!
	  Stosowana jedynie do informacji o zawartości kontenera decyzji
	*/
	virtual void print(){  std::cout << "recruit mid tier in my castle in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}


#endif /* BOT_MODEL_RECRUIT_MID_TIER_ACTION_HPP_ */
