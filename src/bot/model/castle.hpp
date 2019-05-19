/*
 * castle.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_CASTLE_HPP_
#define BOT_MODEL_CASTLE_HPP_

#include <vector>
#include <iostream>
#include "army.hpp"
#include "building.hpp"

namespace model {

class Castle : public GameObject {

public:

static const int LOW_TIER_BUILDING_COST = 1000;
static const int MID_TIER_BUILDING_COST = 4000;
static const int HIGH_TIER_BUILDING_COST = 15000;
static const int LOW_TIER_ENTITY_COST = 100;
static const int MID_TIER_ENTITY_COST = 400;
static const int HIGH_TIER_ENTITY_COST = 2000;
static const int MAX_HIGH_TIER_BUILDINGS = 3;
static const int MAX_MID_TIER_BUILDINGS = 5;
static const int MAX_LOW_TIER_BUILDINGS = 10;
static constexpr double LOW_TIER_BUILDING_DEFENCE_BONUS = 0.01;
static constexpr double MID_TIER_BUILDING_DEFENCE_BONUS = 0.02;
static constexpr double HIGH_TIER_BUILDING_DEFENCE_BONUS = 0.05;

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

	Castle( int high_tier_army_num = 0, int mid_tier_army_num = 0, int low_tier_army_num = 0, Status status = Status::NEUTRAL,
		int high_tier_buildings_num  = 0, int mid_tier_buildings_num = 0, int low_tier_buildings_num = 0,
		int high_tier_recruitment_num = 0, int mid_tier_recruitment_num = 0, int low_tier_recruitment_num = 0, int x = 0,
		int y = 0 ) : GameObject(x, y), garrison_( high_tier_army_num, mid_tier_army_num, low_tier_army_num, x, y ),
		status_( status ), high_tier_buildings_num_( high_tier_buildings_num ),
		mid_tier_buildings_num_( mid_tier_buildings_num ), low_tier_buildings_num_( low_tier_buildings_num ),
		high_tier_recruitment_num_( high_tier_recruitment_num ), mid_tier_recruitment_num_( mid_tier_recruitment_num ),
		low_tier_recruitment_num_( low_tier_recruitment_num ) {}
	Castle( const std::vector<int>& params, Status status ) : GameObject(params[9], params[10]),
		garrison_( params[0], params[1], params[2], params[9], params[10] ), status_( status ),
		high_tier_buildings_num_( params[3] ), mid_tier_buildings_num_( params[4] ),
		low_tier_buildings_num_( params[5] ), high_tier_recruitment_num_( params[6] ),
		mid_tier_recruitment_num_( params[7] ), low_tier_recruitment_num_( params[8] ) {}
	double defence_bonus() const { return (low_tier_buildings_num_*LOW_TIER_BUILDING_DEFENCE_BONUS +
		(mid_tier_buildings_num_*MID_TIER_BUILDING_DEFENCE_BONUS) + (high_tier_buildings_num_*HIGH_TIER_BUILDING_DEFENCE_BONUS) );
	}
	void build_low_tier(){ ++low_tier_buildings_num_; }
	void build_mid_tier(){ ++mid_tier_buildings_num_; }
	void build_high_tier(){ ++high_tier_buildings_num_; }
	void recruit_high_tier( int quantity ){ high_tier_recruitment_num_-=quantity; garrison_.recruit_high_tier( quantity ); }
	void recruit_mid_tier( int quantity ){ mid_tier_recruitment_num_-=quantity; garrison_.recruit_mid_tier( quantity ); }
	void recruit_low_tier( int quantity ){ low_tier_recruitment_num_-=quantity; garrison_.recruit_low_tier( quantity ); }
	int get_high_tier_recruitment_num() const { return high_tier_recruitment_num_; }
	int get_mid_tier_recruitment_num() const { return mid_tier_recruitment_num_; }
	int get_low_tier_recruitment_num() const { return low_tier_recruitment_num_; }
	bool is_development_available_high() const { return high_tier_buildings_num_<MAX_HIGH_TIER_BUILDINGS ? true : false; }
	bool is_development_available_mid() const { return mid_tier_buildings_num_<MAX_MID_TIER_BUILDINGS ? true : false; }
	bool is_development_available_low() const { return low_tier_buildings_num_<MAX_LOW_TIER_BUILDINGS ? true : false; }
	int count_castle_force() const {  return garrison_.count_army_force() * defence_bonus(); }
	void conquer(){ garrison_.vanish(); status_ = Status::FRIEND; }

	void print(){ std::cout << garrison_.get_high_tier_quantity()<< " "<< garrison_.get_low_tier_quantity()<< " "<<
		garrison_.get_mid_tier_quantity() << " status: "<< static_cast<int>(status_); }

};

}//end namespace

#endif /* BOT_MODEL_CASTLE_HPP_ */
