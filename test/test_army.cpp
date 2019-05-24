/*
 * test_army.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/bot/model/army.hpp"

namespace test {

using namespace model;

SCENARIO( "model army usage" ) {

    GIVEN( "an army is created with certain parameters" ) {

    	int high_tier_soldiers_number = 10;
    	int mid_tier_soldiers_number = 100;
    	int low_tier_soldiers_number = 1000;
    	int x = 10;
    	int y = 10;

    	Army army( high_tier_soldiers_number, mid_tier_soldiers_number, low_tier_soldiers_number, x, y);
    	int initial_army_force = army.count_army_force();
        WHEN( "3 high tier soldiers are recruited" ) {

        	army.recruit_high_tier( 3 );
        	THEN( "army force is increased 3*high tier factor" ) {
                REQUIRE( initial_army_force + 3*Troop::HIGH_TIER_FACTOR == army.count_army_force() );
            }
        }
        WHEN( "2 mid tier soldiers are killed" ) {
        	army.kill_mid_tier( 2*Troop::MID_TIER_FACTOR );
        	THEN( "army force is decreased 2*mid tier factor" ) {
                REQUIRE( initial_army_force - 2*Troop::MID_TIER_FACTOR == army.count_army_force() );
            }
        }
    }
}

}// end namespace test
