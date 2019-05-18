/*
 * build_low_tier_action.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_BUILD_LOW_TIER_ACTION_HPP_
#define BOT_MODEL_BUILD_LOW_TIER_ACTION_HPP_

#include "castle_actions.hpp"

namespace model {

class BuildLowTierAction : public CastleAction {

public:
	BuildLowTierAction( const GameObject& target ) : CastleAction( target ){}
};

}



#endif /* BOT_MODEL_BUILD_LOW_TIER_ACTION_HPP_ */
