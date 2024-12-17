#include <iostream>
#include <cmath>
#include <graphics.h>

//a) Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circledrawing algorithm. Apply the concept of encapsulation.

using namespace std;

class DDA{
private:
	float xi, yi, xf, yf, dx, dy, steps;
	float incX, incY;
	float X, Y;

public:
	void calc(float xs, float ys, float xe, float ye){
		xi = xs; yi = ys; xf = xe, yf = ye;
		dx = (xf - xi); dy = (yf - yi);
		steps = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
		incX = dx/steps; incY = dy/steps;
		X = xi; Y = yi;
	}
	void drawLine(){
		for (int i = 1; i <= steps; i++){
			putpixel(floor(X), floor(Y), MAGENTA);
			X += incX; Y += incY;
			delay(5);
		}
	}
};

class Bresenham {
	int xc, yc, r, xi, yi, p;
public:
	void calc(int XC, int YC, int Radius){
		xc = XC; yc = YC; r = Radius;
		xi = 0; yi = r;
		p = 3-(2*r);
	}
	void drawCircle(){
		while (xi < yi){
			putpixel(xc + xi, yc + yi, YELLOW);
			putpixel(xc - xi, yc + yi, YELLOW);
			putpixel(xc + xi, yc - yi, YELLOW);
			putpixel(xc - xi, yc - yi, YELLOW);
			putpixel(xc + yi, yc + xi, YELLOW);
			putpixel(xc - yi, yc + xi, YELLOW);
			putpixel(xc + yi, yc - xi, YELLOW);
			putpixel(xc - yi, yc - xi, YELLOW);
			xi++;
			if (p < 0){
				p += ((4 * xi) + 6);
			} else {
				yi--;
				p += ((4 * (xi - yi)) + 10);
			}
			delay(1);
		}
	}
};

int main() {
	int gd = DETECT, gm;
	int xc = 300, yc = 250, r = 100;	
	Bresenham B1, B2;
	DDA L1, L2, L3;
	initgraph(&gd, &gm, NULL);

	B1.calc(xc, yc, r); 
	B2.calc(xc, yc, r/2); 
	B1.drawCircle();
	B2.drawCircle();

	L1.calc(xc, (yc - r), (xc + (r / 1.154)), (yc + (r / 2)));
	L2.calc(xc, (yc - r), (xc - (r / 1.154)), (yc + (r / 2)));
	L3.calc((xc + (r / 1.154)), (yc + (r / 2)), (xc - (r / 1.154)), (yc + (r / 2)));
	
	L1.drawLine(); 
	L2.drawLine(); 
	L3.drawLine();

	cin.get();
	closegraph();
	return 0;
}

