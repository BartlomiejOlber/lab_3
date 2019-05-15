/*
 * guarded_building.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_GUARDED_BUILDING_HPP_
#define BOT_MODEL_GUARDED_BUILDING_HPP_

#include "building.hpp"
#include "troop.hpp"

namespace model {

class GuardedBuilding : public Building {

	Troop guards_;

public:

	GuardedBuilding( Tier building_tier, Status status, int guards_num, Tier guards_tier, int x, int y ) :
		Building( building_tier, status, x, y ), guards_( guards_num, guards_tier, x, y ) {}
	GuardedBuilding( int building_tier, int status, int guards_num, int guards_tier, int x, int y ) :
		Building( building_tier, status, x, y ), guards_( guards_num, TierConverter::from_int(guards_tier), x, y ) {}
	void conquer(){  take_control(); guards_.vanish(); }
	Tier get_guards_tier() const { return guards_.get_tier(); }
	int get_guards_quantity() const { return guards_.get_quantity(); }

};

typedef std::vector<GuardedBuilding> GuardedBuildingContainer;

}//end namespace

#endif /* BOT_MODEL_GUARDED_BUILDING_HPP_ */
