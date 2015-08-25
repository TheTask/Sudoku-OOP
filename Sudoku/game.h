#pragma once

#include <iostream>
#include "tools.h"
#include <Windows.h>


class Game
{
public:
	Game();
	~Game();

	int main();

	void Intro(); //intro screen with difficulty options, difficulty not implemented yet
	void Logic(); //main logic
	void Move(); 

	void WriteToBoard( unsigned short value,unsigned short &index );
	unsigned short GetFromBoard( unsigned short index );
private:
	unsigned short *board = new unsigned short[ 81 ]; //main sudoku board, only reason why it is on heap is because
													  //I am beginner and I want to practise it

	unsigned short x; //x coord of next move
	unsigned short y; //y coord of next move
	unsigned short value; //value of next move
	unsigned short difficulty; //difficulty, not implemented yet
};

