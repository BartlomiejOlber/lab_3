/*
 * hero.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_HERO_HPP_
#define BOT_MODEL_HERO_HPP_

#include "army.hpp"
#include "status.hpp"

namespace model {

class Hero : public GameObject {

static const int MOVEMENT_POINTS = 10;
static const int MOVEMENT_POINTS_LEVEL_BONUS = 1;

	int gold_;
	int level_;
	Army army_;
	Status status_;

public:
	Hero( int gold = 0, int level = 0, int high_tier_army_num = 0, int mid_tier_army_num = 0, int low_tier_army_num = 0,
		int x = 0, int y = 0, Status status = Status::NEUTRAL ) : GameObject(x, y), gold_( gold ), level_( level ),
		army_( high_tier_army_num, mid_tier_army_num, low_tier_army_num, x, y ), status_( status ){}
	Hero( const std::vector<int>& params, Status status ) : GameObject( params[5], params[6]), gold_( params[0] ),
		level_( params[1] ), army_( params[2], params[3], params[4], params[5], params[6] ), status_( status ){}
	void travel_to( int x, int y ){ set_coordinates( x, y ); }
	int get_level() const { return level_; }
	int get_high_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	int get_mid_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	int get_low_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	int get_movement_points() const { return (MOVEMENT_POINTS + level_*MOVEMENT_POINTS_LEVEL_BONUS); }

};


}//end namespace

#endif /* BOT_MODEL_HERO_HPP_ */
