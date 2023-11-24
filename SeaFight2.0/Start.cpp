#include "Main.h";
#include "Windows.h"
#include <ctime>
#include "SeaFight.h"
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include "Directives.h"

using namespace std;

int main()   // Главная функция запуска
{
	SetConsoleTextAttribute(h, Blue);
	cout << "Rules of the game in sea battle" << endl << endl;
	SetConsoleTextAttribute(h, Red);
	setlocale(LC_ALL, "RUS");
	cout << "Two players or against bot. The rules of naval combat say there must be:" << endl;
	cout << "4 ships of one cell each (single-deck);" << endl;
	cout << "3 ships of 2 cells each (double-decked);" << endl;
	cout << "2 ships of 3 cells;" << endl;
	cout << "1 ship - four-decked." << endl;
	cout << "Ships are placed on the game board in such a way that there is always a gap of one cell between them" << endl;
	cout << "Ships may touch the edges of the field and occupy corners.When the ships are arranged, players take turns firing shots, selecting an area in the field" << endl;
	cout <<	"If a shot is fired into an unoccupied area of the opponent's ship, the opponent takes the turn." << endl;
	cout << "If the shot is fired into an area where a ship is located, the player who fired the shot is" << endl;
	cout << "entitled to another shot." << endl;
	cout << "keys:" << endl;
	cout << "WASD or KEYS on keyboard to place the ships on board." << endl;
	cout << "SPACE or ENTER to shoot." << endl << endl;
	cout << "Enter 'q' to start game.";
	char start = 0;
	while (start != 'q')
	{
		start = _getch();
		switch (start)
		{
		case 'q':
			SetConsoleOutputCP(1251);
			SetConsoleCP(1251);
			srand(time(0));
			options();
			menu();
			Sleep(INFINITE);   // Приостановка выполнения программы до закрытия вручную
		default:
			break;
		}
	}
}

