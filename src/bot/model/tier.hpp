/*
 * tiers_enum.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_TIER_HPP_
#define BOT_MODEL_TIER_HPP_

namespace model {

enum class Tier{
	LOW = 0,
	MEDIUM = 1,
	HIGH = 2
};

class TierConverter {

public:
	static Tier from_int( int tier ){
		return static_cast<Tier>(tier);
	}
};

}//end namespace

#endif /* BOT_MODEL_TIER_HPP_ */
