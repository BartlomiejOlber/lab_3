/*
 * screen_capture.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_SCREEN_CAPTURE_HPP_
#define BOT_SCREEN_CAPTURE_HPP_

#include "model/game_state.hpp"

namespace bot {

class ScreenCapture {

public:
	void capture_screen( model::GameState& );

};

}



#endif /* BOT_SCREEN_CAPTURE_HPP_ */
