#include "Food.h"
#include <random>

Food::Food() : food({ 15,15 }) {}

Food::~Food() {}

void Food::GenerateFoodCoord()
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<> x(2, 35);
    food.X = x(eng);
    std::uniform_int_distribution<> y(2, 17);
    food.Y = y(eng);
}

COORD Food::GetFoodCoord()
{
    return food;
}
