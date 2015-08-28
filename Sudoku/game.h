#pragma once

#include <iostream>
#include "tools.h"
#include <Windows.h>
#include <string>
#include <list>
#include <random>

#define WHITE 7
#define GREEN 10
#define RED 12

class Game
{
public:
	Game();
	~Game();

	void WriteToBoard( unsigned short value,unsigned short &index );
	unsigned short GetFromBoard( unsigned short index ) const;
	void WriteToMatte( unsigned short value,unsigned short &index );
	unsigned short GetFromMatte( unsigned short index ) const;
private:
	bool CanBePlaced( /**/unsigned short &x,unsigned short &y,unsigned short &value );
	void Intro(); 
	void SetBoard();//
	void MakeStartingNums();//
	unsigned short CalculateDifficulty();
	void Logic(); 
	void Move(); 
	bool Finished();
	void CheckForWin();
	void PlayAgain();
private:
	unsigned short *board = new unsigned short[ 81 ]; 		
	unsigned short *matte = new unsigned short[ 81 ];
	
	unsigned short difficulty; 
};

