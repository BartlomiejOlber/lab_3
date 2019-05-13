/*
 * hero.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_HERO_HPP_
#define BOT_MODEL_HERO_HPP_

#include "army.hpp"

namespace model {

class Hero : public GameObject {

static const int MOVEMENT_POINTS = 10;
static const int MOVEMENT_POINTS_LEVEL_BONUS = 1;

	int gold_;
	int level_;
	Army army_;

public:
	Hero( int gold, int level, int high_tier_army_num, int mid_tier_army_num, int low_tier_army_num, int x, int y ) :
		GameObject(x, y), gold_( gold ), level_( level ),
		army_( high_tier_army_num, mid_tier_army_num, low_tier_army_num, x, y ){}
	void travel_to( int x, int y ){ set_coordinates( x, y ); }
	int get_level() const { return level_; }
	int get_high_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	int get_mid_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	int get_low_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	int get_movement_points() const { return (MOVEMENT_POINTS + level_*MOVEMENT_POINTS_LEVEL_BONUS); }

};


}//end namespace

#endif /* BOT_MODEL_HERO_HPP_ */
