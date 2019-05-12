/*
 * action_executor.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_ACTION_EXECUTOR_HPP_
#define BOT_ACTION_EXECUTOR_HPP_

#include "model/action.hpp"

namespace bot {

class ActionExecutor {

	const model::ActionScenario& scenario_;

public:
	ActionExecutor( const model::ActionScenario& scenario ) : scenario_( scenario ){}
};

}

#endif /* BOT_ACTION_EXECUTOR_HPP_ */
