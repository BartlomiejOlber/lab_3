/*
 * action.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_ACTION_HPP_
#define BOT_MODEL_ACTION_HPP_

#include <vector>
#include "game_object.hpp"

namespace model {

class Action {

	GameObject target_;

public:
	explicit Action( const GameObject& target ) : target_( target ){}
	explicit Action( int x, int y ) :  target_( x, y ){}
	virtual ~Action() = 0;
};

typedef std::vector<Action> ActionScenario;

}



#endif /* BOT_MODEL_ACTION_HPP_ */
