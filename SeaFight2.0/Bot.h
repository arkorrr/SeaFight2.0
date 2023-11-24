#pragma once
#include "Directives.h";

void FieldBot(char map2[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL);
void PrintFieldBot(char map2[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE]);
bool isValidPositionBot(int x, int y);
bool isCellEmptyBot(const char map2[][FIELD_SIZE], int row, int col, const char EMPTY_CELL); 

bool isNeighbourCellEmptyBot(int row, int col, const char map2[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL);

bool randomPlaceShipBot(char map2[FIELD_SIZE][FIELD_SIZE], int size, const char EMPTY_CELL, const char SHIP_CELL);

void randomShipBot(char map2[FIELD_SIZE][FIELD_SIZE], const char EMPTY_CELL, const char SHIP_CELL);
