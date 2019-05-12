/*
 * entity.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_ENTITY_HPP_
#define BOT_MODEL_ENTITY_HPP_

#include "game_object.hpp"
#include "tier.hpp"

namespace model {

class Entity : public GameObject {

	Tier tier_;

public:
	Tier get_tier() const { return tier_;}
	~Entity(){};

};

}//end namespace

#endif /* BOT_MODEL_ENTITY_HPP_ */
