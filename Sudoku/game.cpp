#include "Game.h"

Game::Game()
:
tool( tool )
{
	tool.WipeConsole(); //proof that Game can use object 'tool', because it won't cause error, even though it is not needed here
	Intro();
	Logic();
}

Game::~Game()
{
	delete[] board;
}

void Game::Intro()
{
	std::cout << "Sudoku by Marek Borik\n\n"
		
		"Choose difficulty:\n" //not implemented yet
		"1: East\n"
		"2: Medium\n"
		"3: Hard\n"
		"4: Expert\n\n";

	std::cin >> difficulty;
	if( !( 0 < difficulty && difficulty < 5 ) )
	{
		tool.WipeConsole();
		Intro();
	}
}

void Game::Logic()
{
	tool.NormaliseBoard(); 

	for( ;; )
	{
		tool.WipeConsole();
		tool.ShowBoard();
		Move();
	}
}

void Game::Move()
{
	std::cout << ">  ";
	std::cin >> value >> x >> y;

	if ( !( ( 0 < value  && value <= 9 ) && ( 0 < x  && x <= 9 ) && ( 0 < y  && y <= 9 ) ) )
	{
		Move();	
	}
	board[ ( y - 1 ) * 9 + ( x - 1 ) ] = value;
}

void Game::WriteToBoard( unsigned short value,unsigned short &index )
{
	board[ index ] = value;
}
unsigned short Game::GetFromBoard( unsigned short index )
{
	return board[ index ];
}