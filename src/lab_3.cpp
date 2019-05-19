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
	model::GameState game;
	model::ActionScenario action;
	bot::ScreenCapture screen;
	screen.capture_screen( game );
	brain::Brain brain(game);
	game.my_castle_.print();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	game.enemy_castle_.print();
	for( auto it = game.buildings_.begin(); it != game.buildings_.end(); ++it ){
		cout<<"\n\t x,y,t,s"<<it->get_x()<<" "<<it->get_y()<<" "<<static_cast<int>(it->get_tier())<<" "<<static_cast<int>(it->get_status());
	}
	brain.play_round( action );
	cout<<"\n\n actons "<< action.size()<<endl;
	return 0;
}
