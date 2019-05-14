/*
 * screen_capture.cpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#include <random>
#include <algorithm>
#include "model/castle.hpp"
#include "screen_capture.hpp"
#include "model/status.hpp"

namespace bot {

void ScreenCapture::capture_screen( model::GameState& game_state )
{
	std::pair<int, int> map_size;
	randomize_map_size_( map_size );
	int objects_number;
	randomize_map_objects_number_( map_size, objects_number );
	std::vector<std::pair<int, int> > coordinates;
	make_unique_coordinates_( coordinates, map_size, objects_number );
	std::array<int,4> object_types;
	randomize_map_objects_types_( object_types, objects_number );
	std::array<int,11> castle_properties;
	randomize_castle_( castle_properties );
	auto it=coordinates.begin();
	castle_properties[9] = it->first;
	castle_properties[10] = it->second;
	model::Castle my_castle( castle_properties, model::Status::FRIEND );
	game_state.my_castle_ = my_castle;
	randomize_castle_( castle_properties );
	++it;
	castle_properties[9] = it->first;
	castle_properties[10] = it->second;
	model::Castle enemy_castle( castle_properties, model::Status::ENEMY );
	game_state.enemy_castle_ = enemy_castle;
}

void ScreenCapture::make_unique_coordinates_( std::vector<std::pair<int, int> >& coordinates,
		const std::pair<int, int>& map_size,  int objects_number  )
{
	int width = map_size.first;
	int height = map_size.second;
	int coordinates_generated = 0;
    std::random_device dev;
    std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> coordinate_x(0,width);
	std::uniform_int_distribution<std::mt19937::result_type> coordinate_y(0,height);
	std::pair<int,int> tmp;
    while( coordinates_generated < objects_number ){
		tmp.first = coordinate_x(rng);
		tmp.second = coordinate_y(rng);
        if( !(std::find( coordinates.begin(), coordinates.end(), tmp) != coordinates.end() ) ) {
        	coordinates.push_back( tmp );
			++coordinates_generated;
        }
    }
}

void ScreenCapture::randomize_hero_( std::array<int,7>& hero_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> high_tier_troop_quantity(0,30);
    std::uniform_int_distribution<std::mt19937::result_type> mid_tier_troop_quantity(0,150);
    std::uniform_int_distribution<std::mt19937::result_type> low_tier_troop_quantity(0,500);
    std::uniform_int_distribution<std::mt19937::result_type> gold_quantity(0,500);
    std::uniform_int_distribution<std::mt19937::result_type> level(1,25);
    hero_properties[0] = gold_quantity(rng)*100;
    hero_properties[1] = level(rng);
    hero_properties[2] = high_tier_troop_quantity(rng);
    hero_properties[3] = mid_tier_troop_quantity(rng);
    hero_properties[4] = low_tier_troop_quantity(rng);
}

void ScreenCapture::randomize_castle_( std::array<int,11>& castle_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> high_tier_troop_quantity(0,30);
    std::uniform_int_distribution<std::mt19937::result_type> mid_tier_troop_quantity(0,150);
    std::uniform_int_distribution<std::mt19937::result_type> low_tier_troop_quantity(0,500);
    std::uniform_int_distribution<std::mt19937::result_type> high_tier_troop_recruitment(0,5);
    std::uniform_int_distribution<std::mt19937::result_type> mid_tier_troop_recruitment(0,30);
    std::uniform_int_distribution<std::mt19937::result_type> low_tier_troop_recruitment(0,100);
    std::uniform_int_distribution<std::mt19937::result_type> high_tier_buildings_number(0,3);
    std::uniform_int_distribution<std::mt19937::result_type> mid_tier_buildings_number(0,5);
    std::uniform_int_distribution<std::mt19937::result_type> low_tier_buildings_number(1,10);
    castle_properties[0] = high_tier_troop_quantity(rng);
    castle_properties[1] = mid_tier_troop_quantity(rng);
    castle_properties[2] = low_tier_troop_quantity(rng);
    castle_properties[3] = high_tier_buildings_number(rng);
    castle_properties[4] = mid_tier_buildings_number(rng);
    castle_properties[5] = low_tier_buildings_number(rng);
    castle_properties[6] = high_tier_troop_recruitment(rng);
    castle_properties[7] = mid_tier_troop_recruitment(rng);
    castle_properties[8] = low_tier_troop_recruitment(rng);
}

void ScreenCapture::randomize_building_( std::array<int,4>& building_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> tier(0,2);
    building_properties[0] = tier(rng);
    building_properties[1] = tier(rng);
}

void ScreenCapture::randomize_guarded_building_( std::array<int,6>& guarded_building_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> troop_quantity(0,200);
    std::uniform_int_distribution<std::mt19937::result_type> tier(0,2);
    guarded_building_properties[0] = tier(rng);
    guarded_building_properties[1] = tier(rng);
    guarded_building_properties[2] = tier(rng);
    guarded_building_properties[3] = troop_quantity(rng);

}

void ScreenCapture::randomize_gold_( std::array<int,3>& gold_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> gold_quantity(1,10);
    gold_properties[0] = gold_quantity(rng)*100;
}

void ScreenCapture::randomize_troop_( std::array<int,4>& troop_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> troop_quantity(5,200);
    std::uniform_int_distribution<std::mt19937::result_type> troop_tier(0,2);
    troop_properties[0] = troop_quantity(rng);
    troop_properties[1] = troop_tier(rng);

}

void ScreenCapture::randomize_map_size_( std::pair<int, int>& map_size )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> map_measurements(100,200);
    map_size.first = map_measurements(rng);
    map_size.second = map_measurements(rng);
}

void ScreenCapture::randomize_map_objects_number_( const std::pair<int, int>& map_size, int& objects_number )
{
	int max = (map_size.first * map_size.second)/ 30;
	int min = 100;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> objects_number_( min, max);
	objects_number = objects_number_(rng);
}

void ScreenCapture::randomize_map_objects_types_( std::array<int,4>& object_types, int objects_number )
{
	objects_number -= 4;
	int tmp;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> troops_number( 5, objects_number/4 );
	tmp = troops_number(rng);
	object_types[0] = tmp;
	objects_number -= tmp;
	std::uniform_int_distribution<std::mt19937::result_type> all_buildings_number( 10,  objects_number/2 );
	tmp = all_buildings_number(rng);
	objects_number -= tmp;
	object_types[3] = objects_number;
	std::uniform_int_distribution<std::mt19937::result_type> buildings_number( 10,  tmp );
	objects_number = tmp;
	tmp = buildings_number(rng);
	object_types[1] = tmp;
	object_types[2] = (objects_number - tmp);
}

}


