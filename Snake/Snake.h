#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

class Snake
{
	COORD coord;	//coordinates of snake
	enum class Direction { Start, Left, Right, Up, Down };	//choose direction to move constantly
	Direction d;
	int lengthofsnake;
	std::vector<COORD> body;

public:
	Snake();
	~Snake();
	COORD GetCoord();
	void Movement();
	void ChangeDirection();
	bool Collision();
	bool Eaten(COORD food);
	std::vector<COORD> GetBody();
	int Grow();
};

