/*
 * army.hpp
 *
 *  Created on: May 12, 2019
 *      Author: bartlomiej
 */

#ifndef BOT_MODEL_ARMY_HPP_
#define BOT_MODEL_ARMY_HPP_

#include "troop.hpp"

namespace model {

class Army : public GameObject {

	Troop high_tier_troop_;
	Troop mid_tier_troop_;
	Troop low_tier_troop_;

public:

	Army( int high_tier_num, int mid_tier_num, int low_tier_num, int x, int y ) :
		high_tier_troop_( high_tier_num, Tier::HIGH, x, y ), mid_tier_troop_( mid_tier_num, Tier::MIDDLE, x, y ),
			low_tier_troop_( low_tier_num, Tier::LOW, x, y ){}
	int get_high_tier_quantity() const { return high_tier_troop_.get_quantity(); }
	int get_mid_tier_quantity() const { return mid_tier_troop_.get_quantity(); }
	int get_low_tier_quantity() const { return low_tier_troop_.get_quantity(); }
	void kill_high_tier( int quantity ){ high_tier_troop_.kill( quantity ); }
	void kill_mid_tier( int quantity ){ mid_tier_troop_.kill( quantity ); }
	void kill_low_tier( int quantity ){ low_tier_troop_.kill( quantity ); }
	void vanish(){ high_tier_troop_.vanish(); mid_tier_troop_.vanish(); low_tier_troop_.vanish(); }
};

}//end namespace

#endif /* BOT_MODEL_ARMY_HPP_ */
