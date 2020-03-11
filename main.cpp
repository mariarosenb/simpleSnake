
#include <iostream>
#include <ctime>
#include "windows.h"
#include "game.h"

using namespace std;

void hideCursor() {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
}

int main() {
	srand(time(nullptr));
	hideCursor();

	game game;
	game.play();

	return 0;
}