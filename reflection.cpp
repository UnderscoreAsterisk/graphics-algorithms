#include "graphics.h"
#include <iostream>
using namespace std;

void reflect(int& x, int& y, int ref_x, int ref_y) {
    x = 2 * ref_x - x;
    y =  2 * ref_y - y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    /*int triangle_points[] = { 300, 100,
        250, 200,
        350, 200,
        300, 100 };*/

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

    int ref_x, ref_y;
    cout << "Enter reference point coordinates: ";
    cin >> ref_x >> ref_y;

    for (int i = 0; i < 2 * (N+1); i += 2)
        reflect(polygon_points[i], polygon_points[i + 1], ref_x, ref_y);

    setcolor(RED);
    drawpoly(N + 1, polygon_points);

    getch();
    return 0;
}