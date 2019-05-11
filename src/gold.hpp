/*
 * gold.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef GOLD_HPP_
#define GOLD_HPP_

#include "game_object.hpp"

class Gold : public GameObject {

	int quantity_;

public:

	Gold( int quantity, int x, int y ) : quantity_( quantity ), coord_x_( x ), coord_y_( y ){}
	void collect() : quantity_( 0 ){}

};



#endif /* GOLD_HPP_ */
