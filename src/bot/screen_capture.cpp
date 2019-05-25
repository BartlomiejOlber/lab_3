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
	randomize_map_size_( map_size ); //wylosuj rozmiary mapy
	int objects_number;
	randomize_map_objects_number_( map_size, objects_number ); // wylosuj liczbę obiektów
	AllCoordinates coordinates;
	make_unique_coordinates_( coordinates, map_size, objects_number ); //zrób niepowtarzalne współrzędne
	ObjectParameters object_types;
	randomize_map_objects_types_( object_types, objects_number ); // wylosuj liczbę obiektów każdego typu
	AllParameters all_params;
	make_all_parameters_( all_params, object_types ); //wygeneruj wszystkie parametry
	merge_coordinates_( all_params, coordinates ); //scal je z współrzędnymi
	model::Castle my_castle( all_params.at(0).at(0), model::Status::FRIEND ); //kostruktory zamków i bohaterów
	model::Castle enemy_castle( all_params.at(0).at(1), model::Status::ENEMY );
	model::Hero my_hero( all_params.at(1).at(0), model::Status::FRIEND );
	model::Hero enemy_hero( all_params.at(1).at(1), model::Status::ENEMY );
	game_state.enemy_castle = enemy_castle; //przypisanie ich do struktury stanu gry
	game_state.enemy_hero = enemy_hero;
	game_state.my_castle = my_castle;
	game_state.my_hero = my_hero;
	for( auto it = all_params.at(2).begin(); it != all_params.at(2).end(); ++it ){
		/*
		 * dla wszystkich parametrów złota w kontenerze zbiorczym
		 * skonstruuj objekt złota i dodaj go do struktury stanu gry
		 */
		game_state.map_gold.push_back( model::Gold( it->at(0), it->at(1), it->at(2) ) );
	}
	for( auto it = all_params.at(3).begin(); it != all_params.at(3).end(); ++it ){
		/*
		 * dla wszystkich parametrów oddziałów w kontenerze zbiorczym
		 * skonstruuj objekt oddziału i dodaj go do struktury stanu gry
		 */
		game_state.map_troops.push_back( model::Troop( it->at(0), it->at(1), it->at(2), it->at(3) ) );
	}
	for( auto it = all_params.at(4).begin(); it != all_params.at(4).end(); ++it ){
		/*
		 * dla wszystkich parametrów budynków w kontenerze zbiorczym
		 * skonstruuj objekt budynku i dodaj go do struktury stanu gry
		 */
		game_state.buildings.push_back( model::Building( it->at(0), it->at(1), it->at(2), it->at(3) ) );
	}
	for( auto it = all_params.at(5).begin(); it != all_params.at(5).end(); ++it ){
		/*
		 * dla wszystkich parametrów strzeżonych budynków w kontenerze zbiorczym
		 * skonstruuj objekt budynku i dodaj go do struktury stanu gry
		 */
		game_state.guarded_buildings.push_back( model::GuardedBuilding( it->at(0), it->at(1), it->at(3), it->at(2),
			it->at(4), it->at(5)) );
	}
}

void ScreenCapture::make_all_parameters_( AllParameters& all_parameters, const ObjectParameters& object_types )
{
	ObjectParameters castle_properties, hero_properties, building_properties, guarded_building_properties,
		gold_properties, troop_properties; //kontenery dla jednego objektu
	OneTypeParameters castles_properties, heros_properties, buildings_properties, guarded_buildings_properties,
		golds_properties, troops_properties; //kontenery zbiorcze dla wszystkich obiektów danego typu
	for( int i = 0; i<2; ++i ){ //są dwa zamki
		/**
		 * dla każdego wygeneruj parametry i dodaj do konteneru zbiorczego
		 */
		randomize_castle_( castle_properties );
		castles_properties.push_back( castle_properties );
		castle_properties.clear();
	}
	for( int i = 0; i<2; ++i ){//jest dwóch bohaterów
		/**
		 * dla każdego wygeneruj parametry i dodaj do konteneru zbiorczego
		 */
		randomize_hero_( hero_properties );
		heros_properties.push_back( hero_properties );
		hero_properties.clear();
	}
	for( int i = 0; i<object_types.at(0); ++i ){//dla wcześniej wylosowanej liczby w przekazanym parametrze
		/**
		 * dla każdego wygeneruj parametry i dodaj do konteneru zbiorczego
		 */
		randomize_troop_( troop_properties );
		troops_properties.push_back( troop_properties );
		troop_properties.clear();
	}
	for( int i = 0; i<object_types.at(1); ++i ){//dla wcześniej wylosowanej liczby w przekazanym parametrze
		/**
		 * dla każdego wygeneruj parametry i dodaj do konteneru zbiorczego
		 */
		randomize_gold_( gold_properties );
		golds_properties.push_back( gold_properties );
		gold_properties.clear();
	}
	for( int i = 0; i<object_types.at(2); ++i ){//dla wcześniej wylosowanej liczby w przekazanym parametrze
		/**
		 * dla każdego wygeneruj parametry i dodaj do konteneru zbiorczego
		 */
		randomize_building_( building_properties );
		buildings_properties.push_back( building_properties );
		building_properties.clear();
	}
	for( int i = 0; i<object_types.at(3); ++i ){//dla wcześniej wylosowanej liczby w przekazanym parametrze
		/**
		 * dla każdego wygeneruj parametry i dodaj do konteneru zbiorczego
		 */
		randomize_guarded_building_( guarded_building_properties );
		guarded_buildings_properties.push_back( guarded_building_properties );
		guarded_building_properties.clear();
	}
	/*
	 * dodaj wszystkie kontenery zbiorcze do jednego kontenera ze grupującego wszystko
	 */
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
	for( int i = 0; i<6; ++i){ //dla 6 kontenerów znajdujących się w kontenerze wszystkich współrzędnych ( jest 6 rodzajów obiektów )
		for( auto it = all_parameters.at(i).begin(); it!=all_parameters.at(i).end(); ++it ){ //iterujemy po każdym z tych 6 kontenerów
		it->push_back( it_coordinates->first ); //dodajemy do niekompletnych wszystkich parametrów też współrzędne obiektów
		it->push_back( it_coordinates->second );
		++it_coordinates;
		}
	}
}
void ScreenCapture::make_unique_coordinates_( AllCoordinates& coordinates,
		const MapSize& map_size,  int objects_number  )
{
	int width = map_size.first; // szerokość mapy
	int height = map_size.second; //wysokośc mapy
	int coordinates_generated = 0; //licznik wygenerowanych współrzędnych
    std::random_device dev;
    std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> coordinate_x(0,width); //losujemy współrzędną x z zakresu 0 - szerkość
	std::uniform_int_distribution<std::mt19937::result_type> coordinate_y(0,height); //losujemy współrzędną y z zakresu 0 - wysokość
	std::pair<int,int> tmp;
    while( coordinates_generated < objects_number ){ //póki liczba wygenerowanych współrzędnych jest mniejsza od liczby obiektów mapy
		tmp.first = coordinate_x(rng);
		tmp.second = coordinate_y(rng);
        if( !(std::find( coordinates.begin(), coordinates.end(), tmp) != coordinates.end() ) ) {
        	//sprawdzamy czy wylosowane współrzędne znajdują się już w kontenerze z współrzędnymi
        	coordinates.push_back( tmp ); // jeśli nie to dodajemy je do kontenera
			++coordinates_generated; //inkrementujemy licznik wygenerowanych
        }
    }
}

void ScreenCapture::randomize_hero_( ObjectParameters& hero_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    /*
     * losujemy liczebnośc armii bohatera, jego poziom i ilość złota( ją mnożymy przez 100 )
     */
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
    /*
     * losujemy parametry zamku w arbitralnych przedziałach( prawdopodobnych dla rozgrywki )
     */
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
    /*
     * losujemy poziom budynku i jego status
     */
    std::uniform_int_distribution<std::mt19937::result_type> tier(0,2);
    building_properties.push_back( tier(rng) );
    building_properties.push_back( tier(rng) );
}

void ScreenCapture::randomize_guarded_building_( ObjectParameters& guarded_building_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    /*
     * losujemy liczebnośc oddziału z zakresu 5-200
     * i jego poziom, poziom jego strażników i status
     */
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
    /*
     * losujemy ilość złota z zakresu 1-10 i mnożymy przez 100
     */
    std::uniform_int_distribution<std::mt19937::result_type> gold_quantity(1,10);
    gold_properties.push_back( gold_quantity(rng)*100 );
}

void ScreenCapture::randomize_troop_( ObjectParameters& troop_properties )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    /*
     * losujemy liczebnośc oddziału z zakresu 5-200
     * i jego poziom
     */
    std::uniform_int_distribution<std::mt19937::result_type> troop_quantity(5,200);
    std::uniform_int_distribution<std::mt19937::result_type> troop_tier(0,2);
    troop_properties.push_back(troop_quantity(rng));
    troop_properties.push_back(troop_tier(rng));

}

void ScreenCapture::randomize_map_size_( MapSize& map_size )
{
    std::random_device dev;
    std::mt19937 rng(dev());
    /*!
     * losowanie wymiarów mapy z zakresu 100-200
     */
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
    /*!
     * losowanie ilości obiektów na mapie z zakresu 100 do iloczynu wysokości i szerokości mapy podzielonego przez 30
     * aby zaimitować niezbyt gęsty ni luźny rozkład obiektów na mapie
     */
	std::uniform_int_distribution<std::mt19937::result_type> objects_number_( min, max);
	objects_number = objects_number_(rng);
}

void ScreenCapture::randomize_map_objects_types_( ObjectParameters& object_types, int objects_number )
{
    /*!
     * do wylosowania jest podany parametr - 4, ponieważ pozostała 4 jest stała - dwa zamki i dwóch bohaterów
     */
	objects_number -= 4;
	int tmp;
	std::random_device dev;
	std::mt19937 rng(dev());
    /*!
     * losowanie ilości oddziałów na mapie w zakresie 5 do czwartej części wszystkich obiektów
     */
	std::uniform_int_distribution<std::mt19937::result_type> troops_number( 5, objects_number/4 );
	tmp = troops_number(rng);
	object_types.push_back(tmp); //troops number
    /*
     * odejmujemy liczbę już wylosowanych
     * z pozostałej części losujemy liczbę wszystkich budynków na mapie z przedziału 10 - połowa pozostałych
     */
	objects_number -= tmp;
	std::uniform_int_distribution<std::mt19937::result_type> all_buildings_number( 10,  objects_number/2 );
	tmp = all_buildings_number(rng);
    /*
     * odejmujemy liczbę już wylosowanych budynków
     * to, co pozostało jest liczbą złota na mapie
     */
	objects_number -= tmp;
	object_types.push_back(objects_number); //gold number
    /*
     * z liczby wszystkich budynków przechowywanej w zmiennej tmp
     * losujemy liczbę zwykłych budynków w przedziale 10 - wszystkie budynki
     * różnicą wszystkich wylosowanych i wylosowanych zwykłych jest liczba strzeżonych budynków
     */
	std::uniform_int_distribution<std::mt19937::result_type> buildings_number( 10,  tmp );
	objects_number = tmp;
	tmp = buildings_number(rng);
	object_types.push_back(tmp); //buildings number
	object_types.push_back( (objects_number - tmp) ); //guardedbuildings number
}

}


