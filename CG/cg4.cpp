#include <iostream>
#include <graphics.h>
#include <cmath>
#include <string>
using namespace std;

//a) Write C++ program to draw 2-D object and perform following basic transformations, Scaling
//b) Translation c) Rotation. Apply the concept of operator overloading.

class Transform {
public:
	int m, a[20][20], c[20][20];
	int i, j, k;
public:
	void object();
	void accept();
	
	void operator * (float b[20][20]){
		for (i = 0; i < m; i++){
			for (j = 0; j < m; j++) {
				c[i][j] = 0;
				for (k = 0; k < m; k++) {
					c[i][j] += (a[i][k] * b[k][j]);
				}
			} 
		} 
	} 
};

void Transform::object(){
	int gd, gm;
	gd = DETECT;
	initgraph(&gd, &gm, nullptr);
	line(300, 0, 300, 600);
	line(0, 300, 600, 300);

	for (i = 0; i < m - 1; i++){
		line(300 + a[i][0], 300 - a[i][1], 300 + a[i + 1][0], 300 - a[i + 1][1]);
	}
	line(300 + a[0][0], 300 - a[0][1], 300 + a[i][0], 300 - a[i][1]);

	for (i = 0; i < m - 1; i++){
		line(300 + c[i][0], 300 - c[i][1], 300 + c[i + 1][0], 300 - c[i + 1][1]);
	}
	line(300 + c[0][0], 300 - c[0][1], 300 + c[i][0], 300 - c[i][1]);

	int temp;
	cout << "Press 1 to continue: " << endl;
	cin >> temp;
	closegraph();
}

void Transform::accept() {
	cout << "\n";
	cout << "Enter the number of edges: ";
	cin >> m;
	cout << "\nEnter the Coordinates: ";
	for (i = 0; i < m; i++){
		for (j = 0; j < 3; j++){
			if (j >= 2) a[i][j] = 1;
			else cin >> a[i][j];
		}
	}
}

int main() {
	int ch, tx, ty, sx, sy;
	float deg, theta, b[20][20];
	Transform t;
	t.accept();

	cout << "----- MENU -----" << endl;
	cout << "1. Translation\n2. Scaling\n3. Rotation" << endl;
	cout << "Enter your Choice: "; cin >> ch;
	switch (ch) {
		case 1:
			cout << "Translation Operation" << endl;
			cout << "Enter values for tx and ty: "; cin >> tx >> ty;
			b[0][0] = b[2][2] = b[1][1] = 1;
			b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
			b[2][0] = tx;
			b[2][1] = ty;
			t * b;
			t.object();
			break;

		case 2:
			cout << "Scaling Operation" << endl;
			cout << "Enter value for sx and sy: "; cin >> sx >> sy;
			b[0][0] = sx;
			b[1][1] = sy;
			b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
			b[2][0]= b[2][1] = 0;
			b[2][2] = 1;
			t * b;
			t.object();
			break;

		case 3:
			cout << "Rotation Operation" << endl;
			cout << "Enter value for the angle: "; cin >> deg;
			theta = deg * (3.14/100);
			b[0][0] = b[1][1] = cos(theta);
			b[0][1] = sin(theta);
			b[1][0] = sin(-theta);
			b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;
			b[2][2] = 1;
			t * b;
			t.object();
			break;

		default:
			cout << "ERROR! Please Enter a valid choice " << endl;
	}

	getch();

	return 0;
}
