#include "Grid.hpp"

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }
}

void Grid::drawTo(RenderWindow  &window){
    int sizeX = this->w/this->rows;
    int sizeY = this->h/this->cols;

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(sizeX, sizeY));
            rect.setPosition(Vector2f(j*sizeX,i*sizeY));
            rect.setOutlineThickness(1);
            rect.setOutlineColor(Color::Black);
            if(tablero[j][i] == 1)
            {
                rect.setFillColor(Color::Green);
            }
            window.draw(rect);
        }
    }
}

Grid::Grid(int n, int w, int h)
{
    this->rows = n;
    this->cols = n;
    this->w = w;
    this->h = h;
    for (int i = 0; i < this->rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < this->cols; j++)
        {
            tablero[i].push_back(rand()%2);
        }
    }
}

void Grid::toggle(int x, int y)
{
    int sizeX = this->w/this->rows;
    int sizeY = this->h/this->cols;

    int indexX = x/sizeX;
    int indexY = y/sizeY;

    //tablero[indexY][indexX] = tablero[indexX][indexY] == 0? 1 : 0;

    tablero[indexY][indexX] = (tablero[indexY][indexX] + 1) % 2;
}