#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    // Initialize the graphics mode and driver
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Get the center of the screen
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    // Draw a circle
    int radius = 100;
    setcolor(WHITE);
    circle(centerX, centerY, radius);

    // Pause to view the result
    cout << "Press any key to exit...";
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}
