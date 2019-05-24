/*
 * action.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_ACTION_HPP_
#define BOT_MODEL_ACTION_HPP_

#include <vector>
#include <memory>
#include <iostream>
#include "game_object.hpp"

namespace model {

class Action {

protected:
	GameObject target_;

public:
	explicit Action( const GameObject& target ) : target_( target ){}
	explicit Action( int x, int y ) :  target_( x, y ){}
	virtual ~Action(){};

	virtual void print(){};
};

typedef std::vector<std::unique_ptr<Action> > ActionScenario;

}



#endif /* BOT_MODEL_ACTION_HPP_ */
