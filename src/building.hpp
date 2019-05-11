/*
 * building.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include "entity.hpp"
#include "status.hpp"

class Building : public GameObject {

	Tier tier_;
	Status status_;

public:

	Building( Tier tier, Status status, int x, int y ) : tier_( tier ), status_( status ), coord_x_( x ), coord_y_( y ){}
	void take_control() : status_( Status::FRIEND ){}

};


#endif /* BUILDING_HPP_ */
