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
#include "model/travel_to_action.hpp"
#include "model/enter_action.hpp"
#include "model/pick_up_action.hpp"
#include "model/fight_action.hpp"

namespace brain {

void Brain::play_round( model::ActionScenario& action_scenario )
{
	make_hero_actions_( action_scenario );
	make_castle_actions_( action_scenario );
}

void Brain::make_castle_actions_( model::ActionScenario& action_scenario )
{
	int gold_available = game_state_.my_hero_.get_gold();
	int available_to_buy;
	if( game_state_.enemy_hero_.get_movement_points() * MINIMAL_ENEMY_DISTANCE_FACTOR_ >=
		game_state_.enemy_hero_.get_distance( game_state_.my_castle_ ) ){
		if( gold_available > model::Castle::HIGH_TIER_ENTITY_COST ){
			available_to_buy = count_available_to_buy_( gold_available, model::Castle::HIGH_TIER_ENTITY_COST,
				game_state_.my_castle_.get_high_tier_recruitment_num());
			action_scenario.push_back( std::unique_ptr<model::RecruitHighTierAction>( new model::RecruitHighTierAction(game_state_.my_castle_ )));
			game_state_.my_castle_.recruit_high_tier( available_to_buy );
			gold_available -= available_to_buy * model::Castle::HIGH_TIER_BUILDING_COST;
			if( gold_available > model::Castle::MID_TIER_ENTITY_COST ){
				available_to_buy = count_available_to_buy_( gold_available, model::Castle::MID_TIER_ENTITY_COST,
					game_state_.my_castle_.get_mid_tier_recruitment_num());
				action_scenario.push_back( std::unique_ptr<model::RecruitMidTierAction>( new model::RecruitMidTierAction(game_state_.my_castle_ )));
				game_state_.my_castle_.recruit_mid_tier( available_to_buy );
				gold_available -= available_to_buy * model::Castle::MID_TIER_BUILDING_COST;
				if( gold_available > model::Castle::LOW_TIER_ENTITY_COST ){
					available_to_buy = count_available_to_buy_( gold_available, model::Castle::LOW_TIER_ENTITY_COST,
						game_state_.my_castle_.get_low_tier_recruitment_num());
					action_scenario.push_back( std::unique_ptr<model::RecruitLowTierAction>( new model::RecruitLowTierAction(game_state_.my_castle_ )));
					game_state_.my_castle_.recruit_low_tier( available_to_buy );
					gold_available -= available_to_buy * model::Castle::LOW_TIER_BUILDING_COST;
					if( gold_available > model::Castle::HIGH_TIER_BUILDING_COST ){
						gold_available -= model::Castle::HIGH_TIER_BUILDING_COST;
						action_scenario.push_back( std::unique_ptr<model::BuildHighTierAction>( new model::BuildHighTierAction(game_state_.my_castle_ )));
					}else if( gold_available > model::Castle::MID_TIER_BUILDING_COST ){
						gold_available -= model::Castle::MID_TIER_BUILDING_COST;
						action_scenario.push_back( std::unique_ptr<model::BuildMidTierAction>( new model::BuildMidTierAction(game_state_.my_castle_ )) );
					}else if( gold_available > model::Castle::LOW_TIER_BUILDING_COST ){
						gold_available -= model::Castle::LOW_TIER_BUILDING_COST;
						action_scenario.push_back( std::unique_ptr<model::BuildLowTierAction>( new model::BuildLowTierAction(game_state_.my_castle_ )));
					}
				}
			}
		}else if( gold_available > model::Castle::MID_TIER_ENTITY_COST ){
			available_to_buy = count_available_to_buy_( gold_available, model::Castle::MID_TIER_ENTITY_COST,
				game_state_.my_castle_.get_mid_tier_recruitment_num());
			action_scenario.push_back( std::unique_ptr<model::RecruitMidTierAction>( new model::RecruitMidTierAction(game_state_.my_castle_ )));
			game_state_.my_castle_.recruit_mid_tier( available_to_buy );
			gold_available -= available_to_buy * model::Castle::MID_TIER_BUILDING_COST;
		}
	}else if( gold_available > model::Castle::HIGH_TIER_BUILDING_COST ){
		action_scenario.push_back( std::unique_ptr<model::BuildHighTierAction>( new model::BuildHighTierAction(game_state_.my_castle_ )));
	}else if( gold_available > model::Castle::MID_TIER_BUILDING_COST ){
		action_scenario.push_back( std::unique_ptr<model::BuildMidTierAction>( new model::BuildMidTierAction(game_state_.my_castle_ )));
	}else if( gold_available > model::Castle::LOW_TIER_BUILDING_COST ){
		action_scenario.push_back( std::unique_ptr<model::BuildLowTierAction>( new model::BuildLowTierAction(game_state_.my_castle_ )));
	}
}

void Brain::make_hero_actions_( model::ActionScenario& action_scenario )
{
	int movement_remaining = game_state_.my_hero_.get_movement_points();
	if( is_reachable_( movement_remaining, game_state_.enemy_hero_ ) &&
			is_attack_worth_( game_state_.enemy_hero_ )){
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(game_state_.enemy_hero_)));
		action_scenario.push_back( std::unique_ptr<model::FightAction>( new model::FightAction(game_state_.enemy_hero_)));
		movement_remaining -= game_state_.my_hero_.get_distance( game_state_.enemy_hero_ );
		game_state_.my_hero_.kill( count_battle_casualties_( game_state_.enemy_hero_.count_hero_force()));
		game_state_.my_hero_.travel_to( game_state_.enemy_hero_ );
		game_state_.enemy_hero_.kill();
	}
	if( is_reachable_( movement_remaining, game_state_.enemy_castle_ ) &&
			is_attack_worth_( game_state_.enemy_castle_ )){
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(game_state_.enemy_castle_)));
		action_scenario.push_back( std::unique_ptr<model::FightAction>( new model::FightAction(game_state_.enemy_castle_)));
		movement_remaining -= game_state_.my_hero_.get_distance( game_state_.enemy_castle_ );
		game_state_.my_hero_.kill( count_battle_casualties_( game_state_.enemy_castle_.count_castle_force()));
		game_state_.my_hero_.travel_to( game_state_.enemy_castle_ );
		game_state_.enemy_castle_.conquer();
	}
	model::GuardedBuilding closest_guarded_building;
	find_closest_guarded_building_( closest_guarded_building );
	if( is_reachable_( movement_remaining, closest_guarded_building ) &&
			is_attack_worth_( closest_guarded_building )){
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(closest_guarded_building)));
		action_scenario.push_back( std::unique_ptr<model::FightAction>( new model::FightAction(closest_guarded_building)));
		action_scenario.push_back( std::unique_ptr<model::EnterAction>( new model::EnterAction(closest_guarded_building)));
		movement_remaining -= game_state_.my_hero_.get_distance( closest_guarded_building );
		game_state_.my_hero_.kill( count_battle_casualties_( closest_guarded_building.count_guards_force()));
		game_state_.my_hero_.travel_to( closest_guarded_building );
		closest_guarded_building.conquer();
	}
	model::Building closest_building;
	find_closest_building_( closest_building );
	if( is_reachable_( movement_remaining, closest_building )){
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(closest_building)));
		action_scenario.push_back( std::unique_ptr<model::EnterAction>( new model::EnterAction(closest_building)));
		movement_remaining -= game_state_.my_hero_.get_distance( closest_building );
		game_state_.my_hero_.travel_to( closest_building );
		closest_building.take_control();
	}
	int index;
	model::Gold closest_gold;
	find_closest_gold_( index, closest_gold );
	if( is_reachable_( movement_remaining, closest_gold )){
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(closest_gold)));
		action_scenario.push_back( std::unique_ptr<model::PickUpAction>( new model::PickUpAction(closest_gold)));
		movement_remaining -= game_state_.my_hero_.get_distance( closest_gold );
		game_state_.my_hero_.travel_to( closest_gold );
		game_state_.my_hero_.pick_up_gold( closest_gold.get_quantity());
		game_state_.map_gold_.erase( game_state_.map_gold_.begin()+index );
	}
	model::Troop closest_troop;
	find_closest_troop_( index, closest_troop );
	if( is_reachable_( movement_remaining, closest_troop )){
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(closest_troop)));
		action_scenario.push_back( std::unique_ptr<model::FightAction>( new model::FightAction(closest_troop)));
		movement_remaining -= game_state_.my_hero_.get_distance( closest_troop );
		game_state_.my_hero_.travel_to( closest_troop );
		game_state_.my_hero_.kill( count_battle_casualties_( closest_troop.count_troop_force()));
		game_state_.map_troops_.erase( game_state_.map_troops_.begin()+index );
	}
	if( movement_remaining > 0){
		model::GameObject enemy_castle_direction;
		find_enemy_castle_direction_( movement_remaining, enemy_castle_direction );
		action_scenario.push_back( std::unique_ptr<model::TravelToAction>( new model::TravelToAction(enemy_castle_direction)));
		game_state_.my_hero_.travel_to( enemy_castle_direction );
	}

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

int Brain::count_available_to_buy_( int gold, int cost, int limit )
{
	return  gold/cost < limit? gold/cost : limit;
}

void Brain::find_closest_guarded_building_( model::GuardedBuilding& guarded_building )
{
	if( !game_state_.guarded_buildings_.empty() ){
		int idx = 0;
		int i = 0;
		for( auto it = game_state_.guarded_buildings_.begin(); it != game_state_.guarded_buildings_.end(); ++it, ++i ){
			if( game_state_.my_hero_.get_distance( *it ) < game_state_.my_hero_.get_distance( game_state_.guarded_buildings_.at(idx)) &&
				it->get_status() != model::Status::FRIEND )
				idx = i;
		}
		guarded_building = game_state_.guarded_buildings_.at( idx );
	}
}

void Brain::find_closest_building_( model::Building& building )
{
	if( !game_state_.buildings_.empty() ){
		int idx = 0;
		int i = 0;
		for( auto it = game_state_.buildings_.begin(); it != game_state_.buildings_.end(); ++it, ++i ){
			if( game_state_.my_hero_.get_distance( *it ) < game_state_.my_hero_.get_distance( game_state_.buildings_.at( idx )) &&
				it->get_status() != model::Status::FRIEND )
				idx = i;
		}
		building = game_state_.buildings_.at( idx );
	}
}

void Brain::find_closest_gold_( int& index, model::Gold& gold )
{
	if( !game_state_.map_gold_.empty() ){
		int idx = 0;
		int i = 0;
		for( auto it = game_state_.map_gold_.begin(); it != game_state_.map_gold_.end(); ++it, ++i ){
			if( game_state_.my_hero_.get_distance( *it ) < game_state_.my_hero_.get_distance( game_state_.map_gold_.at( idx ) ) )
				idx = i;
		}
		index = idx;
		gold = game_state_.map_gold_.at( idx );
	}
}

void Brain::find_closest_troop_( int& index, model::Troop& troop )
{
	if( !game_state_.map_troops_.empty() ){
		int idx = 0;
		int i = 0;
		for( auto it = game_state_.map_troops_.begin(); it != game_state_.map_troops_.end(); ++it, ++i ){
			if( game_state_.my_hero_.get_distance( *it ) < game_state_.my_hero_.get_distance( game_state_.map_troops_.at( idx ) ) )
				idx = i;
		}
		index = idx;
		troop = game_state_.map_troops_.at( idx );
	}

}

void Brain::find_enemy_castle_direction_( int movement_points, model::GameObject& direction )
{
	int x =  game_state_.enemy_castle_.get_x() - game_state_.my_hero_.get_x();
	int y =  game_state_.enemy_castle_.get_y() - game_state_.my_hero_.get_y();
	double distance = sqrt( pow( x, 2 ) +pow( y, 2 ) );
	if( distance ){
		direction.set_coordinates( game_state_.my_hero_.get_x() + x*(movement_points/distance),
				game_state_.my_hero_.get_y() + y*(movement_points/distance ) );
	}else{
		direction.set_coordinates( game_state_.enemy_castle_.get_x(), game_state_.enemy_castle_.get_y() );
	}

}

bool Brain::is_reachable_( int movement_points, const model::GameObject& object )
{
	return movement_points >= game_state_.my_hero_.get_distance( object )  ? true : false;
}


}
