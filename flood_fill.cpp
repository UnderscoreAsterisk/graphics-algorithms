#include <math.h>
#include <stack>
#include <utility>
#include "graphics.h"
using namespace std;

void boundary_fill(int seed_x, int seed_y, unsigned int BG_COLOR, unsigned int FILL_COLOR) {
    stack<pair<int, int>> s;
    s.push(make_pair(seed_x, seed_y));

    while (!s.empty()) {
        pair<int, int> point = s.top();
        s.pop();

        int x = point.first;
        int y = point.second;
        putpixel(x, y, FILL_COLOR);

        // Check 4-Neighbourhood
        if (getpixel(x - 1, y) == BG_COLOR)
            s.push(make_pair(x - 1, y));

        if (getpixel(x, y - 1) == BG_COLOR)
            s.push(make_pair(x, y - 1));

        if (getpixel(x + 1, y) == BG_COLOR)
            s.push(make_pair(x + 1, y));

        if (getpixel(x, y + 1) == BG_COLOR)
            s.push(make_pair(x, y + 1));
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(RED);
    line(200, 50, 100, 200);
    setcolor(BLUE);
    line(200, 50, 300, 200);
    setcolor(GREEN);
    line(100, 200, 300, 200);

    boundary_fill(200, 100, BLACK, CYAN);

    getch();
    return 0;
}