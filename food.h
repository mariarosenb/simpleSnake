
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class food {
	int x, y;
	const int id = 2;

	bool isFood = true;

public:
	food() {}

	food(vector < vector < int >> & map) {
		createFood(map);
	}

	void createFood(vector < vector < int >> & map) {
		do {
			x = rand() % 20 + 1;
			y = rand() % 20 + 1;
			if (map[y][x] == 0)
				break;
		} while (true);

		map[y][x] = id;
		isFood = true;
	}

	void checkFood(vector < vector < int >> & map) {
		if (map[y][x] != id) isFood = false;
	}

	bool getIsFood() {
		return isFood;
	}

	int getId() {
		return id;
	}
};