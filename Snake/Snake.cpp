#include "Snake.h"
#include <chrono>	// -> dzieki tym biblioteka mozemy uzyc funkcji sleep_for
#include <thread> // -> lepiej uzywac tej funkcji niz Sleep()

Snake::Snake() : coord({ 10,10 }), d(Direction::Start), lengthofsnake(1) 
{
	body.push_back(coord);
}
Snake::~Snake() {}

COORD Snake::GetCoord()
{
	return coord;
}

void Snake::Movement()
{
		ChangeDirection();
		switch (d)
		{
		case Direction::Left:
			coord.X -= 1;
			break;
		case Direction::Right:
			coord.X += 1;
			break;
		case Direction::Up:
			coord.Y -= 1;
			break;
		case Direction::Down:
			coord.Y += 1;
			break;
		default:
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
		body.push_back(coord);
		if (body.size() > lengthofsnake) 
			body.erase(body.begin());
}

void Snake::ChangeDirection()
{
	if (_kbhit())
	{
		char ch = _getch();
		switch (ch)
		{
		case 'w':
			d = Direction::Up;
			break;
		case 'd':
			d = Direction::Right;
			break;
		case 's':
			d = Direction::Down;
			break;
		case 'a':
			d = Direction::Left;
			break;
		}
		std::cin.sync();
	}
}

bool Snake::Collision()
{
	bool GameIsOver = false;

	if (coord.X > 37 || coord.X < 0 || coord.Y > 19 || coord.Y < 0)
	{
		GameIsOver = true;
		std::cout << "GAME OVER!";
	}
	for (int i = 0; i < lengthofsnake - 1; i++)
	{
		if (coord.X == body[i].X && coord.Y == body[i].Y)
		{
			GameIsOver = true;
			std::cout << "GAME OVER!";
			break;
		}
	}

	return GameIsOver;
}

bool Snake::Eaten(COORD food)
{
	bool eaten = false;
	if (coord.X == food.X && coord.Y == food.Y)
		eaten = true;

	return eaten;
}

std::vector<COORD> Snake::GetBody()
{
	return body;
}

int Snake::Grow()
{
	lengthofsnake += 1;
	return lengthofsnake;
}
