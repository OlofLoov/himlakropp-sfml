#include "Game.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"

class MyClass
{
    public:
    int i = 0;
    MyClass()
    {
        std::cout << "Created my class" << std::endl;
    }

    MyClass(const MyClass &myClass)
    {
        i = myClass.i;
        std::cout << "Copy constructor called" << std::endl;
    }
};

int main()
{
    Game game;
    game.run();
    return 0;
}