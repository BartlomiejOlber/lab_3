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
	Entity( Tier tier, int x, int y ) : GameObject( x, y ), tier_( tier ){}
	void set_tier( Tier tier ){ tier_ = tier; }
	Tier get_tier() const { return tier_;}
	virtual ~Entity() = 0;

};

}//end namespace

#endif /* BOT_MODEL_ENTITY_HPP_ */
