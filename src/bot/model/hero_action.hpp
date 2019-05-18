/*
 * hero_actions.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_HERO_ACTION_HPP_
#define BOT_MODEL_HERO_ACTION_HPP_

#include "action.hpp"

namespace model {

class HeroAction : public Action {

public:
	explicit HeroAction( const GameObject& target ) : Action( target ){}
};

}

#endif /* BOT_MODEL_HERO_ACTION_HPP_ */
