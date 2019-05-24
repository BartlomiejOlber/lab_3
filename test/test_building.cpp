/*
 * test_building.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */


#include "catch.hpp"
#include "../src/bot/model/building.hpp"

namespace test {

using namespace model;

SCENARIO( "model building usage" ) {

    GIVEN( "a default building is created" ) {

    	Building building;
        WHEN( "control over the building is taken" ) {

        	building.take_control();
        	THEN( " the building has Friend status" ) {
                REQUIRE( building.get_status() == Status::FRIEND );
            }
        }
    }
}

}// end namespace test

