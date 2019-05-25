/**
 * @file hero.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Hero
 */

#ifndef BOT_MODEL_HERO_HPP_
#define BOT_MODEL_HERO_HPP_

#include "army.hpp"
#include "status.hpp"

namespace model {
//!  Klasa Hero.
/*!
  Klasa bohatera w rozumieniu bota, będąca obiektem gry, więc publicznie dziedzicząca po klasie GameObject.
*/
class Hero : public GameObject {

public:
//! Statyczna stała; punkty ruchu bohatera.
static const int MOVEMENT_POINTS = 5;
//! Statyczna stała; bonus do punktów ruchu od poziomu bohatera.
static constexpr double MOVEMENT_POINTS_LEVEL_BONUS = 0.4;
//! Statyczna stała; wpółczynnik bonusu do siły armii od poziomu bohatera.
static constexpr double ARMYFORCE_FACTOR = 0.05;
//! Statyczna stała; współczynnik strat w walce oddziałów bohatera.
static constexpr double CASUALTIES_FACTOR = 0.33;

private:
	//! Prywatna składowa; ilość złota bohatera.
	int gold_;
	//! Prywatna składowa; numer poziomu bohatera.
	int level_;
	//! Prywatna składowa; armia bohatera klasy Army.
	Army army_;
	//! Prywatna składowa; status bohatera klasy enumeracyjnej Status.
	Status status_;

public:
    //! Publiczny konstruktor domyślny.
    /*!
      \param gold ilość złota bohatera.
      \param level numer poziomu boharera.
      \param high_tier_army_num liczba jednostek wysokiego poziomu w armii bohatera.
      \param mid_tier_army_num liczba jednostek średniego poziomu w armii bohatera.
      \param low_tier_army_num liczba jednostek niskiego poziomu w armii bohatera.
      \param status status bohatera.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Hero( int gold = 0, int level = 0, int high_tier_army_num = 0, int mid_tier_army_num = 0, int low_tier_army_num = 0,
		int x = 0, int y = 0, Status status = Status::NEUTRAL ) : GameObject(x, y), gold_( gold ), level_( level ),
		army_( high_tier_army_num, mid_tier_army_num, low_tier_army_num, x, y ), status_( status ){}
    //! Publiczny konstruktor.
    /*!
      \param params wektor parametrów integerowych.
      \param status status bohatera.
    */
	Hero( const std::vector<int>& params, Status status ) : GameObject( params[5], params[6]), gold_( params[0] ),
		level_( params[1] ), army_( params[2], params[3], params[4], params[5], params[6] ), status_( status ){}
	//! Funkcja podróżuj do; ustawia współrzędne bohatera zgodnie z współrzędnymi celu
	void travel_to( int x, int y ){ set_coordinates( x, y ); }
	//! Funkcja podróżuj do; ustawia współrzędne bohatera zgodnie z współrzędnymi celu
	void travel_to( const GameObject& object ){ set_coordinates( object.get_x(), object.get_y() ); }
	//! Getter zwraca poziom bohatera.
	int get_level() const { return level_; }
	//! Getter zwraca ilość złota bohatera.
	int get_gold() const { return gold_; }
	//! Funkcja podnieś złoto; dodaje ilość złota w parametrze do jego własnego złota
	void pick_up_gold( int quantity ) { gold_ += quantity; }
	//! Getter zwraca liczbę jednostek wysokiego poziomu w armii bohatera.
	int get_high_tier_army_quantity() const { return army_.get_high_tier_quantity(); }
	//! Getter zwraca liczbę jednostek średniego poziomu w armii bohatera.
	int get_mid_tier_army_quantity() const { return army_.get_mid_tier_quantity(); }
	//! Getter zwraca liczbę jednostek niskiego poziomu w armii bohatera.
	int get_low_tier_army_quantity() const { return army_.get_low_tier_quantity(); }
	//! Getter zwraca ilość punktów ruchu bohatera.
	int get_movement_points() const { return (MOVEMENT_POINTS + level_*MOVEMENT_POINTS_LEVEL_BONUS); }
	//! Funkcja obliczająca siłę bohatera; mnoży siłę jego armii przez bonus od jego poziomu.
	int count_hero_force() const { return army_.count_army_force() * ( 1 + level_ * ARMYFORCE_FACTOR ); }
	//! Funkcja zabijająca bohatera; ustawia jego status na neutralny
	void kill(){ status_ = Status::NEUTRAL; }
	//! Funkcja zabijająca część armii bohatera; zabija proporcjonalnie do poziomu oddziałów
	void kill( int casualties ){ army_.kill_high_tier( casualties*CASUALTIES_FACTOR );
		army_.kill_mid_tier( casualties*CASUALTIES_FACTOR ); army_.kill_low_tier( casualties*CASUALTIES_FACTOR );
	}
	//! Funkcja zwraca wartośc logiczą czy bohater żyje czy nie
	bool is_alive() const { return status_ == Status::NEUTRAL ? false : true; }

};


}//end namespace

#endif /* BOT_MODEL_HERO_HPP_ */
