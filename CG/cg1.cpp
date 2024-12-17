#include <iostream>
#include <graphics.h>
#include <algorithm>
#include <math.h>

// Write C++ program to draw a concave polygon and fill it with desired color using scan fill
// algorithm. Apply the concept of inheritance.

using namespace std;

// Base Class for Shape

class Shape {
    protected:
    int x[20], y[20], n = 0;

    public:
    void acceptVertices (int num) {
        n = num;
        
        for (int i = 0; i < n; i++) {
            cout << "Enter the coordinate for vertex "<< i + 1 << ":" << endl;
            cout << "\tEnter the value of X" << i + 1 << ": ";
            cin >> x[i];
            cout << "\tEnter the value of Y" << i + 1 << ": ";
            cin >> y[i];
            cout << "\n" << endl;
        }

        // Close the polygon by connecting the last vertex to the first
        x[n] = x[0];
        y[n] = y[0];
    }
    
    void drawEdges () {
        for (int i = 0; i < n; i++) {
            line (x[i], y[i], x[i + 1], y[i + 1]);
        }
    }
};
// Derived Class for Scan-Line Filling Algorithm
class scanLinePolygon : public Shape{
    float slope[20], x_int[20];  // Slopes and intersection points

    public:
    void calulateSlopes() {
        for (int i = 0; i < n; i++) {
            float dx = x[i + 1] - x[i];
            float dy = y[i + 1] - y[i];
            slope[i] = (dy == 0) ? 1 : ((dx == 0) ? 0 : (float)dx / (float)dy);
        }
    }

    void scanFill () {
        int ymin = getmaxy(), ymax = 0;
        // Find ymin and ymax
        for (int i = 0; i < n; i++) {
            ymin = min(ymin, y[i]);
            ymax = max(ymax, y[i]); 
        }
        // Scan line from ymax to ymin
        for (int p = ymax; p >= ymin; p--) {
            int k = 0;
            for (int i = 0; i < n; i++) {
                if ((y[i] <= p && y[i + 1] > p) || (y[i] > p && y[i + 1] <= p)) {
                    x_int[k++] = x[i] + slope[i] * (p - y[i]);
                }
            }
            // Sort the intersection points
            sort(x_int, x_int + k);
            // Fill between pairs of intersection points
            for (int i = 0; i < k; i += 2) {
                setcolor(MAGENTA);
                line(x_int[i], p, x_int[i + 1], p);
            }

        }
    }
};

int main () {
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, nullptr);

    scanLinePolygon polygon;
    int n;

    cout << "Enter the no. of vertices: ";
    cin >> n;

    polygon.acceptVertices(n);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    polygon.drawEdges();

    // Calculate slopes and fill the polygon using scan-line algorithm

    polygon.calulateSlopes();
    polygon.scanFill();

    getch();
    closegraph();
    return 0;
}

// Sample input
// 3
// 100 200 
// 300 200
// 100 300
