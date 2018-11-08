#include <math.h>
#include <stack>
#include <utility>
#include "graphics.h"
using namespace std;

void boundary_fill(int seed_x, int seed_y, unsigned int BOUNDARY_COLOR, unsigned int FILL_COLOR) {
    stack<pair<int, int>> s;
    s.push(make_pair(seed_x, seed_y));

    while (!s.empty()) {
        pair<int, int> point = s.top();
        s.pop();

        int x = point.first;
        int y = point.second;
        putpixel(x, y, FILL_COLOR);

        // Check 4-Neighbourhood
        if (getpixel(x - 1, y) != BOUNDARY_COLOR && getpixel(x - 1, y) != FILL_COLOR)
            s.push(make_pair(x - 1, y));

        if (getpixel(x, y - 1) != BOUNDARY_COLOR && getpixel(x, y - 1) != FILL_COLOR)
            s.push(make_pair(x, y - 1));

        if (getpixel(x + 1, y) != BOUNDARY_COLOR && getpixel(x + 1, y) != FILL_COLOR)
            s.push(make_pair(x + 1, y));

        if (getpixel(x, y + 1) != BOUNDARY_COLOR && getpixel(x, y + 1) != FILL_COLOR)
            s.push(make_pair(x, y + 1));
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(WHITE);
    rectangle(50, 50, 150, 150);

    boundary_fill(75, 75, WHITE, RED);
    
    getch();
    return 0;
}