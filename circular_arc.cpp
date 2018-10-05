#include <math.h>
#include "graphics.h"
using namespace std;

#define PI 3.14

void drawCircularArc(int center_x, int center_y, int radius, float start_theta, float end_theta) {
    float theta_inc = PI / 180; // one degree
    for (float theta = start_theta; theta <= end_theta; theta += theta_inc) {
        int x = radius * cos(theta);
        int y = radius * sin(theta);

        putpixel(center_x + x, center_y + y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawCircularArc(200, 200, 50, PI / 6, 6 * PI / 4);
    getch();
    return 0;
}