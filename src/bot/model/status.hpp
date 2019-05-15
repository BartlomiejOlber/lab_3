/*
 * status.hpp
 *
 *  Created on: May 11, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_STATUS_HPP_
#define BOT_MODEL_STATUS_HPP_

namespace model {

enum class Status {

	FRIEND = 0,
	ENEMY = 1,
	NEUTRAL = 2
};

class StatusConverter {

public:
	static Status from_int( int status ){
		return static_cast<Status>( status );
	}
};

}//end namespace

#endif /* BOT_MODEL_STATUS_HPP_ */
