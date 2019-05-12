/*
 * game_state.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_GAME_STATE_HPP_
#define BOT_MODEL_GAME_STATE_HPP_

#include "hero.hpp"
#include "castle.hpp"
#include "guarded_building.hpp"
#include "gold.hpp"

namespace model {

class GameState {

	Hero my_hero_;
	Hero enemy_hero_;
	Castle my_castle_;
	Castle enemy_castle_;
	BuildingContainer buildings_;
	GuardedBuildingContainer guarded_buildings_;
	GoldContainer map_gold_;
	TroopContainer map_troops_;

};


}



#endif /* BOT_MODEL_GAME_STATE_HPP_ */
