/*
 * build_high_tier_action.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_BUILD_HIGH_TIER_ACTION_HPP_
#define BOT_MODEL_BUILD_HIGH_TIER_ACTION_HPP_

#include "castle_actions.hpp"

namespace model {

class BuildHighTierAction : public CastleAction {

public:
	BuildHighTierAction( const GameObject& target ) : CastleAction( target ){}

	virtual void print(){  std::cout << "Build high tier building in my castle in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}




#endif /* BOT_MODEL_BUILD_HIGH_TIER_ACTION_HPP_ */
