/*
 * monsters.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_TROOP_HPP_
#define BOT_MODEL_TROOP_HPP_

#include <vector>
#include "entity.hpp"

namespace model {

class Troop : public Entity {

public:
	static const int HIGH_TIER_FACTOR = 50;
	static const int MID_TIER_FACTOR = 10;

private:
	int quantity_;

public:
	Troop( int quantity, Tier tier, int x, int y ) : Entity( tier, x, y ), quantity_( quantity ) {}
	Troop( int quantity = 0, int tier = 0, int x = 0, int y = 0 ) : Entity( tier, x, y ), quantity_( quantity ) {}
	int get_quantity() const { return quantity_; }
	void recruit( int quantity ){ quantity_ += quantity; }
	void kill( int quantity ){ quantity >= quantity_ ? quantity_ = 0 : quantity_ -= quantity; }
	void vanish(){ quantity_ = 0;}
	int count_troop_force() const { if( get_tier() == Tier::HIGH ) return quantity_ * HIGH_TIER_FACTOR;
		if( get_tier() == Tier::MEDIUM ) return quantity_ * MID_TIER_FACTOR;
		return quantity_;
	}
};

typedef std::vector<Troop> TroopContainer;

}//end namespace

#endif /* BOT_MODEL_TROOP_HPP_ */
