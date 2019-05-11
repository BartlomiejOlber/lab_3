/*
 * game_object.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef GAME_OBJECT_HPP_
#define GAME_OBJECT_HPP_


class GameObject{

	int coord_x_;
	int coord_y_;

public:
	void set_coordinates( int x, int y ) : coord_x_( x ), coord_y_( y ){};
	virtual ~GameObject(){};

};




#endif /* GAME_OBJECT_HPP_ */
