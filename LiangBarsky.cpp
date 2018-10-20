#include <math.h>
#include "graphics.h"
using namespace std;

int clipTest(int p, int q, float& u1, float& u2) {
    float r = (float)q / p;
    if (p < 0)
        if (max(u1, r) > u2)
            return false;
        else u1 = max(u1, r);
    else if (p > 0)
        if (u1 > min(u2, r))
            return false;
        else u2 = min(u2, r);
    else if (q < 0)
        return false;

    return true;
}

void clipLineLB(int wx1, int wy1, int wx2, int wy2, int x1, int y1, int x2, int y2)
{
    int deltaX = x2 - x1, deltaY = y2 - y1;
    float u1 = 0, u2 = 1;
    int p = -deltaX, q = x1 - wx1;
    
    int new_x1 = x1, new_y1 = y1, new_x2 = x2, new_y2 = y2;

    if (clipTest(-deltaX, x1 - wx1, u1, u2))
        if(clipTest(deltaX, wx2 - x1, u1, u2))
            if(clipTest(-deltaY, y1 - wy1, u1, u2))
                if (clipTest(deltaY, wy2 - y1, u1, u2)) {
                    if (u2 < 1) {
                        new_x2 = x1 + u2 * deltaX;
                        new_y2 = y1 + u2 * deltaY;
                    }

                    if (u1 > 0) {
                        new_x1 = x1 + u1 * deltaX;
                        new_y2 = y1 + u2 * deltaY;
                    }
                    line(new_x1, new_y1, new_x2, new_y2);
                }

        
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(50, 50, 150, 150);
    clipLineLB(50, 50, 150, 150, 75, 100, 125, 100);
    clipLineLB(50, 50, 150, 150, 25, 100, 100, 65);
    clipLineLB(50, 50, 150, 150, 75, 75, 75, 10);
    clipLineLB(50, 50, 150, 150, 10, 10, 10, 100);
    getch();
    return 0;
}