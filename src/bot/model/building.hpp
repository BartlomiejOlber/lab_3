/*
 * building.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_BUILDING_HPP_
#define BOT_MODEL_BUILDING_HPP_

#include <vector>
#include "entity.hpp"
#include "status.hpp"

namespace model {

class Building : public GameObject {

	Tier tier_;
	Status status_;

public:

	Building( Tier tier, Status status, int x, int y ) : tier_( tier ), status_( status ), coord_x_( x ), coord_y_( y ){}
	void take_control() : status_( Status::FRIEND ){}
	Tier get_tier() const { return tier_;}
	Status get_status() const { return status_; }

};

typedef std::vector<Building> BuildingContainer;

}//end namespace

#endif /* BOT_MODEL_BUILDING_HPP_ */
