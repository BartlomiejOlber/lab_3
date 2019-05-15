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

	typedef std::vector<std::vector <std::vector<int> > > AllParameters;
	typedef std::vector<std::vector<int> > OneTypeParameters;
	typedef std::vector<std::pair<int, int> > AllCoordinates;
	typedef std::pair<int, int> MapSize;
	typedef std::vector<int> ObjectParameters;

public:
	void capture_screen( model::GameState& );

private:
	void make_all_parameters_( AllParameters& all_parameters, const ObjectParameters& object_types );
	void merge_coordinates_( AllParameters& all_parameters, const AllCoordinates& coordinates );
	void make_unique_coordinates_( AllCoordinates& coordinates, const MapSize& map_size,
		int objects_number );
	void randomize_hero_( ObjectParameters& hero_properties );
	void randomize_castle_( ObjectParameters& castle_properties );
	void randomize_building_( ObjectParameters& building_properties );
	void randomize_guarded_building_( ObjectParameters&  guarded_building_properties );
	void randomize_gold_( ObjectParameters& gold_properties );
	void randomize_troop_( ObjectParameters& troop_properties );
	void randomize_map_size_( MapSize& map_size );
	void randomize_map_objects_number_( const MapSize& map_size, int& objects_number );
	void randomize_map_objects_types_( ObjectParameters& object_types, int objects_number );
};

}



#endif /* BOT_SCREEN_CAPTURE_HPP_ */
