/*
Name: Muhammad Abbas
id:23k-0068
purpose: simulating a game engine showing associaton
*/

#include <iostream>
#include <string>

using namespace std;

// Graphics Rendering Engine
class GraphicRenderEngine {
public:
    void render() {
        cout<<"Graphics engine is rendering graphics." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Input handler is processing user input." << endl;
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() {
        cout << "Physics engine is simulating physics." << endl;
    }
};

class GameEngine {
//association being used
private:
    GraphicRenderEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void start() {
        cout << "the Graphics engine is starting." << endl;
        graphicsEngine.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        cout << "Game engine has started" << endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.start();
    return 0;
}
