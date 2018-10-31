#include "graphics.h"

void translate(int& x, int& y, int tx, int ty) {
    x += tx;
    y += ty;
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    rectangle(x1, y1, x2, y2);
    
    translate(x1, y1, 100, 50);
    translate(x2, y2, 100, 50);

    setcolor(RED);
    rectangle(x1, y1, x2, y2);

    getch();
    return 0;
}