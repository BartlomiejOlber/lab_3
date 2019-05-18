/*
 * brain.cpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#include "brain.hpp"
#include "model/recruit_high_tier_action.hpp"
#include "model/recruit_mid_tier_action.hpp"
#include "model/recruit_low_tier_action.hpp"
#include "model/build_high_tier_action.hpp"
#include "model/build_mid_tier_action.hpp"
#include "model/build_low_tier_action.hpp"

namespace brain {

void Brain::play_round( model::ActionScenario& action_scenario )
{



}

void Brain::make_castle_actions_( model::ActionScenario& action_scenario )
{
	int gold_available = game_state_.my_hero_.get_gold();
	if( game_state_.enemy_hero_.get_movement_points() * MINIMAL_ENEMY_DISTANCE_FACTOR_ <=
		game_state_.enemy_hero_.get_distance( game_state_.my_castle_ ) ){
		if( gold_available > model::Castle::HIGH_TIER_ENTITY_COST ){
			action_scenario.push_back( model::RecruitHighTierAction( game_state_.my_castle_ )  );
			gold_available -= game_state_.my_castle_.get_high_tier_recruitment_num() * model::Castle::HIGH_TIER_BUILDING_COST;
			if( gold_available > model::Castle::MID_TIER_ENTITY_COST ){
				action_scenario.push_back( model::RecruitMidTierAction( game_state_.my_castle_ )  );
				gold_available -= game_state_.my_castle_.get_mid_tier_recruitment_num()* model::Castle::MID_TIER_BUILDING_COST;
				if( gold_available > model::Castle::LOW_TIER_ENTITY_COST ){
					action_scenario.push_back( model::RecruitLowTierAction( game_state_.my_castle_ )  );
					gold_available -= game_state_.my_castle_.get_low_tier_recruitment_num()*
						model::Castle::LOW_TIER_BUILDING_COST;
					if( gold_available > model::Castle::HIGH_TIER_BUILDING_COST ){
						action_scenario.push_back( model::BuildHighTierAction( game_state_.my_castle_ )  );
					}else if( gold_available > model::Castle::MID_TIER_BUILDING_COST ){
						action_scenario.push_back( model::BuildMidTierAction( game_state_.my_castle_ ) );
					}else if( gold_available > model::Castle::LOW_TIER_BUILDING_COST ){
						action_scenario.push_back( model::BuildLowTierAction( game_state_.my_castle_ ) );
					}
				}
			}
		}else if( gold_available > model::Castle::MID_TIER_ENTITY_COST ){
			action_scenario.push_back( model::RecruitMidTierAction( game_state_.my_castle_ )  );
		}
	}else if( gold_available > model::Castle::HIGH_TIER_BUILDING_COST ){
		action_scenario.push_back( model::BuildHighTierAction( game_state_.my_castle_ )  );
	}
}

void Brain::make_hero_actions_( model::ActionScenario& action_scenario )
{

}

bool Brain::is_attack_worth_( const model::Troop& troop )
{
	return game_state_.my_hero_.count_hero_force() > troop.count_troop_force() &&
		count_battle_casualties_( troop.count_troop_force() ) <= game_state_.my_hero_.count_hero_force() *
		MAXIMAL_CASUALTIES_FACTOR_  ? true : false;
}

bool Brain::is_attack_worth_( const model::Castle& enemy_castle )
{
	return game_state_.my_hero_.count_hero_force() >= enemy_castle.count_castle_force()*MINIMAL_DOMINANCE_FACTOR_ ?
		true : false;
}

bool Brain::is_attack_worth_( const model::Hero& enemy_hero )
{
	return game_state_.my_hero_.count_hero_force() >= enemy_hero.count_hero_force() * MINIMAL_DOMINANCE_FACTOR_ ?
		true : false;
}

bool Brain::is_attack_worth_( const model::GuardedBuilding& guarded_building )
{
	return game_state_.my_hero_.count_hero_force() > guarded_building.count_guards_force() &&
		count_battle_casualties_( guarded_building.count_guards_force() ) <= game_state_.my_hero_.count_hero_force() *
		MAXIMAL_CASUALTIES_FACTOR_  ? true : false;
}

int Brain::count_battle_casualties_( int opponent_force )
{
	return opponent_force * ( 1.00 -( (double)game_state_.my_hero_.count_hero_force() /
			opponent_force * CASUALTIES_FACTOR_ ) + opponent_force * MINIMAL_CASUALTIES_FACTOR_ );
}




}
