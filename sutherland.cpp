#include <math.h>
#include <vector>
#include <utility>
#include "graphics.h"
using namespace std;

#define TOP_LEFT 0b1001
#define TOP_MID 0b1000
#define TOP_RIGHT 0b1010
    
#define LEFT 0b0001
#define MIDDLE 0
#define RIGHT 0b0010

#define BOTTOM_LEFT 0b0101
#define BOTTOM_MID 0b0100
#define BOTTOM_RIGHT 0b0110

short getRegion(int wx1, int wy1, int wx2, int wy2, int x, int y) {
    if (x < wx1) {
        if (y < wy1)
            return TOP_LEFT;
        else if (y > wy2)
            return BOTTOM_LEFT;
        else return LEFT;
    }
    else if (x > wx2) {
        if (y < wy1)
            return TOP_RIGHT;
        else if (y > wy2)
            return BOTTOM_RIGHT;
        else return RIGHT;
    }
    else {
        if (y < wy1)
            return TOP_MID;
        else if (y > wy2)
            return BOTTOM_MID;
        else return MIDDLE;
    }
}

void clipLineCS(int wx1, int wy1, int wx2, int wy2, int x1, int y1, int x2, int y2)
{
    float m = (float)(y2 - y1) / (x2 - x1);
    short region1 = getRegion(wx1, wy1, wx2, wy2, x1, y1);
    short region2 = getRegion(wx1, wy1, wx2, wy2, x2, y2);

    if ((region1 | region2) == 0) {
        line(x1, y1, x2, y2);
    }
    else if ((region1 & region2) == 0) {
        // needs clipping
        vector<pair<int, int>> points;
        if (region1 == 0)
            points.push_back(make_pair(x1, y1));
        else if (region2 == 0)
            points.push_back(make_pair(x2, y2));

        // Check left border
        if ((wx1 > x1 && wx1 < x2) || (wx1 > x2 && wx1 < x1)) {
            int yi = y1 + m * (wx1 - x1);
            if (yi < wy2 && yi > wy1)
                points.push_back(make_pair(wx1, yi));
        }

        // Ceck right border
        if ((wx2 > x1 && wx2 < x2) || (wx2 > x2 && wx2 < x1)) {
            int yi = y1 + m * (wx2 - x1);
            if (yi < wy2 && yi > wy1)
                points.push_back(make_pair(wx2, yi));
        }

        // Check top border
        if ((wy1 > y1 && wy1 < y2) || (wy1 > y2 && wy1 < y1)) {
            int xi = x1 + (wy1 - y1) / m;
            if (xi < wx2 && xi > wx1)
                points.push_back(make_pair(xi, wy1));
        }

        // Check bottom border
        if ((wy2 > y1 && wy2 < y2) || (wy2 > y2 && wy2 < y1)) {
            int xi = x1 + (wy2 - y1) / m;
            if (xi < wx2 && xi > wx1)
                points.push_back(make_pair(xi, wy2));
        }

        line(points[0].first, points[0].second, points[1].first, points[1].second);
    }
    else {
        // entirely out of window
    }
    
    
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(50, 50, 150, 150);
    clipLineCS(50, 50, 150, 150, 75, 100, 125, 100);
    clipLineCS(50, 50, 150, 150, 25, 100, 200, 65);
    clipLineCS(50, 50, 150, 150, 75, 75, 75, 10);
    clipLineCS(50, 50, 150, 150, 10, 10, 10, 100);
    getch();
    return 0;
}