#ifndef Grid_h
#define Grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid
{
private:
    vector<vector<int>> tablero;
    int rows, cols, w, h;

public:
    Grid(int rows, int cols);
    Grid(int n, int w, int h);

    void drawTo(RenderWindow  &window);
    void toggle(int x, int y)
};

#endif