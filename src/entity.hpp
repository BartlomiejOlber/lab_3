/*
 * entity.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "game_object.hpp"
#include "tier.hpp"

class Entity : public GameObject {

	Tier tier_;

public:
	~Entity(){};

};



#endif /* ENTITY_HPP_ */
