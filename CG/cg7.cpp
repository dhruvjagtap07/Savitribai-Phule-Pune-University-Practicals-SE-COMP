#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

//c) Write C++ program to draw man walking in the rain with an umbrella. Apply the concept of
//polymorphism.

using namespace std;

class Shape {
public:
    virtual void draw(int x, int y) = 0; // Pure virtual function
};

class Man : public Shape {
public:
    void draw(int x, int y) override {
        // Draw head
        circle(x, y - 50, 10);
        // Draw body
        line(x, y - 40, x, y);
        // Draw arms
        line(x, y - 30, x - 10, y - 20);
        line(x, y - 30, x + 10, y - 20);
        // Draw legs
        line(x, y, x - 10, y + 20);
        line(x, y, x + 10, y + 20);
    }
};

class Umbrella : public Shape {
public:
    void draw(int x, int y) override {
        // Draw umbrella
        arc(x, y - 70, 180, 0, 30);
        line(x - 30, y - 70, x + 30, y - 70);
        line(x+10, y - 70, x+10, y - 25);
    }
};

class Rain : public Shape {
public:
    void draw(int x, int y) override {
        // Draw rain
        for (int i = 0; i < 100; i++) {
            int rx = rand() % getmaxx();
            int ry = rand() % getmaxy();
            line(rx, ry, rx, ry + 5);
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Man man;
    Umbrella umbrella;
    Rain rain;

    for (int i = 0; i < getmaxx(); i += 5) {
        cleardevice();
        rain.draw(0, 0);
        man.draw(i, getmaxy() - 50);
        umbrella.draw(i, getmaxy() - 50);
        usleep(100000); // Sleep for 100 milliseconds
    }                                          

    closegraph();

    return 0;
}

