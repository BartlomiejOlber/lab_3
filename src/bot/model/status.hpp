/**
 * @file status.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy enumeracyjnej Status i klasy konwertera StatusConverter
 */

#ifndef BOT_MODEL_STATUS_HPP_
#define BOT_MODEL_STATUS_HPP_

namespace model {
//!  Klasa enumeracyjna Status.
/*!
  Enumeracja statusu obiektów gry.
*/
enum class Status {

	//! Status obiektu bota.
	FRIEND = 0,
	//! Status obiektu przeciwnika.
	ENEMY = 1,
	//! Status obiektu niezależnego.
	NEUTRAL = 2
};
//!  Klasa StatusConverter.
class StatusConverter {

public:
	//! Statyczna publiczna fukncja konwertująca wartość całkowitą do enumeracji Status
	static Status from_int( int status ){
		return static_cast<Status>( status );
	}
};

}//end namespace

#endif /* BOT_MODEL_STATUS_HPP_ */
