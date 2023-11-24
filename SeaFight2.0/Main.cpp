#include "Main.h"
#include "Windows.h"
#include "Directives.h"
#include "Player.h"
#include "Bot.h"
#include "attack.h"

void GotoXY(int x, int y)  // Функция для перемещения курсора консоли в указанную позицию (x, y)
{
	COORD myCoords = { x,y };  // Создание структуры COORD с координатами x и y
	SetConsoleCursorPosition(h, myCoords);  // Установка позиции курсора консоли в указанные координаты
}

void vsbot_random()  // Функция для случайного размещения кораблей в игре против бота
{
	system("CLS");
	char map1[FIELD_SIZE][FIELD_SIZE];	  // Создание двумерного массива для хранения игрового поля игрока
	char map2[FIELD_SIZE][FIELD_SIZE];	  // Также для бота
	const char symbol[FIELD_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	const char EMPTY_CELL = '.';  // Символ для обозначения пустой ячейки на игровом поле
	const char SHIP_CELL = 'N';  // Символ для обозначения ячейки с кораблем на игровом поле
	const char HIT_CELL = 'X';  // Символ для обозначения попадания в корабль
	const char MISS_CELL = '*';  // Символ для обозначения промаха
	Field(map1, EMPTY_CELL);
	randomShip(map1, EMPTY_CELL, SHIP_CELL);
	randomPlaceShip(map1, 0, EMPTY_CELL, SHIP_CELL);
	PrintField(map1, symbol);

	FieldBot(map2, EMPTY_CELL);
	randomShipBot(map2, EMPTY_CELL, SHIP_CELL);
	randomPlaceShipBot(map2, 0, EMPTY_CELL, SHIP_CELL);
	PrintFieldBot(map2, symbol);
	gameLoop(map2, map1, symbol, SHIP_CELL, HIT_CELL, MISS_CELL, EMPTY_CELL);
}

void vsbot_own()  // Функция для размещения кораблей пользователем в игре против бота
{
	system("CLS");
	char map1[FIELD_SIZE][FIELD_SIZE];  // Создание двумерного массива для хранения игрового поля игрока
	char map2[FIELD_SIZE][FIELD_SIZE];  // Также для бота
	const char symbol[FIELD_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	const char EMPTY_CELL = '.';  // Символ для обозначения пустой ячейки на игровом поле
	const char SHIP_CELL = 'N';   // Символ для обозначения ячейки с кораблем на игровом поле
	const char HIT_CELL = 'X';	  // Символ для обозначения попадания в корабль
	const char MISS_CELL = '*';	  // Символ для обозначения промаха

	place(map1, symbol, EMPTY_CELL);
	FieldBot(map2, EMPTY_CELL);
	randomShipBot(map2, EMPTY_CELL, SHIP_CELL);
	randomPlaceShipBot(map2, 0, EMPTY_CELL, SHIP_CELL);
	PrintFieldBot(map2, symbol);

	FieldBot(map2, EMPTY_CELL);
	randomShipBot(map2, EMPTY_CELL, SHIP_CELL);
	randomPlaceShipBot(map2, 0, EMPTY_CELL, SHIP_CELL);
	PrintFieldBot(map2, symbol);
	gameLoop(map2, map1, symbol, SHIP_CELL, HIT_CELL, MISS_CELL, EMPTY_CELL);

}

