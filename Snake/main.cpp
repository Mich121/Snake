#include "Snake.h"
#include "Food.h"

void table(COORD coord, COORD food, bool eaten, std::vector<COORD> body)
{
    for (int i = 0; i < 20; i++)
    {
        std::cout << "\t\t#";
        for (int j = 0; j < 40 - 2; j++)
        {
            if (i == 0 || i == 20 - 1)
                std::cout << '#';
            else if (i == coord.Y && j + 1 == coord.X)
                std::cout << 'O';
            else if (i == food.Y && j + 1 == food.X)
                std::cout << 'X';
            else if (eaten == true)
                std::cout << ' ';
            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < body.size() - 1; k++)
                {
                    if (i == body[k].Y && j + 1 == body[k].X)
                    {
                        std::cout << 'O';
                        isBodyPart = true;
                        break;
                    }
                }

                if (!isBodyPart) 
                    std::cout << ' ';
            }
        }
        std::cout << "#\n";
    }
}

int main()
{
    Snake s1;
    Food f1;
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    bool GameIsOver = false;
    bool eaten = false;
    while(GameIsOver == false)
    {
        table(s1.GetCoord(), f1.GetFoodCoord(), eaten, s1.GetBody());
        s1.Movement();
        GameIsOver = s1.Collision();
        eaten = s1.Eaten(f1.GetFoodCoord());
        if (eaten == true)
        {
            f1.GenerateFoodCoord();
            s1.Grow();
        }
        SetConsoleCursorPosition(H, { 0,0 });
    }
}
