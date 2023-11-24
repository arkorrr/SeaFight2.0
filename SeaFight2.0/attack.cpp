#include "Directives.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Bot.h"
#include "Player.h"


using namespace std;


bool isShipDestroyed(int player, int x, int y, char map1[FIELD_SIZE][FIELD_SIZE], const char SHIP_CELL) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < FIELD_SIZE && newY >= 0 && newY < FIELD_SIZE && map1[newY][newX] == SHIP_CELL) {
                return false;
            }
        }
    }
    return true;
}

bool areAllShipsDestroyed(int player, char map1[FIELD_SIZE][FIELD_SIZE],const char SHIP_CELL) {
    for (int y = 0; y < FIELD_SIZE; y++) {
        for (int x = 0; x < FIELD_SIZE; x++) {
            if (map1[y][x] == SHIP_CELL) {
                return false;
            }
        }
    }
    return true;
}

bool attack(int player, int x, int y, char map1[FIELD_SIZE][FIELD_SIZE],const char SHIP_CELL, const char HIT_CELL,const char MISS_CELL) {
    if (map1[y][x] == SHIP_CELL) {
        map1[y][x] = HIT_CELL;
        cout << "Попадание" << endl;
        if (isShipDestroyed(player, x, y, map1, SHIP_CELL)) {
            cout << "Корабль уничтожен" << endl;
        }
        return true;
    }
    else {
        map1[y][x] = MISS_CELL;
        cout << "Промах" << endl;
        return false;
    }
}

void botTurn(int player, char map1[FIELD_SIZE][FIELD_SIZE], const char SHIP_CELL, const char HIT_CELL, const char MISS_CELL,const char EMPTY_CELL) {
    int x, y;
    do {
        x = rand() % FIELD_SIZE;
        y = rand() % FIELD_SIZE;
    } while (map1[y][x] != EMPTY_CELL);

    if (attack(player,x,y,map1,SHIP_CELL,HIT_CELL, MISS_CELL)) 
    {
        cout << "Бот атаковал позицию (" << x << ", " << y << ")" << endl;
        if (areAllShipsDestroyed(1 - player, map1, SHIP_CELL)) 
        {
            cout << "Бот победил!" << endl;
            return;
        }
    }
}

void gameLoop(char map2[FIELD_SIZE][FIELD_SIZE],char map1[FIELD_SIZE][FIELD_SIZE],const char symbol[FIELD_SIZE], const char SHIP_CELL, const char HIT_CELL, const char MISS_CELL,const char EMPTY_CELL)
{
    int player = 0;
    int x = 0, y = 0;
    while (true) {
        system("cls");
        PrintField(map1, symbol);
        PrintFieldBot(map2, symbol);

        if (player == 0) {
            cout << "Ход игрока. Используйте WASD или стрелки для выбора клетки, SPACE или ENTER для атаки." << endl;
            char ch = _getch();
            switch (ch) {
            case 'w':
            case UP:
                if (y > 0) y--;
                break;
            case 's':
            case DOWN:
                if (y < FIELD_SIZE - 1) y++;
                break;
            case 'a':
            case LEFT:
                if (x > 0) x--;
                break;
            case 'd':
            case RIGHT:
                if (x < FIELD_SIZE - 1) x++;
                break;
            case ' ':
            case ENTER:
                if (attack(player, x, y, map1, SHIP_CELL, HIT_CELL, MISS_CELL)) {
                    cout << "Игрок атаковал позицию (" << x << ", " << y << ")" << endl;
                    if (areAllShipsDestroyed(1 - player, map1,SHIP_CELL)) {
                        cout << "Игрок победил!" << endl;
                        return;
                    }
                }
                player = 1 - player;
                break;
            }
        }
        else {
            cout << "Ход бота." << endl;
            botTurn(player, map1, SHIP_CELL, HIT_CELL, MISS_CELL, EMPTY_CELL);
            player = 1 - player;
        }
    }
}