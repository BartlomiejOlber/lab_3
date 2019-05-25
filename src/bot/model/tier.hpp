/**
 * @file tier.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy enumeracyjnej Tier i klasy konwertera TierConverter
 */

#ifndef BOT_MODEL_TIER_HPP_
#define BOT_MODEL_TIER_HPP_

namespace model {
//!  Klasa enumeracyjna Tier.
/*!
  Enumeracja poziomu obiektów gry.
*/
enum class Tier{
	//! Poziom niski.
	LOW = 0,
	//! Poziom średni.
	MEDIUM = 1,
	//! Poziom wysoki.
	HIGH = 2
};
//!  Klasa TierConverter.
class TierConverter {

public:
	//! Statyczna publiczna fukncja konwertująca wartość całkowitą do enumeracji Tier
	static Tier from_int( int tier ){
		return static_cast<Tier>(tier);
	}
};

}//end namespace

#endif /* BOT_MODEL_TIER_HPP_ */
