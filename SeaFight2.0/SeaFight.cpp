#include "Main.h";
#include "Windows.h"
#include "Directives.h"

void options()    // Функция для настройки параметров игры
{
	CONSOLE_CURSOR_INFO cursor;  // Структура, которая содержит информацию о курсоре консоли
	cursor.bVisible = false;     // Видимость курсора на false
	cursor.dwSize = 100;		 // Размер курсора на 100
	SetConsoleCursorInfo(h, &cursor);   // Применение настроек курсора к текущей консоли

	system("title Sea Fight");
}