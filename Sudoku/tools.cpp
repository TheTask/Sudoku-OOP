#include "tools.h"

Tools::Tools()
	:
	game( game )
{}

void Tools::ShowBoard()
{
	std::cout << "      1   2   3     4   5   6     7   8   9";

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	for( unsigned short i = 1; i <= 9; i++ )
	{
		std::cout << i << "    ";
		for( unsigned short j = 1; j <= 9; j++ )
		{
			if( game.GetFromBoard( ( i - 1 ) * 9 + ( j  - 1 ) ) != 0 )
			{
				std::cout << " " << game.GetFromBoard( ( i - 1 ) * 9 + ( j - 1 ) ) << "  ";
			}
			else
			{
				std::cout << "___ ";
			}
			if( j % 3 == 0 && j != 9 )
			{
				std::cout << "| ";
			}
		}
		std::cout << std::endl;
		if( i % 3 == 0 && i != 9 )
			{
				std::cout << "     ---------------------------------------";
			}
		std::cout << std::endl;
	}
}

void Tools::NormaliseBoard()
{
	for( unsigned short i = 0; i < 81; i++ )
	{
		game.WriteToBoard( 0,i ); //this line of code seems to cause error, game object seems not to be defined
	}
}

void Tools::WipeConsole()
{
	HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	COORD coord = { 0,0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if( GetConsoleScreenBufferInfo( hStdOut,&csbi ) )
	{
		FillConsoleOutputCharacter( hStdOut,(TCHAR)32,csbi.dwSize.X * csbi.dwSize.Y,coord,&count );
		FillConsoleOutputAttribute( hStdOut,csbi.wAttributes,csbi.dwSize.X - 1* csbi.dwSize.Y - 1,coord,&count );
		SetConsoleCursorPosition( hStdOut,coord );
	}
	return;
}
