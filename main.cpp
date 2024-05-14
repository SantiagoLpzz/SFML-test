#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int numCells = 80;
int width = 800;
int height = 800;

int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(40);
    Grid grid(numCells,width,height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

        }

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;
            grid.toggle(x,y);
        }

        window.clear();
        grid.update();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}