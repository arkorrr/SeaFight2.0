#pragma once
#include "Directives.h"

bool isShipDestroyed(int player, int x, int y, char map1[FIELD_SIZE][FIELD_SIZE], const char SHIP_CELL);
bool areAllShipsDestroyed(int player, char map1[FIELD_SIZE][FIELD_SIZE], const char SHIP_CELL);
bool attack(int player, int x, int y, char map1[FIELD_SIZE][FIELD_SIZE], const char SHIP_CELL, const char HIT_CELL, const char MISS_CELL);
void botTurn(int player, char map1[FIELD_SIZE][FIELD_SIZE], const char SHIP_CELL, const char HIT_CELL, const char MISS_CELL, const char EMPTY_CELL);
void gameLoop(char map2[FIELD_SIZE][FIELD_SIZE], char map1[FIELD_SIZE][FIELD_SIZE], const char symbol[FIELD_SIZE], const char SHIP_CELL, const char HIT_CELL, const char MISS_CELL, const char EMPTY_CELL);