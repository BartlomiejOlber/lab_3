/*
 * screen_capture.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_SCREEN_CAPTURE_HPP_
#define BOT_SCREEN_CAPTURE_HPP_

#include <vector>
#include <array>
#include "model/game_state.hpp"

namespace bot {

class ScreenCapture {

public:
	void capture_screen( model::GameState& );

private:
	void make_unique_coordinates_( std::vector<std::pair<int, int> >& coordinates, const std::pair<int, int>& map_size,
			int objects_number );
	void randomize_hero_( std::array<int,7>& hero_properties );
	void randomize_castle_( std::array<int,11>& castle_properties );
	void randomize_building_( std::array<int,4>& building_properties );
	void randomize_guarded_building_( std::array<int,6>&  guarded_building_properties );
	void randomize_gold_( std::array<int,3>& gold_properties );
	void randomize_troop_( std::array<int,4>& troop_properties );
	void randomize_map_size_( std::pair<int, int>& map_size );
	void randomize_map_objects_number_( const std::pair<int, int>& map_size, int& objects_number );
	void randomize_map_objects_types_( std::array<int,4>& object_types, int objects_number );

};

}



#endif /* BOT_SCREEN_CAPTURE_HPP_ */
