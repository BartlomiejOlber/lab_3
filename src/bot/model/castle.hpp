/**
 * @file castle.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Castle
 */

#ifndef BOT_MODEL_CASTLE_HPP_
#define BOT_MODEL_CASTLE_HPP_

#include <vector>
#include <iostream>
#include "army.hpp"
#include "building.hpp"

namespace model {
//!  Klasa Castle.
/*!
  Klasa zamku w rozumieniu bota, będąca obiektem gry, więc publicznie dziedzicząca po klasie GameObject.
*/
class Castle : public GameObject {

public:

//! Statyczna stała; koszt wybudowania budynku niskiego poziomu.
static const int LOW_TIER_BUILDING_COST = 1000;
//! Statyczna stała; koszt wybudowania budynku średniego poziomu.
static const int MID_TIER_BUILDING_COST = 4000;
//! Statyczna stała; koszt wybudowania budynku wysokiego poziomu.
static const int HIGH_TIER_BUILDING_COST = 15000;
//! Statyczna stała; koszt rekrutacji jednostki niskiego poziomu.
static const int LOW_TIER_ENTITY_COST = 100;
//! Statyczna stała; koszt rekrutacji jednostki średniego poziomu.
static const int MID_TIER_ENTITY_COST = 400;
//! Statyczna stała; koszt rekrutacji jednostki wysokiego poziomu.
static const int HIGH_TIER_ENTITY_COST = 2000;
//! Statyczna stała; maksymalna liczba budynków wysokiego poziomu.
static const int MAX_HIGH_TIER_BUILDINGS = 3;
//! Statyczna stała; maksymalna liczba budynków średniego poziomu.
static const int MAX_MID_TIER_BUILDINGS = 5;
//! Statyczna stała; maksymalna liczba budynków niskiego poziomu.
static const int MAX_LOW_TIER_BUILDINGS = 10;
//! Statyczna stała; bonus do obrony od budynku niskiego poziomu.
static constexpr double LOW_TIER_BUILDING_DEFENCE_BONUS = 0.01;
//! Statyczna stała; bonus do obrony od budynku średniego poziomu.
static constexpr double MID_TIER_BUILDING_DEFENCE_BONUS = 0.02;
//! Statyczna stała; bonus do obrony od budynku wysokiego poziomu.
static constexpr double HIGH_TIER_BUILDING_DEFENCE_BONUS = 0.05;

private:
	//! Prywatna składowa klasy Army.
	/*! Garnizon zamku */
	Army garrison_;
    //! Prywatna składowa klasy enumeracyjnej.
    /*! Określa status zamku */
	Status status_;
    //! Prywatna składowa określająca liczbę budynków wysokiego poziomu w zamku.
	int high_tier_buildings_num_;
	//! Prywatna składowa określająca liczbę budynków średniego poziomu w zamku.
	int mid_tier_buildings_num_;
	//! Prywatna składowa określająca liczbę budynków niskiego poziomu w zamku.
	int low_tier_buildings_num_;
	//! Prywatna składowa określająca liczbę dostępnych do rekrutacji jednostek wysokiego poziomu w zamku.
	int high_tier_recruitment_num_;
	//! Prywatna składowa określająca liczbę dostępnych do rekrutacji jednostek średniego poziomu w zamku.
	int mid_tier_recruitment_num_;
	//! Prywatna składowa określająca liczbę dostępnych do rekrutacji jednostek niskiego poziomu w zamku.
	int low_tier_recruitment_num_;


public:

    //! Publiczny konstruktor domyślny.
    /*!
      \param high_tier_army_num liczba jednostek wysokiego poziomu w garnizonie.
      \param mid_tier_army_num liczba jednostek średniego poziomu w garnizonie.
      \param low_tier_army_num liczba jednostek niskiego poziomu w garnizonie.
      \param status status zamku.
      \param high_tier_buildings_num liczba budynków wysokiego poziomu w zamku.
      \param mid_tier_buildings_num liczba budynków średniego poziomu w zamku.
      \param low_tier_buildings_num liczba budynków niskiego poziomu w zamku.
      \param high_tier_recruitment_num liczba jednostek wysokiego poziomu możliwych do rekrutacji w zamku.
      \param mid_tier_recruitment_num liczba jednostek średniego poziomu możliwych do rekrutacji w zamku.
      \param low_tier_recruitment_num liczba jednostek niskiego poziomu możliwych do rekrutacji w zamku.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Castle( int high_tier_army_num = 0, int mid_tier_army_num = 0, int low_tier_army_num = 0, Status status = Status::NEUTRAL,
		int high_tier_buildings_num  = 0, int mid_tier_buildings_num = 0, int low_tier_buildings_num = 0,
		int high_tier_recruitment_num = 0, int mid_tier_recruitment_num = 0, int low_tier_recruitment_num = 0, int x = 0,
		int y = 0 ) : GameObject(x, y), garrison_( high_tier_army_num, mid_tier_army_num, low_tier_army_num, x, y ),
		status_( status ), high_tier_buildings_num_( high_tier_buildings_num ),
		mid_tier_buildings_num_( mid_tier_buildings_num ), low_tier_buildings_num_( low_tier_buildings_num ),
		high_tier_recruitment_num_( high_tier_recruitment_num ), mid_tier_recruitment_num_( mid_tier_recruitment_num ),
		low_tier_recruitment_num_( low_tier_recruitment_num ) {}
    //! Publiczny konstruktor.
    /*!
      \param params wektor parametrów integerowych.
      \param status status bohatera.
    */
	Castle( const std::vector<int>& params, Status status ) : GameObject(params[9], params[10]),
		garrison_( params[0], params[1], params[2], params[9], params[10] ), status_( status ),
		high_tier_buildings_num_( params[3] ), mid_tier_buildings_num_( params[4] ),
		low_tier_buildings_num_( params[5] ), high_tier_recruitment_num_( params[6] ),
		mid_tier_recruitment_num_( params[7] ), low_tier_recruitment_num_( params[8] ) {}
	//! Funkcja obliczająca bonus obronny
	double defence_bonus() const { return 1 + (low_tier_buildings_num_*LOW_TIER_BUILDING_DEFENCE_BONUS +
		(mid_tier_buildings_num_*MID_TIER_BUILDING_DEFENCE_BONUS) + (high_tier_buildings_num_*HIGH_TIER_BUILDING_DEFENCE_BONUS) );
	}
	//! Funkcja budowania budynku niskiego poziomu; zwiększa liczbę tych budynków w zamku
	void build_low_tier(){ ++low_tier_buildings_num_; }
	//! Funkcja budowania budynku średniego poziomu; zwiększa liczbę tych budynków w zamku
	void build_mid_tier(){ ++mid_tier_buildings_num_; }
	//! Funkcja budowania budynku wysokiego poziomu; zwiększa liczbę tych budynków w zamku
	void build_high_tier(){ ++high_tier_buildings_num_; }
	//! Funkcja rekrutowania jednostki wysokiego poziomu; zmniejsza liczbę możliwych do rektutacji i zwiększa liczbę jednostek w garnizonie
	void recruit_high_tier( int quantity ){ high_tier_recruitment_num_-=quantity; garrison_.recruit_high_tier( quantity ); }
	//! Funkcja rekrutowania jednostki średniego poziomu; zmniejsza liczbę możliwych do rektutacji i zwiększa liczbę jednostek w garnizonie
	void recruit_mid_tier( int quantity ){ mid_tier_recruitment_num_-=quantity; garrison_.recruit_mid_tier( quantity ); }
	//! Funkcja rekrutowania jednostki niskiego poziomu; zmniejsza liczbę możliwych do rektutacji i zwiększa liczbę jednostek w garnizonie
	void recruit_low_tier( int quantity ){ low_tier_recruitment_num_-=quantity; garrison_.recruit_low_tier( quantity ); }
	//! Getter zwraca liczbę jednostek wysokiego poziomu możliwą do rekrutacji.
	int get_high_tier_recruitment_num() const { return high_tier_recruitment_num_; }
	//! Getter zwraca liczbę jednostek średniego poziomu możliwą do rekrutacji.
	int get_mid_tier_recruitment_num() const { return mid_tier_recruitment_num_; }
	//! Getter zwraca liczbę jednostek niskiego poziomu możliwą do rekrutacji.
	int get_low_tier_recruitment_num() const { return low_tier_recruitment_num_; }
	//! Funkcja zwraca wartośc logiczą czy budowa budynku wysokiego poziomu jest możliwa
	bool is_development_available_high() const { return high_tier_buildings_num_<MAX_HIGH_TIER_BUILDINGS ? true : false; }
	//! Funkcja zwraca wartośc logiczą czy budowa budynku średniego poziomu jest możliwa
	bool is_development_available_mid() const { return mid_tier_buildings_num_<MAX_MID_TIER_BUILDINGS ? true : false; }
	//! Funkcja zwraca wartośc logiczą czy budowa budynku niskiego poziomu jest możliwa
	bool is_development_available_low() const { return low_tier_buildings_num_<MAX_LOW_TIER_BUILDINGS ? true : false; }
	//! Funkcja obliczająca siłę zamku; mnoży siłę garnizonu przez bonus obronny.
	int count_castle_force() const {  return garrison_.count_army_force() * defence_bonus(); }
	//! Funkcja zdobądź zamek; ustawia jego status na przyjazny i zeruje garnizon zamku
	void conquer(){ garrison_.vanish(); status_ = Status::FRIEND; }
	//! Getter zwraca status zamku.
	Status get_status() const { return status_; }


};

}//end namespace

#endif /* BOT_MODEL_CASTLE_HPP_ */
