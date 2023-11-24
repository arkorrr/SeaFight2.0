#include "Directives.h"
#include "Main.h";
#include <iostream>
#include "Player.h"
#include <Windows.h>
#include <conio.h>

using namespace std;

void Field(char map1[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL)  // Функция для заполнения игрового поля пустыми ячейками
{
	// Двойной цикл для прохода по всем ячейкам поля
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			map1[i][j] = EMPTY_CELL;
		}
	}
}

void PrintField(char map1[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE]) // Функция для вывода игрового поля с координатами
{

	// Циклы для вывода координат и значений ячеек поля
	GotoXY(2, 0);
	for (char i = 0; i < FIELD_SIZE; i++)
	{
		cout << symbol[i] << " ";
	}
	for (int i = 0; i < rows; i++)
	{
		GotoXY(0, 1 + i);
		cout << i << " ";
		for (int j = 0; j < cols; j++)
		{
			cout << map1[i][j] << " ";
		}
		cout << endl;
	}
}

bool isValidPosition(int x, int y)	// Функция для проверки, находится ли координата в пределах игрового поля
{
	return (x >= 0 && x < FIELD_SIZE && y >= 0 && y < FIELD_SIZE);
}

bool isCellEmpty(const char map1[][FIELD_SIZE], int row, int col, const char EMPTY_CELL)  // Функция для проверки, является ли ячейка пустой
{
	return (map1[row][col] == EMPTY_CELL);
}

bool isNeighbourCellEmpty(const char map1[][FIELD_SIZE], int row, int col, const char EMPTY_CELL)	// Функция для проверки, являются ли соседние ячейки пустыми
{
	// Циклы для проверки всех соседних ячеек
	for (int i = row - 1; i <= row + 1; ++i)
	{
		for (int j = col - 1; j <= col + 1; ++j)
		{
			if (isValidPosition(i, j) && !isCellEmpty(map1, i, j, EMPTY_CELL))
			{
				return false;
			}
		}
	}
	return true;
}

bool randomPlaceShip(char map1[][FIELD_SIZE], int size, const char EMPTY_CELL, const char SHIP_CELL)    // Функция для случайного размещения корабля на поле
{

	// Код для выбора начальной позиции и ориентации корабля, а также проверки возможности его размещения
	int startRow, startCol;				
	bool isVertical = (rand() % 2 == 0);   // Определение ориентации корабля (вертикальной или горизонтальной)

	if (isVertical)
	{
		startRow = rand() % (FIELD_SIZE - size + 1);   //Выбор случайной начальной строки, учитывая размер корабля
		startCol = rand() % FIELD_SIZE;     // Выбор случайной начальной колонки
	}
	else
	{
		startRow = rand() % FIELD_SIZE;      // Выбор случайной начальной строки
		startCol = rand() % (FIELD_SIZE - size + 1);     // Выбор случайной начальной колонки, учитывая размер корабля
	}
	 
	for (int i = 0; i < size; ++i)   // Цикл для проверки каждой ячейки, которую займет корабль
	{
		int row = startRow + (isVertical ? i : 0);    //Вычисление строки ячейки
		int col = startCol + (isVertical ? 0 : i);    //Вычисление колонки ячейки
		 
		if (!isValidPosition(row, col) || !isNeighbourCellEmpty(map1, row, col, EMPTY_CELL)) //Если ячейка недопустима или соседняя ячейка не пуста
		{
			return false;
		}
	}

	for (int i = 0; i < size; ++i)    // Цикл для размещения корабля
	{
		int row = startRow + (isVertical ? i : 0);     //Вычисление строки ячейки
		int col = startCol + (isVertical ? 0 : i);     //Вычисление колонки ячейки

		map1[row][col] = SHIP_CELL;
	}
	return true;
}

void randomShip(char map1[][FIELD_SIZE], const char EMPTY_CELL, const char SHIP_CELL)    //Функция для случайного размещения всех кораблей на поле
{

	// Цикл для размещения кораблей разных размеров
	int shipSizes[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
	int numShips = sizeof(shipSizes) / sizeof(shipSizes[0]);
	int size = 0;
	for (int i = 0; i < numShips; ++i)	
	{
		int size = shipSizes[i];
		bool placed = false;
		while (!placed)
		{
			placed = randomPlaceShip(map1, size, EMPTY_CELL, SHIP_CELL);
		}
	}
}

bool canPlaceShip(char map[FIELD_SIZE][FIELD_SIZE], int x, int y, int size, bool vertical)    // Функция для проверки возможности размещения корабля в определенной позиции
{    
	// Цикл для проверки всех ячеек, которые займет корабль
	for (int i = 0; i < size; i++) {
		if (vertical) {
			if (y + i >= FIELD_SIZE || !isValidCell(map, x, y + i))
				return false;
		}
		else {
			if (x + i >= FIELD_SIZE || !isValidCell(map, x + i, y))
				return false;
		}
	}

	return true;
}

bool isValidCell(char map[FIELD_SIZE][FIELD_SIZE], int x, int y)   // Функция для проверки, является ли ячейка допустимой для размещения корабля
{   
	// Циклы для проверки всех соседних ячеек
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (x + i >= 0 && x + i < FIELD_SIZE && y + j >= 0 && y + j < FIELD_SIZE && map[y + j][x + i] == '#')   // Если ячейка находится в пределах игрового поля и содержит корабль ('#'), то ячейка считается недопустимой
				return false;

	return true;
}

void placeShip(char map[FIELD_SIZE][FIELD_SIZE], int x, int y, int size, bool vertical)     //Функция для размещения корабля в определенной позиции
{

	// Цикл для заполнения ячеек, которые займет корабль
	for (int i = 0; i < size; i++) {
		if (vertical)
			map[y + i][x] = '#';
		else
			map[y][x + i] = '#';
	}
}


void place(char map[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE], const char EMPTY_CELL)    // Функция для размещения всех кораблей игрока на поле
{

	SetConsoleTextAttribute(h, GREEN);
	Field(map, EMPTY_CELL);
	int shipSizes[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, };
	int currentShip = 0;
	int x = 0, y = 0;
	bool vertical = true;
	char ch;

	// Цикл для выбора позиции каждого корабля и его размещения на поле
	do {
		system("cls");
		PrintField(map, symbol);

		ch = _getch();
		switch (ch) {
		case 'w':
			if (y > 0) y--;
			break;
		case 's':
			if (y < FIELD_SIZE - 1) y++;
			break;
		case 'a':
			if (x > 0) x--;
			break;
		case 'd':
			if (x < FIELD_SIZE - 1) x++;
			break;
		case 'r':
			vertical = !vertical;
			break;
		case ' ':
			if (currentShip < sizeof(shipSizes) / sizeof(shipSizes[0])) {
				if (canPlaceShip(map, x, y, shipSizes[currentShip], vertical)) {
					placeShip(map, x, y, shipSizes[currentShip], vertical);
					currentShip++;
				}
				else {
					cout << "Cannot place ship here!" << endl;
					Sleep(1000);  // Pause for a moment to show the error message
				}
			}
			break;
		}
	} while (currentShip < sizeof(shipSizes) / sizeof(shipSizes[0]));

}
