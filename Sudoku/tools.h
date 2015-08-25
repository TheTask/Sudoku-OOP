#pragma once

#include "game.h"

class Game;

namespace Tools 
{
void ShowBoard( Game &game ); 
void NormaliseBoard( Game &game ); //Sets all values on board to 0
void WipeConsole(); //because I don't want drawing new boards below each other on next move, I better wipe console and redraw
}