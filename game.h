
#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "snake.h"
#include "food.h"

using namespace std;

void showChar(int x, int y, char character) {
	COORD cord;
	cord.X = x * 3;
	cord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << character;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

class game {
	const int width = 30;
	const int heigth = 30;

	Snake snake;
	food food;

	vector < vector < int >> map;
	vector < vector < int >> showMap;
	bool start = false;

public:
	game() {
		map = vector < vector < int >> (heigth, vector < int > (width, 0));
		showMap = vector < vector < int >> (heigth, vector < int > (width, 0));
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0 || j == 0 || i == heigth - 1 || j == width - 1)
					map[i][j] = -1;
			}
		}
		snake.createSnake(map);
		food.createFood(map);
		updateMap();;
	}

	void updateMap() {
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				if (showMap[i][j] != map[i][j]) {
					showMap[i][j] = map[i][j];
					if (showMap[i][j] == 0)
						showChar(j, i, ' ');
					else if (showMap[i][j] == -1)
						showChar(j, i, '*');
					else if (showMap[i][j] == snake.getId())
						showChar(j, i, '*');
					else if (showMap[i][j] == food.getId())
						showChar(j, i, '$');
				}
			}
		}
	}

	void play() {
		do {
			if (_kbhit()) {
				snake.updateDir(_getch(), map);
				if (!start) start = true;
			}
			snake.moves(map);
			snake.updateSnake(map);

			updateMap();

			food.checkFood(map);
			if (!food.getIsFood()) {
				snake.addLength();
				food.createFood(map);
			}

			if (start) showScore();

			Sleep(200);

		} while (!snake.getCollision());
	}

	void showScore() {
		COORD cord;
		cord.X = 6;
		cord.Y = heigth;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
		cout << "                             \n";
		cout << "Score: " << snake.getLength();
	}
};