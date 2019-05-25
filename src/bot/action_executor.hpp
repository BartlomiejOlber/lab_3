/**
 * @file action_executor.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy ActionExecutor
 */
#ifndef BOT_ACTION_EXECUTOR_HPP_
#define BOT_ACTION_EXECUTOR_HPP_

#include "model/action.hpp"

namespace bot {
//!  Klasa ActionExecutor.
/*!
  Pusta klasa imitująca klasę wykonawcy decyzji otrzymanych przez algorytm.
*/
class ActionExecutor {

	//! Prywatna składowa; scenariusz akcji do wykonania, wygenerowany przez algorytm.
	const model::ActionScenario& scenario_;

public:
    //! Publiczny konstruktor z parametrem klasy ActionScenario.
    /*!
      \param scenario stała referencja na obiekt klasy ActionScenario; scenariusz akcji do wykonania.
    */
	ActionExecutor( const model::ActionScenario& scenario ) : scenario_( scenario ){}
};

}

#endif /* BOT_ACTION_EXECUTOR_HPP_ */
