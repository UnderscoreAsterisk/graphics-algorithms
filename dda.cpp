#include "graphics.h"
#include <iostream>
#include <math.h>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2)
{
	double m = (y2 - y1) / (double)(x2 - x1);
	cout << m << endl;

	if (abs(m) < 1)
		for (int x = x1, y = y1; x <= x2; x++, y = floor(y + m + 0.5))
		{
			cout << x << ", " << y << endl;
			putpixel(x, y, RED);
		}
	else 
		for (int x = x1, y = y1; y <= y2; y++, x = floor(x + 1.0/m + 0.5))
		{
			cout << 1.0 / m + 0.5 << endl;
			//cout << x << ", " << y << endl;
			putpixel(x, y, GREEN);
		}

}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "..//BGI");
	drawLine(0,0, 100, 300);
	getch();
	return 0;
}