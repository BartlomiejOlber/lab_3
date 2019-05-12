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

	int quantity_;

public:
	Troop( int quantity, Tier tier, int x, int y ) : Entity( tier, x, y ), quantity_( quantity ) {}
	int get_quantity() const { return quantity_; }
	void recruit( int quantity ){ quantity_ += quantity; }
	void kill( int quantity ){ quantity >= quantity_ ? quantity_ = 0 : quantity_ -= quantity; }
	void vanish(){ quantity_ = 0;}
};

typedef std::vector<Troop> TroopContainer;

}//end namespace

#endif /* BOT_MODEL_TROOP_HPP_ */
