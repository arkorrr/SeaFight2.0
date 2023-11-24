#pragma once // Директива препроцессора отвечающая за то,
			 //что заголовочный файл будет включен только один раз и не более.

void Field(char map1[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL);  // Объявление функции для заполнения игрового поля пустыми ячейками

void PrintField(char map1[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE]);  // Объявление функции для вывода игрового поля с координатами

bool isValidPosition(int x, int y);  // Объявление функции для проверки, находится ли координата в пределах игрового поля

bool isCellEmpty(const char map1[][FIELD_SIZE], int row, int col, const char EMPTY_CELL);   // Объявление функции для проверки, является ли ячейка пустой

bool isNeighbourCellEmpty(const char map1[][FIELD_SIZE], int row, int col, const char EMPTY_CELL);  // Объявление функции для проверки, являются ли соседние ячейки пустыми

bool randomPlaceShip(char map1[][FIELD_SIZE], int size, const char EMPTY_CELL, const char SHIP_CELL);  // Объявление функции для случайного размещения корабля на поле

void randomShip(char map1[][FIELD_SIZE], const char EMPTY_CELL, const char SHIP_CELL);  // Объявление функции для случайного размещения всех кораблей на поле

bool canPlaceShip(char map[FIELD_SIZE][FIELD_SIZE], int x, int y, int size, bool vertical);  // Объявление функции для проверки возможности размещения корабля в определенной позиции

bool isValidCell(char map[FIELD_SIZE][FIELD_SIZE], int x, int y);  // Объявление функции для проверки, является ли ячейка допустимой для размещения корабля

void placeShip(char map[FIELD_SIZE][FIELD_SIZE], int x, int y, int size, bool vertical);  // Объявление функции для размещения корабля в определенной позиции

void place(char map[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE], const char EMPTY_CELL);  // Объявление функции для размещения всех кораблей игрока на поле
