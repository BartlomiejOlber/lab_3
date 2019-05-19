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

#include <iostream>
using namespace std;


namespace bot {

void ScreenCapture::capture_screen( model::GameState& game_state )
{
	MapSize map_size;
	randomize_map_size_( map_size );
	int objects_number;
	randomize_map_objects_number_( map_size, objects_number );
	AllCoordinates coordinates;
	make_unique_coordinates_( coordinates, map_size, objects_number );
	ObjectParameters object_types;
	randomize_map_objects_types_( object_types, objects_number );
	AllParameters all_params;
	make_all_parameters_( all_params, object_types );
	merge_coordinates_( all_params, coordinates );
	model::Castle my_castle( all_params.at(0).at(0), model::Status::FRIEND );
	model::Castle enemy_castle( all_params.at(0).at(1), model::Status::ENEMY );
	model::Hero my_hero( all_params.at(1).at(0), model::Status::FRIEND );
	model::Hero enemy_hero( all_params.at(1).at(1), model::Status::ENEMY );
	game_state.enemy_castle_ = enemy_castle;
	game_state.enemy_hero_ = enemy_hero;
	game_state.my_castle_ = my_castle;
	game_state.my_hero_ = my_hero;
	for( auto it = all_params.at(2).begin(); it != all_params.at(2).end(); ++it ){
		game_state.map_gold_.push_back( model::Gold( it->at(0), it->at(1), it->at(2) ) );
	}
	for( auto it = all_params.at(3).begin(); it != all_params.at(3).end(); ++it ){
		game_state.map_troops_.push_back( model::Troop( it->at(0), it->at(1), it->at(2), it->at(3) ) );
	}
	for( auto it = all_params.at(4).begin(); it != all_params.at(4).end(); ++it ){
		game_state.buildings_.push_back( model::Building( it->at(0), it->at(1), it->at(2), it->at(3) ) );
	}
	for( auto it = all_params.at(5).begin(); it != all_params.at(5).end(); ++it ){
		game_state.guarded_buildings_.push_back( model::GuardedBuilding( it->at(0), it->at(1), it->at(3), it->at(2),
			it->at(4), it->at(5)) );
	}
}

void ScreenCapture::make_all_parameters_( AllParameters& all_parameters, const ObjectParameters& object_types )
{
	ObjectParameters castle_properties, hero_properties, building_properties, guarded_building_properties,
		gold_properties, troop_properties;
	OneTypeParameters castles_properties, heros_properties, buildings_properties, guarded_buildings_properties,
		golds_properties, troops_properties;
	for( int i = 0; i<2; ++i ){
		randomize_castle_( castle_properties );
		castles_properties.push_back( castle_properties );
		castle_properties.clear();
	}
	for( int i = 0; i<2; ++i ){
		randomize_hero_( hero_properties );
		heros_properties.push_back( hero_properties );
		hero_properties.clear();
	}
	for( int i = 0; i<object_types.at(0); ++i ){
		randomize_troop_( troop_properties );
		troops_properties.push_back( troop_properties );
		troop_properties.clear();
	}
	for( int i = 0; i<object_types.at(1); ++i ){
		randomize_gold_( gold_properties );
		golds_properties.push_back( gold_properties );
		gold_properties.clear();
	}
	for( int i = 0; i<object_types.at(2); ++i ){
		randomize_building_( building_properties );
		buildings_properties.push_back( building_properties );
		building_properties.clear();
	}
	for( int i = 0; i<object_types.at(3); ++i ){
		randomize_guarded_building_( guarded_building_properties );
		guarded_buildings_properties.push_back( guarded_building_properties );
		guarded_building_properties.clear();
	}
	all_parameters.push_back( castles_properties );
	all_parameters.push_back( heros_properties );
	all_parameters.push_back( golds_properties );
	all_parameters.push_back( troops_properties );
	all_parameters.push_back( buildings_properties );
	all_parameters.push_back( guarded_buildings_properties );
}

void ScreenCapture::merge_coordinates_( AllParameters& all_parameters, const AllCoordinates& coordinates )
{
	auto it_coordinates = coordinates.begin();
	for( int i = 0; i<6; ++i){
		for( auto it = all_parameters.at(i).begin(); it!=all_parameters.at(i).end(); ++it ){
		it->push_back( it_coordinates->first );
		it->push_back( it_coordinates->second );
		++it_coordinates;
		}
	}
}
void ScreenCapture::make_unique_coordinates_( AllCoordinates& coordinates,
		const MapSize& map_size,  int objects_number  )
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

void ScreenCapture::randomize_hero_( ObjectParameters& hero_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> high_tier_troop_quantity(0,30);
    std::uniform_int_distribution<std::mt19937::result_type> mid_tier_troop_quantity(0,150);
    std::uniform_int_distribution<std::mt19937::result_type> low_tier_troop_quantity(0,500);
    std::uniform_int_distribution<std::mt19937::result_type> gold_quantity(0,1000);
    std::uniform_int_distribution<std::mt19937::result_type> level(1,25);
    hero_properties.push_back( gold_quantity(rng)*100 );
    hero_properties.push_back(level(rng));
    hero_properties.push_back(high_tier_troop_quantity(rng));
    hero_properties.push_back(mid_tier_troop_quantity(rng));
    hero_properties.push_back(low_tier_troop_quantity(rng));
}

void ScreenCapture::randomize_castle_( ObjectParameters& castle_properties )
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
    castle_properties.push_back( high_tier_troop_quantity(rng) );
    castle_properties.push_back( mid_tier_troop_quantity(rng) );
    castle_properties.push_back( low_tier_troop_quantity(rng) );
    castle_properties.push_back( high_tier_buildings_number(rng) );
    castle_properties.push_back( mid_tier_buildings_number(rng) );
    castle_properties.push_back( low_tier_buildings_number(rng) );
    castle_properties.push_back( high_tier_troop_recruitment(rng) );
    castle_properties.push_back( mid_tier_troop_recruitment(rng) );
    castle_properties.push_back( low_tier_troop_recruitment(rng) );
}

void ScreenCapture::randomize_building_( ObjectParameters& building_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> tier(0,2);
    building_properties.push_back( tier(rng) );
    building_properties.push_back( tier(rng) );
}

void ScreenCapture::randomize_guarded_building_( ObjectParameters& guarded_building_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> troop_quantity(0,200);
    std::uniform_int_distribution<std::mt19937::result_type> tier(0,2);
    guarded_building_properties.push_back( tier(rng) );
    guarded_building_properties.push_back( tier(rng) );
    guarded_building_properties.push_back( tier(rng) );
    guarded_building_properties.push_back( troop_quantity(rng) );

}

void ScreenCapture::randomize_gold_( ObjectParameters& gold_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> gold_quantity(1,10);
    gold_properties.push_back( gold_quantity(rng)*100 );
}

void ScreenCapture::randomize_troop_( ObjectParameters& troop_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> troop_quantity(5,200);
    std::uniform_int_distribution<std::mt19937::result_type> troop_tier(0,2);
    troop_properties.push_back(troop_quantity(rng));
    troop_properties.push_back(troop_tier(rng));

}

void ScreenCapture::randomize_map_size_( MapSize& map_size )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> map_measurements(100,200);
    map_size.first = map_measurements(rng);
    map_size.second = map_measurements(rng);
}

void ScreenCapture::randomize_map_objects_number_( const MapSize& map_size, int& objects_number )
{
	int max = (map_size.first * map_size.second)/ 30;
	int min = 100;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> objects_number_( min, max);
	objects_number = objects_number_(rng);
}

void ScreenCapture::randomize_map_objects_types_( ObjectParameters& object_types, int objects_number )
{
	objects_number -= 4;
	int tmp;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> troops_number( 5, objects_number/4 );
	tmp = troops_number(rng);
	object_types.push_back(tmp); //troops number
	objects_number -= tmp;
	std::uniform_int_distribution<std::mt19937::result_type> all_buildings_number( 10,  objects_number/2 );
	tmp = all_buildings_number(rng);
	objects_number -= tmp;
	object_types.push_back(objects_number); //gold number
	std::uniform_int_distribution<std::mt19937::result_type> buildings_number( 10,  tmp );
	objects_number = tmp;
	tmp = buildings_number(rng);
	object_types.push_back(tmp); //buildings number
	object_types.push_back( (objects_number - tmp) ); //guardedbuildings number
}

}


