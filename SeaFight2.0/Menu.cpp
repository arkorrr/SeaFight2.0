#include "Directives.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Main.h";
#include "Menu.h"
	

using namespace std;

void randomPlaceOrOwnPlace()  // Функция для выбора способа размещения кораблей (случайное или пользовательское)
{	
	// Код для отображения меню и обработки выбора пользователя
	system("CLS");
	const int items_count = 2;
	string menu_items[items_count] = { "Random","Own" };
	int startX = 35;  // Начальная координата X для отображения меню
	int startY = 3;  // Начальная координата Y для отображения меню
	int shift = 2;  // Сдвиг для отображения следующего пункта меню

	COORD position = { startX, startY };
	for (auto item : menu_items) // Цикл для отображения каждого пункта меню
	{
		SetConsoleTextAttribute(h, LightBlue);
		SetConsoleCursorPosition(h, position);
		cout << item;
		position.Y += shift;
	}

	int current_item = 0;  // Текущий выбранный пункт меню
	SetConsoleTextAttribute(h, GREEN);
	position.Y = startY + current_item * shift;
	SetConsoleCursorPosition(h, position);
	cout << menu_items[current_item];

	int code;  // Код нажатой клавиши
	while (true)  // Бесконечный цикл для обработки ввода пользователя
	{
		code = _getch();  // Чтение символа с клавиатуры
		if (code == 224)
			code = _getch();  // Чтение символа с клавиатуры

		SetConsoleTextAttribute(h, LightBlue);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

		if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) // down arrow
		{
			current_item++;
		}
		else if ((code == UP || code == LEFT) && current_item > 0) // up arrow
		{
			current_item--;
		}
		else if (code == ENTER)
		{
			switch (current_item)  // Выбор пользователя
			{
			case 0:
				vsbot_random();
				return;
			case 1:
				vsbot_own();
				return;
			}
		}
		SetConsoleTextAttribute(h, GREEN);  //Установка цвета текста для не выбранных пунктов меню
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];
	}
}

void game_options()  // Функция для отображения настроек игры
{  
	// Отображение меню настроек и обработки выбора пользователя
	system("CLS");
	const int items_count = 3;
	string menu_items[items_count] = { "OPTIONS OF GAME: ", "VSBOT", "BACK" };
	int startX = 35;
	int startY = 3;
	int shift = 2;

	COORD position = { startX, startY };
	for (auto item : menu_items)
	{
		SetConsoleTextAttribute(h, LightBlue);
		SetConsoleCursorPosition(h, position);
		cout << item;
		position.Y += shift;
	}

	int current_item = 0;
	SetConsoleTextAttribute(h, GREEN);
	position.Y = startY + current_item * shift;
	SetConsoleCursorPosition(h, position);
	cout << menu_items[current_item];

	int code;
	while (true)
	{
		code = _getch();
		if (code == 224)
			code = _getch();

		SetConsoleTextAttribute(h, LightBlue);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

		if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) //нажата стрелка вниз или вправо
		{
			current_item++;
		}
		else if ((code == UP || code == LEFT) && current_item > 0) // нажата стрелка вверх или влево 
		{
			current_item--;
		}
		else if (code == ENTER)  // Нажата клавиша Enter
		{
			switch (current_item)  // Выбор пользователя
			{
			case 0:
				break;
			case 1:
				randomPlaceOrOwnPlace();
				return;
			default:
				menu();
				return;
			}
		}
		SetConsoleTextAttribute(h, GREEN);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];
	}
}

void about_author()   // Функция для отображения информации об авторе(ах)
{
	system("CLS");
	const int items_count = 4;
	string menu_items[items_count] = { "The Game Was Created:","Pirhavko Bogdan", "Ilyushchenko Nikita", "BACK" };

	int startX = 35;
	int startY = 3;
	int shift = 2;

	COORD position = { startX, startY };
	for (auto item : menu_items)
	{
		SetConsoleTextAttribute(h, LightBlue);
		SetConsoleCursorPosition(h, position);
		cout << item;
		position.Y += shift;
	}

	int current_item = 0;
	SetConsoleTextAttribute(h, GREEN);
	position.Y = startY + current_item * shift;
	SetConsoleCursorPosition(h, position);
	cout << menu_items[current_item];

	int code;
	while (true)
	{
		code = _getch();  // Чтение символа с клавиатуры
		if (code == 224)
			code = _getch();

		SetConsoleTextAttribute(h, LightBlue);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

		if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) //нажата стрелка вниз или вправо
		{
			current_item++;
		}
		else if ((code == UP || code == LEFT) && current_item > 0) // нажата стрелка вверх или влево 
		{
			current_item--;
		}
		else if (code == ENTER)  // Нажата клавиша Enter
		{
			switch (current_item)  // Выбор пользователя
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				menu();
				return;
			}
		}
		SetConsoleTextAttribute(h, GREEN);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];
	}
}



void menu()  // Главная функция меню
{
	// Код для отображения главного меню и обработки выбора пользователя
	system("CLS");
	const int items_count = 3;
	string menu_items[items_count] = { "START GAME","ABOUT AUTHOR", "EXIT" };

	int startX = 35;
	int startY = 3;
	int shift = 2;

	COORD position = { startX, startY };
	for (auto item : menu_items)
	{
		SetConsoleTextAttribute(h, LightBlue);
		SetConsoleCursorPosition(h, position);
		cout << item;
		position.Y += shift;
	}

	int current_item = 0;
	SetConsoleTextAttribute(h, GREEN);
	position.Y = startY + current_item * shift;
	SetConsoleCursorPosition(h, position);
	cout << menu_items[current_item];

	int code;
	while (true)
	{
		code = _getch();  // Чтение символа с клавиатуры
		if (code == 224)
			code = _getch();  // Чтение символа с клавиатуры

		SetConsoleTextAttribute(h, LightBlue);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

		if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) //нажата стрелка вниз или вправо
		{
			current_item++;
		}
		else if ((code == UP || code == LEFT) && current_item > 0) // нажата стрелка вверх или влево 
		{
			current_item--;
		}
		else if (code == ENTER)  // Нажата клавиша Enter
		{
			switch (current_item)  // Выбор пользователя
			{
			case 0:
				game_options();
				return;
			case 1:
				about_author();
				return;
			default:
				exit(0);
				break;
			}
		}

		SetConsoleTextAttribute(h, GREEN);
		position.Y = startY + current_item * shift;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

	}
}
