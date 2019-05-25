/**
 * @file building.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Building
 */

#ifndef BOT_MODEL_BUILDING_HPP_
#define BOT_MODEL_BUILDING_HPP_

#include <vector>
#include "status.hpp"

namespace model {
//!  Klasa Building.
/*!
  Klasa budynku w rozumieniu bota, będąca obiektem gry, więc publicznie dziedzicząca po klasie GameObject.
*/

class Building : public GameObject {
    //! Prywatna składowa klasy enumeracyjnej Tier.
    /*! Określa poziom budynku. */
	Tier tier_;
    //! Prywatna składowa klasy enumeracyjnej.
    /*! Określa status budynku */
	Status status_;

public:

    //! Publiczny konstruktor.
    /*!
      \param tier poziom budynku.
      \param status status budynku.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Building( Tier tier, Status status, int x, int y ) : GameObject(x, y), tier_( tier ), status_( status ){}
    //! Publiczny konstruktor domyślny z parametrami integerowymi, konwertujący tier i status do enumeracji.
    /*!
      \param tier poziom budynku.
      \param status status budynku.
      \param x współrzędna x.
      \param y współrzędna y.
    */
	Building( int tier = 0, int status = 0, int x = 0, int y = 0 ) : GameObject(x, y), tier_( TierConverter::from_int(tier) ),
		status_( StatusConverter::from_int( status ) ){}
	//! Funkcja objęcia kontroli; zmienia status budynku na przyjazny.
	void take_control(){ status_ = Status::FRIEND; }
	//! Setter ustatwia status.
	void set_status( Status status ){ status_ = status; }
	//! Setter ustawia poziom.
	void set_tier( Tier tier ){ tier_ = tier; }
	//! Getter zwraca poziom.
	Tier get_tier() const { return tier_;}
	//! Getter zwraca status.
	Status get_status() const { return status_; }

};

//! Wektor budynków
typedef std::vector<Building> BuildingContainer;

}//end namespace

#endif /* BOT_MODEL_BUILDING_HPP_ */
