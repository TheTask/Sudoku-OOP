#include "Game.h" 

Game::Game()
{
	Intro();
}
Game::~Game()
{
	delete[] board;
}
bool Game::CanBePlaced( unsigned short &x,unsigned short &y,unsigned short &value )
{
	bool canBePlaced = true;

	for( unsigned short i = 0; i < 9; i++ )
	{
		if( board[ i * 9 + x ] == value ) //row
		{
			canBePlaced = false;
		} 
		if( board[ y * 9 + i ] == value ) //col
		{
			canBePlaced = false;
		}
	}
	//block
	unsigned short blockX = x / 3;
	unsigned short blockY = y / 3;
	unsigned short valPos = y * 9 + x;

	for( unsigned short i = 0; i < 3; i++ )
	{
		for( unsigned short j = 0; j < 3; j++ )
		{
			if( board[ ( blockY * 3 + i ) * 9 + ( blockX * 3 + j ) ] == value )
			{
				canBePlaced = false;
			}
		}
	}
	return canBePlaced;
}
void Game::Intro()
{
	std::cout << "Sudoku by Marek Borik\n\n"
		"Play by typing: \"value\" \"Xcoord\" \"Ycoord\" \n\n"
		
		"Choose difficulty:\n" 
		"1: Easy\n"
		"2: Medium\n"
		"3: Hard\n"
		"4: Expert\n\n";

	std::cin >> difficulty;
	if( !( 0 < difficulty && difficulty < 5 ) )
	{
		Tools::WipeConsole();
		Intro();
	}
	Logic();
}
void Game::MakeStartingNums()
{
	for( short i = 0; i < CalculateDifficulty(); i++ )
	{
		unsigned short tempX = Tools::RandFromRange( 0,8 );
		unsigned short tempY = Tools::RandFromRange( 0,8 );
		unsigned short tempVal = Tools::RandFromRange( 1,9 );
	
		if( board[ tempY * 9 + tempX ] == 0  && CanBePlaced( tempX,tempY,tempVal ) )
		{
			board[ tempY * 9 + tempX ] = tempVal;
		}
		else
		{
			i--;
		}
	}
}
unsigned short Game::CalculateDifficulty()
{
	unsigned short finalDifficulty;

	switch( difficulty )
	{
	case 1:
		finalDifficulty = Tools::RandFromRange( 48,53 );
		break;
	case 2:
		finalDifficulty = Tools::RandFromRange( 40,46 );
		break;
	case 3:
		finalDifficulty = Tools::RandFromRange( 33,37 );
		break;
	case 4:
		finalDifficulty = Tools::RandFromRange( 25,28 );
		break;
	default:
		std::cout << "ERROR in CalculateDifficulty()" << std::endl;
	}
	return finalDifficulty;
}
void Game::Logic()
{
	Tools::NormaliseBoard( *this ); 
	//MakeStartingNums();
	SetBoard();
	Tools::CopyToMatte( *this );

	for( ;; )
	{
		Tools::WipeConsole();
		Tools::ShowBoard( *this );
		Move();
		if( Finished() )
		{
			Tools::WipeConsole();
			Tools::ShowBoard( *this );
			CheckForWin();
			break;
		}
	}
}
void Game::Move()
{
	unsigned short x;
	unsigned short y; 
	unsigned short value; 

	Tools::WriteColoredText( WHITE,">  " );
	std::cin >> value >> x >> y;

	if ( !( ( 0 < value  && value <= 9 ) && ( 0 < x  && x <= 9 ) && ( 0 < y  && y <= 9 ) ) )
	{
		Move();	
	}
	if( matte[ ( y - 1 ) * 9 + ( x - 1 ) ] == 0 )
	{	
		board[ ( y - 1 ) * 9 + ( x - 1 ) ] = value;
	}
}
bool Game::Finished()
{
	bool finished = true;
	for( unsigned short i = 0; i < 81; i++ )
	{
		if( board[ i ] == 0 )
		{
			finished = false;
		}
	}
	return finished;
}
void Game::CheckForWin()
{
	bool won = false;

	for( unsigned short i = 0; i < 9; i++ )
	{
		std::list< unsigned short > vecRow = { 1,2,3,4,5,6,7,8,9 };
		std::list< unsigned short > vecCol = { 1,2,3,4,5,6,7,8,9 };

		for( unsigned short j = 0; j < 9; j++ )
		{
			for( unsigned short k = 1; k <= 9; k++ )
			{
				if( k == board[ i * 9 + j ] )
				{
					vecRow.remove( k );
					break;
				}
			}
			for( unsigned short l = 1; l <= 9; l++ )
			{
				if( l == board[ j * 9 + i ] )
				{
					vecCol.remove( l );
					break;
				}
			}
		}
		if( vecRow.empty() && vecCol.empty() )
		{
			won = true;
		}
		else
		{
			won = false;
			break;
		}
	}
	if( won )
	{
		Tools::WriteColoredText( GREEN,"YOU HAVE WON!\n\n" );
		PlayAgain();
	}
	else
	{
		Tools::WriteColoredText( RED,"YOU HAVE LOST!\n\n" );
		PlayAgain();
	}
}
void Game::PlayAgain()
{
	unsigned char c;
	Tools::WriteColoredText( WHITE,"Play again?  y/n\n" );

	std::cin >> c;

	if( c == 'Y' || c == 'y' )
	{
		Tools::WipeConsole();
		Game new_game;
	}
}

void Game::WriteToBoard( unsigned short value,unsigned short &index )
{
	board[ index ] = value;
}
unsigned short Game::GetFromBoard( unsigned short index ) const
{
	return board[ index ];
}
void Game::WriteToMatte( unsigned short value,unsigned short &index )
{
	matte[ index ] = value;
}
unsigned short Game::GetFromMatte( unsigned short index ) const
{
	return matte[ index ];
}

void Game::SetBoard()
{
	unsigned short temp[ 81 ] = { 5,3,4,   6,7,8,   9,1,2, 
		                          6,7,2,   1,9,5,   3,4,8,
								  1,9,8,   3,4,2,   5,6,7,

								  8,5,9,   7,6,1,   4,2,3,
								  4,2,6,   8,5,3,   7,9,1,
								  7,1,3,   9,2,4,   8,5,6,

								  9,6,1,   5,3,7,   2,8,4,
								  2,8,7,   4,1,9,   6,3,5,
								  3,4,5,   2,8,6,   1,0,0   };
	
	for( unsigned short i = 0; i < 81; i++ )
	{
		board[ i ]  = temp[ i ];
	}
}