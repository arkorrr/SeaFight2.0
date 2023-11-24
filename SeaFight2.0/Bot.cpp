#include "Directives.h"
#include <iostream>
#include "Main.h";
#include "Bot.h"

using namespace std;	


void FieldBot(char map2[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL)			//��������� ���� �������� ��� ��� ����.
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			map2[i][j] = EMPTY_CELL;
		}
	}
}

void PrintFieldBot(char map2[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE])		//������� ���� �������� ��� � ������������.
{
	GotoXY(50, 0);
	for (char i = 0; i < FIELD_SIZE; i++)
	{
		cout << symbol[i] << " ";
	}
	for (int i = 0; i < rows; i++)
	{
		GotoXY(48, 1 + i);
		cout << i << " ";
		for (int j = 0; j < cols; j++)
		{
			cout << map2[i][j] << " ";
		}
		cout << endl;
	}
}

bool isValidPositionBot(int x, int y)		//��������, ���������� �� ���������� ����������� � ���� �������� ���.
{
	return (x >= 0 && x < FIELD_SIZE && y >= 0 && y < FIELD_SIZE);
}

bool isCellEmptyBot(const char map2[][FIELD_SIZE], int row, int col, const char EMPTY_CELL) //��������, ������ �� ������.
{
	return (map2[row][col] == EMPTY_CELL);
}

bool isNeighbourCellEmptyBot(int row, int col, const char map2[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL)		//��������, ������ �� ��������� ������.
{
	for (int i = row - 1; i <= row + 1; ++i)
	{
		for (int j = col - 1; j <= col + 1; ++j)
		{
			if (isValidPositionBot(i, j) && !isCellEmptyBot(map2, i, j, EMPTY_CELL))
			{
				return false;
			}
		}
	}
	return true;
}

bool randomPlaceShipBot(char map2[FIELD_SIZE][FIELD_SIZE], int size, const char EMPTY_CELL, const char SHIP_CELL)
{
	int startRow, startCol;				//�������� �� ����������� ��������.����������� �� ��������� ��� �� ������������.
	bool isVertical = (rand() % 2 == 0);

	if (isVertical)
	{
		startRow = rand() % (FIELD_SIZE - size + 1);
		startCol = rand() % FIELD_SIZE;
	}
	else
	{
		startRow = rand() % FIELD_SIZE;
		startCol = rand() % (FIELD_SIZE - size + 1);
	}

	for (int i = 0; i < size; ++i)		//���������� ������� ��������.���������,����� �� ������� �� ������ �������.
	{
		int row = startRow + (isVertical ? i : 0);
		int col = startCol + (isVertical ? 0 : i);

		if (!isValidPositionBot(row, col) || !isNeighbourCellEmptyBot(row, col, map2, EMPTY_CELL))
		{
			return false;
		}
	}

	for (int i = 0; i < size; ++i)		//����������� ��������.
	{
		int row = startRow + (isVertical ? i : 0);
		int col = startCol + (isVertical ? 0 : i);

		map2[row][col] = SHIP_CELL;
	}
	return true;
}

void randomShipBot(char map2[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL, const char SHIP_CELL)
{
	int shipSizes[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
	int numShips = sizeof(shipSizes) / sizeof(shipSizes[0]);
	int size = 0;
	for (int i = 0; i < numShips; ++i)		//���������� ������ �� �������.
	{
		int size = shipSizes[i];		//������ ������� ���� �� �������.
		bool placed = false;
		while (!placed)
		{
			placed = randomPlaceShipBot(map2, size, EMPTY_CELL, SHIP_CELL);			//���� �������� True, ���� ������������� ���������, ���� ��� �� ����� �����������.
		}
	}
}