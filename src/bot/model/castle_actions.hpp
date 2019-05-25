/**
 * @file castle_actions.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy CastleAction
 */
#ifndef BOT_MODEL_CASTLE_ACTIONS_HPP_
#define BOT_MODEL_CASTLE_ACTIONS_HPP_

#include "action.hpp"

namespace model {
//!  Klasa CastleAction.
/*!
  Klasa bazowa dla akcji zamku wydanych przez algorytm bota.
*/
class CastleAction : public Action {

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
	/*!
	  \param target stała referencja na obiekt klasy GameObject.
	*/
	explicit CastleAction( const GameObject& target ) : Action( target ){}
	//! Wirtualny destruktor.
	virtual ~CastleAction(){};

};

}


#endif /* BOT_MODEL_CASTLE_ACTIONS_HPP_ */
