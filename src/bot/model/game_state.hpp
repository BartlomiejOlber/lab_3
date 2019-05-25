/**
 * @file game_state.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy GameState
 */

#ifndef BOT_MODEL_GAME_STATE_HPP_
#define BOT_MODEL_GAME_STATE_HPP_

#include "hero.hpp"
#include "castle.hpp"
#include "guarded_building.hpp"
#include "gold.hpp"

namespace model {
//!  Struktura GameState.
/*!
  Struktura stanu gry w rozumieniu bota; zawiera wszystkie obiekty będące w rozgrywce.
*/
struct GameState {
	//! Składowa struktury; bohater bota klasy Hero.
	Hero my_hero;
	//! Składowa struktury; bohater przeciwnika klasy Hero.
	Hero enemy_hero;
	//! Składowa struktury; zamek bota klasy Castle.
	Castle my_castle;
	//! Składowa struktury; zamek przeciwnika klasy Castle.
	Castle enemy_castle;
	//! Składowa struktury; budynki na mapie jako wektor klasy Building.
	BuildingContainer buildings;
	//! Składowa struktury; strzeżone budynki na mapie jako wektor klasy GuardedBuilding.
	GuardedBuildingContainer guarded_buildings;
	//! Składowa struktury; złoto na mapie jako wektor klasy Gold.
	GoldContainer map_gold;
	//! Składowa struktury; oddziały na mapie jako wektor klasy Troop.
	TroopContainer map_troops;

};


}



#endif /* BOT_MODEL_GAME_STATE_HPP_ */
