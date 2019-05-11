/*
 * guarded_building.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef GUARDED_BUILDING_HPP_
#define GUARDED_BUILDING_HPP_

#include "building.hpp"
#include "troop.hpp"

class GuardedBuilding : public Building {

	Troop guards_;

public:

	GuardedBuilding( Tier building_tier, Status status, int guards_num, Tier guards_tier, int x, int y ) :
		tier_( building_tier), status_( status ), guards_( guards_num, guards_tier, x, y ), coord_x_( x ), coord_y_( y ){}
	void take_control() : status_( Status::FRIEND ) { guards_.vanish(); }

};



#endif /* GUARDED_BUILDING_HPP_ */
