/*
 * castle.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_CASTLE_HPP_
#define BOT_MODEL_CASTLE_HPP_

#include "army.hpp"
#include "building.hpp"

namespace model {

class Castle : public GameObject {

public:

static const int LOW_TIER_BUILDING_DEFENCE_BONUS = 1;
static const int MID_TIER_BUILDING_DEFENCE_BONUS = 2;
static const int HIGH_TIER_BUILDING_DEFENCE_BONUS = 5;
static const int LOW_TIER_BUILDING_COST = 1000;
static const int MID_TIER_BUILDING_COST = 4000;
static const int HIGH_TIER_BUILDING_COST = 15000;
static const int LOW_TIER_ENTITY_COST = 100;
static const int MID_TIER_ENTITY_COST = 400;
static const int HIGH_TIER_ENTITY_COST = 2000;
static const int MAX_HIGH_TIER_BUILDINGS = 3;
static const int MAX_MID_TIER_BUILDINGS = 5;
static const int MAX_LOW_TIER_BUILDINGS = 10;

private:

	Army garrison_;
	Status status_;
	int high_tier_buildings_num_;
	int mid_tier_buildings_num_;
	int low_tier_buildings_num_;
	int high_tier_recruitment_num_;
	int mid_tier_recruitment_num_;
	int low_tier_recruitment_num_;


public:

	Castle( int high_tier_army_num, int mid_tier_army_num, int low_tier_army_num, Status status, int high_tier_buildings_num,
		int mid_tier_buildings_num, int low_tier_buildings_num, int high_tier_recruitment_num,
		int mid_tier_recruitment_num, int low_tier_recruitment_num, int x, int y ) : GameObject(x, y),
		garrison_( high_tier_army_num, mid_tier_army_num, low_tier_army_num, x, y ), status_( status ),
		high_tier_buildings_num_( high_tier_buildings_num ), mid_tier_buildings_num_( mid_tier_buildings_num ),
		low_tier_buildings_num_( low_tier_buildings_num ), high_tier_recruitment_num_( high_tier_recruitment_num ),
		mid_tier_recruitment_num_( mid_tier_recruitment_num ), low_tier_recruitment_num_( low_tier_recruitment_num ) {}
	int defence_bonus(){ return (low_tier_buildings_num_*LOW_TIER_BUILDING_DEFENCE_BONUS +
		(mid_tier_buildings_num_*MID_TIER_BUILDING_DEFENCE_BONUS) + (high_tier_buildings_num_*HIGH_TIER_BUILDING_DEFENCE_BONUS) );
	}
	void build_low_tier(){ ++low_tier_buildings_num_; }
	void build_mid_tier(){ ++mid_tier_buildings_num_; }
	void build_high_tier(){ ++high_tier_buildings_num_; }

};

}//end namespace

#endif /* BOT_MODEL_CASTLE_HPP_ */
