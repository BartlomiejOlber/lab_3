/*
 * test_hero.cpp
 *
 *  Created on: May 24, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/bot/model/hero.hpp"
#include "../src/bot/model/gold.hpp"

namespace test {

using namespace model;

SCENARIO( "model hero usage" ) {

    GIVEN( "a hero with certain parameters, gold with certain paremeters" ) {

    	int hero_gold = 1000, hero_level = 10, hero_high_tier_army_number = 10, hero_mid_tier_army_numer = 20,
    			hero_low_tier_army_number = 30, hero_x = 40, hero_y = 50, gold_quantity = 500, gold_x = 20, gold_y = 30;
    	Status hero_status = Status::FRIEND;
    	Hero hero( hero_gold, hero_level, hero_high_tier_army_number, hero_mid_tier_army_numer, hero_low_tier_army_number,
    	 	 hero_x, hero_y, hero_status );
    	Gold gold( gold_quantity, gold_x, gold_y );
    	int initial_hero_force = hero.count_hero_force();

        WHEN( "the hero travels to the gold and picks it up" ) {

        	hero.travel_to( gold );
        	hero.pick_up_gold( gold.get_quantity() );
        	THEN( "hero coordinates are the same as the gold's and his gold amount is higher" ) {
        		REQUIRE( hero.get_x() == gold.get_x() );
        		REQUIRE( hero.get_y() == gold.get_y() );
        		REQUIRE( hero.get_gold() == gold.get_quantity() + hero_gold );
            }
        }
        WHEN( "some of the hero's army is killed" ) {

        	hero.kill( 100 );
        	THEN( "his force is decreased" ) {
        		REQUIRE( hero.count_hero_force() < initial_hero_force );
            }
        }
        WHEN( "the hero is killed" ){
        	hero.kill();
        	THEN( "he is not alive" ) {
        		REQUIRE( !hero.is_alive() );
            }
        }
    }
}

}// end namespace test


