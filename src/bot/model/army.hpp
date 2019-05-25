/**
 * @file army.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Army
 */

#ifndef BOT_MODEL_ARMY_HPP_
#define BOT_MODEL_ARMY_HPP_

#include "troop.hpp"

namespace model {

//!  Klasa Army.
/*!
  Klasa armii w rozumieniu bota, będąca obiektem gry, więc publicznie dziedzicząca po klasie GameObject.
*/

class Army : public GameObject {

    //! Prywatna składowa klasy Troop.
    /*! Oddział armii o wysokim poziomie. */
	Troop high_tier_troop_;
    //! Prywatna składowa klasy Troop.
    /*! Oddział armii o średnim poziomie. */
	Troop mid_tier_troop_;
    //! Prywatna składowa klasy Troop.
    /*! Oddział armii o niskim poziomie. */
	Troop low_tier_troop_;

public:

    //! Publiczny konstruktor z parametrami integerowymi.
    /*!
      \param high_tier_num liczba jednostek wysokiego poziomu.
      \param mid_tier_num liczba jednostek średniego poziomu.
      \param low_tier_num liczba jednostek niskiego poziomu.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Army( int high_tier_num, int mid_tier_num, int low_tier_num, int x, int y ) : GameObject(x, y),
		high_tier_troop_( high_tier_num, Tier::HIGH, x, y ), mid_tier_troop_( mid_tier_num, Tier::MEDIUM, x, y ),
			low_tier_troop_( low_tier_num, Tier::LOW, x, y ){}
	//! Getter zwraca liczbę jednostek wysokiego poziomu.
	int get_high_tier_quantity() const { return high_tier_troop_.get_quantity(); }
	//! Getter zwraca liczbę jednostek średniego poziomu.
	int get_mid_tier_quantity() const { return mid_tier_troop_.get_quantity(); }
	//! Getter zwraca liczbę jednostek niskiego poziomu.
	int get_low_tier_quantity() const { return low_tier_troop_.get_quantity(); }
	/*! Funkcja zwiększająca liczbę jednostek wysokiego poziomu.
	 *\param quantity liczba dodawanych jednostek
	 */
	void recruit_high_tier( int quantity ){ high_tier_troop_.recruit( quantity ); }
	/*! Funkcja zwiększająca liczbę jednostek średniego poziomu.
	 *\param quantity liczba dodawanych jednostek
	 */
	void recruit_mid_tier( int quantity ){ mid_tier_troop_.recruit( quantity ); }
	/*! Funkcja zwiększająca liczbę jednostek niskiego poziomu.
	 *\param quantity liczba dodawanych jednostek
	 */
	void recruit_low_tier( int quantity ){ low_tier_troop_.recruit( quantity ); }
	/*! Funkcja zmniejszająca liczbę jednostek wysokiego poziomu.
	 *\param quantity liczba usuwanych jednostek pomnożona przez współczynnik wysokiego poziomu
	 */
	void kill_high_tier( int quantity ){ high_tier_troop_.kill( quantity/Troop::HIGH_TIER_FACTOR ); }
	/*! Funkcja zmniejszająca liczbę jednostek średniego poziomu.
	 *\param quantity liczba usuwanych jednostek pomnożona przez współczynnik średniego poziomu
	 */
	void kill_mid_tier( int quantity ){ mid_tier_troop_.kill( quantity/Troop::MID_TIER_FACTOR ); }
	/*! Funkcja zmniejszająca liczbę jednostek niskiego poziomu.
	 *\param quantity liczba usuwanych jednostek
	 */
	void kill_low_tier( int quantity ){ low_tier_troop_.kill( quantity ); }
	//! Funkcja usuwająca armię.
	void vanish(){ high_tier_troop_.vanish(); mid_tier_troop_.vanish(); low_tier_troop_.vanish(); }
	//! Funkcja obliczająca siłę armii; sumuje siły jej oddziałów
	int count_army_force() const { return high_tier_troop_.count_troop_force() + mid_tier_troop_.count_troop_force() +
		low_tier_troop_.count_troop_force(); }
};

}//end namespace

#endif /* BOT_MODEL_ARMY_HPP_ */
