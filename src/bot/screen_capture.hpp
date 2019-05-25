/**
 * @file screen_capture.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy ScreenCapture
 */

#ifndef BOT_SCREEN_CAPTURE_HPP_
#define BOT_SCREEN_CAPTURE_HPP_

#include <vector>
#include <array>
#include "model/game_state.hpp"

namespace bot {
//!  Klasa ScreenCapture.
/*!
  Klasa imitująca część bota odpowiedzialną za pobieranie stanu gry z ekranu i parsowanie go do struktur rozumianych przez algorytm.
  Zaimplementowana by generować stan gry w sposób całkowicie losowy.
*/
class ScreenCapture {

	//! Prywatna definicja typu; zgrupowanie wszystkich parametrów obiektów mapy w jeden wektor.
	typedef std::vector<std::vector <std::vector<int> > > AllParameters;
	//! Prywatna definicja typu; zgrupowanie parametrów wszystkich obiektów danego typu w jeden wektor.
	typedef std::vector<std::vector<int> > OneTypeParameters;
	//! Prywatna definicja typu; zgrupowanie wszystkich współrzędnych obiektów mapy w jeden wektor.
	typedef std::vector<std::pair<int, int> > AllCoordinates;
	//! Prywatna definicja typu; para wymiarów mapy.
	typedef std::pair<int, int> MapSize;
	//! Prywatna definicja typu; parametry jednego obiektu w wektorze.
	typedef std::vector<int> ObjectParameters;

public:
	//! Funkcja imitująca zbieranie danych z ekranu; faktycznie generuje stan gry losowo
	void capture_screen( model::GameState& );

private:

	//! Prywatna funkcja pomocnicza grupująca wszystkie wcześniej wygenerowane parametry w jeden wektor
	void make_all_parameters_( AllParameters& all_parameters, const ObjectParameters& object_types );
	//! Prywatna funkcja pomocnicza scalająca wszyskie wygenerowane parametry z wszystkimi unikalnymi współrzędnymi
	void merge_coordinates_( AllParameters& all_parameters, const AllCoordinates& coordinates );
	//! Prywatna funkcja pomocnicza generująca wektor unikalnych współrzędnych w podanej liczbie i o podanych ograniczeniach wielkości mapy
	void make_unique_coordinates_( AllCoordinates& coordinates, const MapSize& map_size, int objects_number );
	//! Prywatna funkcja pomocnicza generująca parametry dla jednego bohatera
	void randomize_hero_( ObjectParameters& hero_properties );
	//! Prywatna funkcja pomocnicza generująca parametry dla jednego zamku
	void randomize_castle_( ObjectParameters& castle_properties );
	//! Prywatna funkcja pomocnicza generująca parametry dla jednego budynku
	void randomize_building_( ObjectParameters& building_properties );
	//! Prywatna funkcja pomocnicza generująca parametry dla jednego strzeżonego budynku
	void randomize_guarded_building_( ObjectParameters&  guarded_building_properties );
	//! Prywatna funkcja pomocnicza generująca parametry dla jednego złota na mapie
	void randomize_gold_( ObjectParameters& gold_properties );
	//! Prywatna funkcja pomocnicza generująca parametry dla jednego oddziału
	void randomize_troop_( ObjectParameters& troop_properties );
	//! Prywatna funkcja pomocnicza generująca rozmiary mapy
	void randomize_map_size_( MapSize& map_size );
	//! Prywatna funkcja pomocnicza generująca liczbę obiektów na mapie
	void randomize_map_objects_number_( const MapSize& map_size, int& objects_number );
	//! Prywatna funkcja pomocnicza generująca liczby poszczególnych rodzajów obiektów na mapie
	void randomize_map_objects_types_( ObjectParameters& object_types, int objects_number );
};

}



#endif /* BOT_SCREEN_CAPTURE_HPP_ */
