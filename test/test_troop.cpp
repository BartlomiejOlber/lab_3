/*
 * test_troop.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/bot/model/troop.hpp"

namespace test {

using namespace model;

SCENARIO( "model troop usage" ) {

    GIVEN( "a high tier troop of 100 entities is created" ) {
    	int entities_num = 100;
    	Tier tier = Tier::HIGH;
    	int x = 10, y = 10;
    	Troop troop( entities_num, tier, x, y );

    	REQUIRE( troop.get_tier() == tier );

    	THEN( " troop force equals entities number * high tier factor" ) {
            REQUIRE( troop.count_troop_force() == troop.get_quantity() * Troop::HIGH_TIER_FACTOR );
        }
        WHEN( " 5 entities are recruited and then 6 are killed " ) {

        	troop.recruit( 5 );
        	troop.kill( 6 );
        	THEN( " troop quantity is 99" ) {
                REQUIRE( troop.get_quantity() == 99 );
            }
        }

    }
}

}// end namespace test


