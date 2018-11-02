#include "graphics.h"
#include <iostream>
using namespace std;

void translate(int& x, int& y, int tx, int ty) {
    x += tx;
    y += ty;
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    
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

    int tx, ty;
    cout << "Translation factors (Tx, Ty): ";
    cin >> tx >> ty;

    for (int i = 0; i < 2 * (N+1); i += 2)
        translate(polygon_points[i], polygon_points[i + 1], tx, ty);

    setcolor(RED);
    drawpoly(N + 1, polygon_points);

    getch();
    return 0;
}