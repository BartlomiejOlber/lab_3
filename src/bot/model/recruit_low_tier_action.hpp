/*
 * recruit_low_tier_action.hpp
 *
 *  Created on: May 18, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_RECRUIT_LOW_TIER_ACTION_HPP_
#define BOT_MODEL_RECRUIT_LOW_TIER_ACTION_HPP_


#include "castle_actions.hpp"

namespace model {

class RecruitLowTierAction : public CastleAction {

public:
	RecruitLowTierAction( const GameObject& target ) : CastleAction( target ){}
};

}


#endif /* BOT_MODEL_RECRUIT_LOW_TIER_ACTION_HPP_ */
