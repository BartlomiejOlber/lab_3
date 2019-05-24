/*
 * test_guarded_building.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/bot/model/guarded_building.hpp"

namespace test {

using namespace model;

SCENARIO( "model guarded building usage" ) {

    GIVEN( "a default guarded building is created with certain parameters" ) {

    	Tier building_tier( Tier::MEDIUM );
    	Status building_status( Status::ENEMY );
    	int guards_number = 100;
    	Tier guards_tier( Tier::HIGH );
    	int x = 10;
    	int y = 10;
    	GuardedBuilding guarded_building( building_tier, building_status, guards_number, guards_tier, x, y );
    	THEN( "its guards force equals their quantity * their tier factor" )
    		REQUIRE( guarded_building.count_guards_force() == guards_number*Troop::HIGH_TIER_FACTOR );
        WHEN( "the building is conquered" ) {

        	guarded_building.conquer();
        	THEN( " its status is Friend and has no guards" ) {
                REQUIRE( guarded_building.get_status() == Status::FRIEND );
                REQUIRE( guarded_building.count_guards_force() == 0 );
            }
        }
    }
}

}// end namespace test

