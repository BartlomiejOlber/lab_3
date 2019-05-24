/*
 * test_screen_capture.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */


#include "catch.hpp"
#include "../src/bot/screen_capture.hpp"

namespace test {

using namespace bot;

SCENARIO( "screen capture mock object test" ) {

    GIVEN( "screen capture class object, empty game state structure" ) {

    	model::GameState game_state;
    	ScreenCapture screen_capture;

    	REQUIRE( game_state.buildings_.empty() );
    	REQUIRE( game_state.guarded_buildings_.empty() );
    	REQUIRE( game_state.map_gold_.empty() );
    	REQUIRE( game_state.map_troops_.empty() );

        WHEN( " the mock object captures the screen" ) {

        	screen_capture.capture_screen( game_state );
        	THEN( "map gold vector is not empty" ) {
                REQUIRE( !game_state.map_gold_.empty() );
            }
        	THEN( "map troops vector is not empty" ) {
                REQUIRE( !game_state.map_troops_.empty() );
            }
        	THEN( "map buildings vector is not empty" ) {
                REQUIRE( !game_state.buildings_.empty() );
            }
        }
    }
}

}// end namespace test

