#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

const int gameWidth = 20;
const int gameHeight = 10;

int birdY = gameHeight / 2;
int birdVelocity = 0;
int birdGravity = 1;
bool gameover = false;

int pipeX = gameWidth - 1;
int gapY = gameHeight / 2;
const int gapHeight = 3;
const int pipeWidth = 2;

// Function to draw the game screen
void draw() {
    system("cls");
    
    for (int i = 0; i < gameHeight; ++i) {
        for (int j = 0; j < gameWidth; ++j) {
            if (i == birdY && j == gameWidth / 4) {
                cout << "B"; // Bird
            } else if ((j == pipeX || j == pipeX + 1) && (i < gapY || i >= gapY + gapHeight)) {
                cout << "#"; // Pipe
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Function to update the game state
void update() {
    if (!gameover) {
        birdVelocity += birdGravity;
        birdY += birdVelocity;
        
        pipeX--;
        if (pipeX < 0) {
            pipeX = gameWidth - 1;
            gapY = rand() % (gameHeight - gapHeight);
        }
        
        // Collision detection
        if (birdY < 0 || birdY >= gameHeight || ((gameWidth / 4) == pipeX && (birdY < gapY || birdY >= gapY + gapHeight))) {
            gameover = true;
        }
    }
}

int main() {
    srand(time(0));

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ' && !gameover) {
                birdVelocity = -2;
            }
            if (gameover && key == 'r') {
                birdY = gameHeight / 2;
                birdVelocity = 0;
                gameover = false;
            }
        }
        
        draw();
        update();
        
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
