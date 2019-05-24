/*
 * recruit_high_tier_action.hpp
 *
 *  Created on: May 18, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_RECRUIT_HIGH_TIER_ACTION_HPP_
#define BOT_MODEL_RECRUIT_HIGH_TIER_ACTION_HPP_

#include "castle_actions.hpp"

namespace model {

class RecruitHighTierAction : public CastleAction {

public:
	RecruitHighTierAction( const GameObject& target ) : CastleAction( target ){}

	virtual void print(){  std::cout << "recruit high tier troop in my castle in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}



#endif /* BOT_MODEL_RECRUIT_HIGH_TIER_ACTION_HPP_ */
