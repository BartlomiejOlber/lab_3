/*
 * game_object.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_GAME_OBJECT_HPP_
#define BOT_MODEL_GAME_OBJECT_HPP_

namespace model {

class GameObject {

	int coord_x_;
	int coord_y_;

public:
	GameObject( int x = 0, int y = 0 ) : coord_x_( x ), coord_y_( y ){};
	void set_coordinates( int x, int y ) : coord_x_( x ), coord_y_( y ){};
	int get_x() const { return coord_x_; }
	int get_y() const { return coord_y_; }
	virtual ~GameObject(){};

};


}//end namespace

#endif /* BOT_MODEL_GAME_OBJECT_HPP_ */
