#include <math.h>
#include <iostream>
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

    /*int triangle_points[] = { 100, 100,
                              50, 200,
                              150, 200,
                              100, 100};*/

    int N;
    int polygon_points[500] = { 0 };


    cout << "Number of points: ";
    cin >> N;

    for (int i = 0; i < 2*N; i += 2) {
        cout << "Point " << i/2 << endl;
        cout << "x: ";
        cin >> polygon_points[i];

        cout << "y: ";
        cin >> polygon_points[i + 1];
    }
    polygon_points[2 * N] = polygon_points[0];
    polygon_points[2 * N + 1] = polygon_points[1];
    drawpoly(N+1, polygon_points);

    int angle;
    cout << "Enter the angle to rotate (degrees): ";
    cin >> angle;

    for(int i = 0; i < 2*N; i += 2)
        rotate(polygon_points[i], polygon_points[i + 1], 100, 100, (3.14*angle/180.0));

    setcolor(RED);
    drawpoly(N+1, polygon_points);

    getch();
    return 0;
}