/*
 * enter_action.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_ENTER_ACTION_HPP_
#define BOT_MODEL_ENTER_ACTION_HPP_


#include "hero_action.hpp"

namespace model {

class EnterAction : public HeroAction {

public:
	EnterAction( const GameObject& target ) : HeroAction( target ){}
};

}


#endif /* BOT_MODEL_ENTER_ACTION_HPP_ */
