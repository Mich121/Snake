#pragma once
#include <windows.h>

class Food
{
	COORD food;	//coordinates of food
public:
	Food();
	~Food();
	void GenerateFoodCoord();
	COORD GetFoodCoord();
};

