#include "graphics.h"
#include <iostream>
using namespace std;

void scale(int& x, int& y, int ref_x, int ref_y, float sx, float sy) {
    x -= ref_x;
    y -= ref_y;

    int new_x = x * sx;
    int new_y = y * sy;

    x = new_x + ref_x;
    y = new_y + ref_y;
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int N;
    int polygon_points[500] = { 0 };

    cout << "Number of points: ";
    cin >> N;

    for (int i = 0; i < 2 * N; i += 2) {
        cout << "Point " << i / 2 << endl;
        cout << "x: ";
        cin >> polygon_points[i];

        cout << "y: ";
        cin >> polygon_points[i + 1];
    }
    polygon_points[2 * N] = polygon_points[0];
    polygon_points[2 * N + 1] = polygon_points[1];
    drawpoly(N + 1, polygon_points);

    float sx, sy;
    cout << "Enter scaling factors Sx and Sy: ";
    cin >> sx >> sy;

    int ref_x, ref_y;
    cout << "Enter reference point coordinates: ";
    cin >> ref_x >> ref_y;

    for (int i = 0; i < 2 * (N+1); i += 2)
        scale(polygon_points[i], polygon_points[i + 1], ref_x, ref_y, sx, sy);

    setcolor(RED);
    drawpoly(N + 1, polygon_points);

    getch();
    return 0;
}