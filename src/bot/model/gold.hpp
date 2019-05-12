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

	Gold( int quantity, int x, int y ) : quantity_( quantity ), coord_x_( x ), coord_y_( y ){}
	int get_quantity(){ return quantity_; }
	void collect() : quantity_( 0 ){}

};

typedef std::vector<Gold> GoldContainer;

}//end namespace

#endif /* BOT_MODEL_GOLD_HPP_ */
