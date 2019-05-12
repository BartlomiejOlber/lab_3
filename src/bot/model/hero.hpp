/*
 * hero.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_HERO_HPP_
#define BOT_MODEL_HERO_HPP_

#include "army.hpp"

namespace model {

class Hero : public GameObject {

	int level_;
	Army army_;

};


}//end namespace

#endif /* BOT_MODEL_HERO_HPP_ */
