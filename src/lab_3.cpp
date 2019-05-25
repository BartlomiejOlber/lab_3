//============================================================================
// Name        : lab_3.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bot/brain.hpp"
#include "bot/screen_capture.hpp"
using namespace std;

int main() {
	model::GameState game_state;
	model::ActionScenario action_scenario;
	bot::ScreenCapture bot_screen_capture;
	bot_screen_capture.capture_screen( game_state );
	brain::Brain brain( game_state );
	cout<<"\nmy hero start x: " << game_state.my_hero.get_x() << " y: "<< game_state.my_hero.get_y() << endl;
	brain.play_round( action_scenario );
	cout << "\n Bot made following decisions: "<< endl;
	for( auto it = action_scenario.begin(); it != action_scenario.end(); ++it ){
		it->get()->print();
	}
	return 0;
}
