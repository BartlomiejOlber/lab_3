/**
 * @file troop.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Troop
 */

#ifndef BOT_MODEL_TROOP_HPP_
#define BOT_MODEL_TROOP_HPP_

#include <vector>
#include "tier.hpp"
#include "game_object.hpp"

namespace model {
//!  Klasa Troop.
/*!
  Klasa oddziału w rozumieniu bota, będąca obiektem gry, więc publicznie dziedzicząca po klasie GameObject.
*/
class Troop : public GameObject {

public:
	//! Statyczna stała; współczynnik mocy jednostki wysokiego poziomu.
	static const int HIGH_TIER_FACTOR = 50;
	//! Statyczna stała; współczynnik mocy jednostki średniego poziomu.
	static const int MID_TIER_FACTOR = 10;

private:
	//! Prywatna składowa; poziom oddziału klasy enumeracyjnej Tier.
	Tier tier_;
	//! Prywatna składowa; liczebność oddziału.
	int quantity_;

public:
    //! Publiczny konstruktor.
    /*!
      \param quantity liczebność oddziału.
      \param tier poziom oddziału klasy enumeracyjnej Tier.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Troop( int quantity, Tier tier, int x, int y ) : GameObject( x, y ), tier_( tier ), quantity_( quantity ) {}
    //! Publiczny konstruktor domyślny.
    /*!
      \param quantity liczebność oddziału.
      \param tier poziom oddziału konwetrowany do klasy enumeracyjnej Tier.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Troop( int quantity = 0, int tier = 0, int x = 0, int y = 0 ) : GameObject( x, y ), tier_( TierConverter::from_int( tier) ),
			quantity_( quantity ) {}
	//! Getter zwraca liczebnośc oddziału.
	int get_quantity() const { return quantity_; }
	//! Getter zwraca poziom oddziału.
	Tier get_tier() const { return tier_; }
	//! Funkcja rekrutuj; zwiększa liczbę jednostek oddziału o dany parametr
	void recruit( int quantity ){ quantity_ += quantity; }
	//! Funkcja zabij odejmuje zadaną liczbę jednostek z oddziału
	void kill( int quantity ){ quantity >= quantity_ ? quantity_ = 0 : quantity_ -= quantity; }
	//! Funkcja zabij wszystkich; ustawia liczebność oddziału na zero
	void vanish(){ quantity_ = 0;}
	//! Funkcja obliczająca siłę oddziału; mnoży jego liczebność przez współczynnik poziomu jednostek
	int count_troop_force() const { if( tier_ == Tier::HIGH ) return quantity_ * HIGH_TIER_FACTOR;
		if( tier_ == Tier::MEDIUM ) return quantity_ * MID_TIER_FACTOR;
		return quantity_;
	}
};
//! Wektor oddziałów
typedef std::vector<Troop> TroopContainer;

}//end namespace

#endif /* BOT_MODEL_TROOP_HPP_ */
