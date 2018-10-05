#include <math.h>
#include <iostream>
#include "graphics.h"
using namespace std;

void drawEllipse(int center_x, int center_y, int x_axis, int y_axis) {
    int ry2 = y_axis * y_axis;
    int rx2 = x_axis * x_axis;
    
    // Region 1
    int p = ry2 - rx2 * y_axis + float(rx2 / 4);
    int x = 0, y = y_axis;
    
    for (x = 0; ry2*x < rx2 * y; x++) {
        putpixel(x + center_x, y + center_y, WHITE);
        putpixel(-x + center_x, y + center_y, WHITE);
        putpixel(x + center_x, -y + center_y, WHITE);
        putpixel(-x + center_x, -y + center_y, WHITE);
        if (p >= 0) {
            y--;
            p += 2 * ry2*x - 2 * rx2*y + ry2;
        }
        else p += 2 * ry2*x + ry2;
    }

    //Region 2
    p = ry2 * (float(x) + 0.5)*(float(x) + 0.5) + rx2*(y-1)*(y-1) - rx2*ry2;

    for(;y >= 0; y--) {
        putpixel(x + center_x, y + center_y, WHITE);
        putpixel(-x + center_x, y + center_y, WHITE);
        putpixel(x + center_x, -y + center_y, WHITE);
        putpixel(-x + center_x, -y + center_y, WHITE);
        if (p <= 0) {
            x++;
            p += 2 * ry2*x - 2 * rx2*y + rx2;
        }
        else p += rx2-2*rx2*y;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipse(50, 50, 25, 50);
    getch();
    return 0;
}