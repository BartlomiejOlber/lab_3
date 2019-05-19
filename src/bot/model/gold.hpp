/*
 * gold.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_GOLD_HPP_
#define BOT_MODEL_GOLD_HPP_

#include <vector>
#include "game_object.hpp"

namespace model {

class Gold : public GameObject {

	int quantity_;

public:

	Gold( int quantity = 0, int x = 0, int y = 0) : GameObject(x, y), quantity_( quantity ){}
	int get_quantity(){ return quantity_; }

};

typedef std::vector<Gold> GoldContainer;

}//end namespace

#endif /* BOT_MODEL_GOLD_HPP_ */
