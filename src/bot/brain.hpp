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
};

}



#endif /* BOT_BRAIN_HPP_ */
