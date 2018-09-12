#include <math.h>
#include "graphics.h"
using namespace std;

void drawCircle(int center_x, int center_y, double radius)
{
	int p = floor(1.75 - radius);
	for (int x = 0, y = radius; x <= y; x++) {
		if (p < 0)
			p += 2*x + 3;
		else {
			p += 2*x - 2*y + 1;
			y -= 1;
		}

		//Draw in all octants
		for (int i = 0; i < 8; i++) {
			float theta = i * 3.14 / 4;
			int plot_x = cos(theta) * x - sin(theta) * y + center_x;
			int plot_y = sin(theta) * x + cos(theta) * y + center_y;
			putpixel(plot_x, plot_y, WHITE);
		}
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	drawCircle(320, 240, 200.53);
	drawCircle(220, 140, 50);
	drawCircle(420, 140, 50);
	getch();
	return 0;
}