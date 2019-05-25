/**
 * @file hero_action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy HeroAction
 */
#ifndef BOT_MODEL_HERO_ACTION_HPP_
#define BOT_MODEL_HERO_ACTION_HPP_

#include "action.hpp"

namespace model {
//!  Klasa HeroAction.
/*!
  Klasa bazowa dla akcji bohatera wydanych przez algorytm bota.
*/
class HeroAction : public Action {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	explicit HeroAction( const GameObject& target ) : Action( target ){}
	//! Wirtualny destruktor.
	virtual ~HeroAction(){};
};

}

#endif /* BOT_MODEL_HERO_ACTION_HPP_ */
