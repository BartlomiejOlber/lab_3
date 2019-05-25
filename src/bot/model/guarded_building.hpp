/**
 * @file guarded_building.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy GuardedBuilding
 */

#ifndef BOT_MODEL_GUARDED_BUILDING_HPP_
#define BOT_MODEL_GUARDED_BUILDING_HPP_

#include "building.hpp"
#include "troop.hpp"

namespace model {
//!  Klasa GuardedBuilding.
/*!
  Klasa strzeżonego budynku w rozumieniu bota, będąca budynkiem, więc publicznie dziedzicząca po klasie Building.
*/
class GuardedBuilding : public Building {
	//! Prywatna składowa; oddział strzegący klasy Troop.
	Troop guards_;

public:
    //! Publiczny konstruktor.
    /*!
      \param building_tier poziom budynku klasy enumeracyjnej Tier.
      \param status status budynku klasy enumeracyjnej Status.
      \param guards_num liczebność oddziału.
      \param guards_tier poziom oddziału strzegącego klasy enumeracyjnej Tier.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	GuardedBuilding( Tier building_tier, Status status, int guards_num, Tier guards_tier, int x, int y ) :
		Building( building_tier, status, x, y ), guards_( guards_num, guards_tier, x, y ) {}
    //! Publiczny konstruktor domyślny.
    /*!
      \param building_tier poziom budynku konwertowany do klasy enumeracyjnej Tier.
      \param status status budynku konwertowany do klasy enumeracyjnej Status.
      \param guards_num liczebność oddziału.
      \param guards_tier poziom oddziału strzegącego konwertowany do klasy enumeracyjnej Tier.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	GuardedBuilding( int building_tier = 0, int status = 0, int guards_num = 0, int guards_tier = 0, int x = 0, int y = 0 ) :
		Building( building_tier, status, x, y ), guards_( guards_num, TierConverter::from_int(guards_tier), x, y ) {}
	//! Funkcja zdobycia budynku; ustawia status na przyjazny i liczbę strzegących na 0
	void conquer(){  take_control(); guards_.vanish(); }
	//! Getter zwraca poziom oddziału.
	Tier get_guards_tier() const { return guards_.get_tier(); }
	//! Getter zwraca liczebnośc oddziału.
	int get_guards_quantity() const { return guards_.get_quantity(); }
	//! Funkcja obliczająca siłę oddziału strzegącego budynek
	int count_guards_force() const { return guards_.count_troop_force();  }

};
//! Wektor strzeżonych budynków
typedef std::vector<GuardedBuilding> GuardedBuildingContainer;

}//end namespace

#endif /* BOT_MODEL_GUARDED_BUILDING_HPP_ */
