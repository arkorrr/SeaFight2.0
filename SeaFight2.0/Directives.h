#pragma once  // Директива препроцессора отвечающая за то,
			  //что заголовочный файл будет включен только один раз и не более.

#define rows 10  // Определение количества строк на игровом поле
#define cols 10  // Определение количества столбцов на игровом поле
#define FIELD_SIZE 10  // Определение размера игрового поля

#include <windows.h>

enum Colors { LightBlue = 9, GREEN = 10,Red = 11,Blue};  // Цвета в консоли
enum code { ENTER = 13, ESCAPE = 27, SPACE = 32, LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72 }; // Коды клавиш для ввода

const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);   // Для управления выводом на консоль