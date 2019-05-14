//============================================================================
// Name        : lab_3.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bot/screen_capture.hpp"
using namespace std;

int main() {
	model::GameState game;
	bot::ScreenCapture screen;
	screen.capture_screen( game );
	game.my_castle_.print();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	game.enemy_castle_.print();
	return 0;
}
