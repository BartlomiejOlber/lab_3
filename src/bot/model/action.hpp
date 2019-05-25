/**
 * @file action.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Action
 */

#ifndef BOT_MODEL_ACTION_HPP_
#define BOT_MODEL_ACTION_HPP_

#include <vector>
#include <memory>
#include <iostream>
#include "game_object.hpp"

namespace model {

//!  Klasa Action.
/*!
  Klasa imitująca klasę akcji wydanych przez algorytm bota.
*/

class Action {

protected:
    //! Chroniona składowa klasy GameObject.
    /*! Jest to objekt, na którym akcja ma być wykonana. */
	GameObject target_;

public:
    //! Publiczny konstruktor z parametrem klasy GameObject.
    /*!
      \param target stała referencja na obiekt klasy GameObject.
    */
	explicit Action( const GameObject& target ) : target_( target ){}
    //! Publiczny konstruktor z parametrami integer.
    /*!
      \param x integerowa współrzędna x.
      \param y integerowa współrzędna y.
    */
	explicit Action( int x, int y ) :  target_( x, y ){}
    //! Wirtualny destruktor.
	virtual ~Action(){};

    //! Wirtualna metoda print.
	/*!
	  Pusta metoda; w klasach pochodnych będzie służyć w celach jedynie informacyjnych.
	*/
	virtual void print(){};
};

//! Wektor inteligentnych wskaźników na klasę Action - jest to zestaw decyzji bota w jednym kontenerze
typedef std::vector<std::unique_ptr<Action> > ActionScenario;

}



#endif /* BOT_MODEL_ACTION_HPP_ */
