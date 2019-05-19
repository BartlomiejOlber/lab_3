/*
 * brain.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_BRAIN_HPP_
#define BOT_BRAIN_HPP_


#include "model/game_state.hpp"
#include "model/action.hpp"

namespace brain {

class Brain {

	model::GameState game_state_;

public:
	explicit Brain( const model::GameState& game_state ) : game_state_( game_state ){}
	void play_round( model::ActionScenario& action_scenario );
	void set_start_state( const model::GameState& game_state ){ game_state_ = game_state; }
	const model::GameState& get_final_game_state() const { return game_state_; }

private:
	static constexpr double CASUALTIES_FACTOR_ = 0.4;
	static constexpr double MINIMAL_CASUALTIES_FACTOR_ = 0.1;
	static constexpr double MINIMAL_DOMINANCE_FACTOR_ = 1.1;
	static constexpr double MAXIMAL_CASUALTIES_FACTOR_ = 0.05;
	static const int MINIMAL_ENEMY_DISTANCE_FACTOR_ = 2;

	void make_hero_actions_( model::ActionScenario& action_scenario );
	void make_castle_actions_( model::ActionScenario& action_scenario );
	bool is_attack_worth_( const model::Troop& troop );
	bool is_attack_worth_( const model::Castle& enemy_castle );
	bool is_attack_worth_( const model::Hero& enemy_hero );
	bool is_attack_worth_( const model::GuardedBuilding& guarded_building );
	int count_battle_casualties_( int opponent_force );
	int count_available_to_buy_( int gold, int cost, int limit );
	void find_closest_guarded_building_( model::GuardedBuilding& guarded_building );
	void find_closest_building_( model::Building& building );
	void find_closest_gold_( int& index, model::Gold& gold );
	void find_closest_troop_( int& index, model::Troop& troop );
	void find_enemy_castle_direction_( int movement_points, model::GameObject& direction );

};

}



#endif /* BOT_BRAIN_HPP_ */
