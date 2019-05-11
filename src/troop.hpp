/*
 * monsters.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef TROOP_HPP_
#define TROOP_HPP_

#include "entity.hpp"

class Troop : public Entity {

	int quantity_;

public:
	Troop( int quantity, Tier tier, int x, int y ) : quantity_( quantity ),
		tier_( tier ), coord_x_( x ), coord_y_( y ){};
	int get_quantity(){ return quantity_;}
	void kill( int quantity ){ quantity >= quantity_ ? quantity_ = 0 : quantity_ -= quantity; }
	void vanish() : quantity_( 0 ){}
};


#endif /* TROOP_HPP_ */
