#include <math.h>
#include "graphics.h"
using namespace std;

void rotate(int& x, int& y, int ref_x, int ref_y, float theta) {
    x -= ref_x;
    y -= ref_y;

    int new_x = x * cos(theta) - y * sin(theta);
    int new_y = x * sin(theta) + y * cos(theta);

    x = new_x + ref_x;
    y = new_y + ref_y;
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int triangle_points[] = { 100, 100,
                              50, 200,
                              150, 200,
                              100, 100};

    drawpoly(4, triangle_points);
    for (int i = 0; i < 7; i += 2) {
        rotate(triangle_points[i], triangle_points[i + 1], 100, 100, -3.14 / 2);
    }

    setcolor(RED);
    drawpoly(4, triangle_points);

    getch();
    return 0;
}