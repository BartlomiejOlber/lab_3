/*
 * fight_action.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_FIGHT_ACTION_HPP_
#define BOT_MODEL_FIGHT_ACTION_HPP_

#include "hero_action.hpp"

namespace model {

class FightAction : public HeroAction {

public:
	FightAction( const GameObject& target ) : HeroAction( target ){}

	virtual void print(){  std::cout << "my hero fight in location ( " << target_.get_x()<<", "<<
		target_.get_y()<<" )"<<std::endl;
	}
};

}



#endif /* BOT_MODEL_FIGHT_ACTION_HPP_ */
