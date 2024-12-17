#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Write C++ program to implement Cohen Southerland line clipping algorithm.

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;

int getCode(int x, int y){
	int code = 0;
	if (y > ymax) code |= TOP;
	if (y < ymin) code |= BOTTOM;
	if (x < xmin) code |= LEFT;
	if (x > xmax) code |= RIGHT;
	return code;
}

int main() {
	int gd = DETECT, gm;
	//cout << "Enter Window's max and min values: " << endl;
	//cin >> xmax >> ymax >> xmin >> ymin;
	xmax = 350;
	ymax = 350;
	xmin = 150;
	ymin = 150;

	int x1, y1, x2, y2;
	cout << "Enter Endpoints of the line: " << endl;
	cin >> x1 >> y1 >> x2 >> y2;


	initgraph(&gd, &gm, nullptr);

	rectangle(xmin, ymin, xmax, ymax);
	setcolor(BLUE);
	line(x1, y1, x2, y2);

	int outcode1 = getCode(x1, y1);
	int outcode2 = getCode(x2, y2);
	int accept = 0;

	while (1) {
		float m = (float)(y2 - y1)/(x2 - x1);
		if (outcode1 == 0 && outcode2 == 0) {
			accept = 1;
			break;
		} else if ((outcode1 & outcode2) != 0) {
			break;
		} else {
			int x, y, temp;
			if (outcode1 == 0) {
				temp = outcode2;
			} else {
				temp = outcode1;
			}
			
			if (temp & TOP) {
				x = x1 + (ymax - y1) / m;
				y = ymax;
			} else if (temp & BOTTOM) {
				x = x1 + (ymin - y1) / m;
				y = ymin;
			} else if (temp & LEFT) {
				x = xmin;
				y = y1 + m*(xmin - x1);
			} else if (temp & RIGHT) {
				x = xmax;
				y = y1 + m*(xmax - x1);
			}

			if (temp == outcode1) {
				x1 = x;
				y1 = y;
				outcode1 = getCode(x1, y1);
			} else {
				x2 = x;
				y2 = y;
				outcode2 = getCode(x2, y2);
			}
		}
	}

	cout << "After Clipping: ";
	if (accept){
		//cleardevice();
	
	}
	setcolor(WHITE);
	rectangle(xmin, ymin, xmax, ymax);
	setcolor(RED);
	line(x1, y1, x2, y2);
	getch();
	closegraph();

	return 0;
}


/*
Sample Input: 
100 400
400 200
*/