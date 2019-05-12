/*
 * castle.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_CASTLE_HPP_
#define BOT_MODEL_CASTLE_HPP_

#include "army.hpp"
#include "building.hpp"

namespace model {

class Castle : public GameObject {

	Army garrison_;
	Status status_;
	int high_tier_buildings_num_;
	int mid_tier_buildings_num_;
	int low_tier_buildings_num_;

public:



};

}//end namespace

#endif /* BOT_MODEL_CASTLE_HPP_ */
