#pragma once

#include "game.h"

class Game;

namespace Tools 
{
void ShowBoard( Game &game ); 
void NormaliseBoard( Game &game ); 
void WipeConsole(); 
unsigned short RandFromRange( unsigned short min,unsigned short max );
}