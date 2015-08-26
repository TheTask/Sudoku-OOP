#pragma once

#include <iostream>
#include "tools.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <random>

class Game
{
public:
	Game();
	~Game();

	void WriteToBoard( unsigned short value,unsigned short &index );
	unsigned short GetFromBoard( unsigned short index ) const;
private:
	bool CanBePlaced( unsigned short &x,unsigned short &y,unsigned short &value );
	void Intro(); 
	void MakeStartingNums();
	unsigned short CalculateDifficulty();
	void Logic(); 
	void Move(); 
private:
	unsigned short *board = new unsigned short[ 81 ]; 						 
	
	unsigned short x;
	unsigned short y; 
	unsigned short value; 
	unsigned short difficulty; 
};

