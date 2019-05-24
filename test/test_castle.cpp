/*
 * test_castle.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/bot/model/castle.hpp"

namespace test {

using namespace model;

SCENARIO( "model castle usage" ) {

    GIVEN( "a default castle is created" ) {

    	Castle castle;
    	double initial_defence_bonus = castle.defence_bonus();
        WHEN( "10 high tier soldiers are recruited" ) {

        	castle.recruit_high_tier( 10 );
        	THEN( "castle force is equal or higher than 10*high tier factor" ) {
                REQUIRE( castle.count_castle_force() >= 10*Troop::HIGH_TIER_FACTOR );
            }
        }
        WHEN(" 5  mid tier buildings are built"){
        	castle.build_mid_tier();
        	castle.build_mid_tier();
        	castle.build_mid_tier();
        	castle.build_mid_tier();
        	castle.build_mid_tier();
        	THEN(" castle defence bonus is increased "){
        		REQUIRE( castle.defence_bonus() > initial_defence_bonus );
        	}
        	THEN(" further mid tier buildings development is not available"){
        		REQUIRE( !castle.is_development_available_mid() );
        	}
        }
        WHEN(" the castle is conquered "){
        	castle.conquer();
        	THEN(" castle status is Friend and its force = 0"){
        		REQUIRE( castle.get_status() == Status::FRIEND );
        		REQUIRE( castle.count_castle_force() == 0 );
        	}
        }
    }
}

}// end namespace test


