#include <math.h>
#include <iostream>
#include "graphics.h"
using namespace std;

void drawLine(int x1, int y1, int x2, int y2)
{
	int dy = y2 - y1;
	int dx = x2 - x1;
	int px = 2 * dy - dx;
	int py = 2 * dx - dy;
	double m = dy / (double)dx;

	cout << m << endl;

	if (abs(m) < 1)
		for (int x = x1, y = y1; x < x2; x++)
			if (px < 0) {
				putpixel(x + 1, y, WHITE);
				px += 2 * dy;
			} else {
				putpixel(x + 1, ++y, WHITE);
				px += 2 * dy - 2 * dx;
			}
	else
	{
		for (int x = x1, y = y1; y < y2; y++)
			if (py < 0) {
				putpixel(x, y+1, WHITE);
				py += 2 * dx;
			}
			else {
				putpixel(++x, y+1, WHITE);
				py += 2 * dx - 2 * dy;
			}
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	drawLine(100, 100, 400, 300);
	drawLine(100, 50, 400, 400);
	getch();
	return 0;
}