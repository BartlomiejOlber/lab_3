/*
 * test_game_object.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/bot/model/game_object.hpp"

namespace test {

using namespace model;

SCENARIO( "model game object usage" ) {

    GIVEN( "object A with coordinates 10,5 and object B with coordinates 20, 40" ) {

    	GameObject A( 10, 5);
    	GameObject B( 20, 40);
    	int initial_distance = A.get_distance(B);
        WHEN( "B coordinates are set to 15, 10" ) {

        	B.set_coordinates( 15,10 );
        	THEN( "the distance between A and B decreased" ) {
                REQUIRE( A.get_distance(B) < initial_distance );
            }
        }
    }
}

}// end namespace test


