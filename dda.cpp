#include <math.h>
#include "graphics.h"
using namespace std;

void drawLine(int x1, int y1, int x2, int y2)
{
	double m = (y2 - y1) / (double)(x2 - x1);

	if (abs(m) > 1)
		for (int x = x1, y = y1; x < x2; x++, y = floor(y + m + 0.5))
			putpixel(x, y, WHITE);
	else 
		for (int x = x1, y = y1; y < y2; y++, x = floor(x + 1.0/m + 0.5))
			putpixel(x, y, WHITE);

}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	drawLine(100, 100, 400, 300);
	drawLine(100, 450, 400, 100);
	getch();
	return 0;
}