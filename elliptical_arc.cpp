#include <math.h>
#include "graphics.h"
using namespace std;

#define PI 3.14

void drawEllipticalArc(int center_x, int center_y, int x_axis, int y_axis, float start_theta, float end_theta) {
    float theta_inc = PI/180; // one degree
    for (float theta = start_theta; theta <= end_theta; theta += theta_inc) {
        float r = x_axis * y_axis / sqrt(pow(y_axis*cos(theta), 2) + pow(x_axis*sin(theta), 2));
        int x = r * cos(theta);
        int y = r * sin(theta);

        putpixel(center_x + x, center_y + y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipticalArc(100, 100, 25, 50, 0, 3*PI/4);
    getch();
    return 0;
}