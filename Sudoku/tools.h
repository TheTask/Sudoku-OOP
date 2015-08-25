#pragma once

#include "game.h"

class Game;

class Tools
{
	Tools();
public:
	void ShowBoard(); 
	void NormaliseBoard(); //Sets all values on board to 0
	void WipeConsole(); //because I don't want drawing new boards below each other on next move, I better wipe console and redraw
private:
	Game &game;
};