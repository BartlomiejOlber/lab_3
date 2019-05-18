/*
 * game_object.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_GAME_OBJECT_HPP_
#define BOT_MODEL_GAME_OBJECT_HPP_

#include <cmath>

namespace model {

class GameObject {

	int coord_x_;
	int coord_y_;

public:
	GameObject( int x = 0, int y = 0 ) : coord_x_( x ), coord_y_( y ){};
	GameObject( const GameObject& object ) : coord_x_( object.get_x() ), coord_y_( object.get_y() ){}
	void set_coordinates( int x, int y ){ coord_x_ = x; coord_y_ = y; };
	int get_x() const { return coord_x_; }
	int get_y() const { return coord_y_; }
	int get_distance( const GameObject& destination ) const { return sqrt( pow( coord_x_ - destination.get_x(), 2 ) +
		pow( coord_y_ - destination.get_y(), 2 ) ); }
	virtual ~GameObject(){};

};


}//end namespace

#endif /* BOT_MODEL_GAME_OBJECT_HPP_ */
