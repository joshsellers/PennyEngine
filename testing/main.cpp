//#define NO_CONSOLE_ON_STARTUP

#include "../PennyEngine/PennyEngine.h"
#include "TestGameManager.h"
#include <iostream>

// for testing

int main() {
    TestGameManager testManager;

    TestClass testObject("MAINTEST"); 

    PennyEngine::setAppName("TestApp");
    PennyEngine::setWindowTitle(PennyEngine::getAppName());

    PennyEngine::setFullscreen(false);
    PennyEngine::useDisplayResForUI(true);
    PennyEngine::setRenderResolution({900, 900});
    //PennyEngine::setDisplayResolution({ (int)sf::VideoMode::getDesktopMode().width, (int)sf::VideoMode::getDesktopMode().height });
    PennyEngine::setDisplayResolution({ 1080, 1080 });

    PennyEngine::setFramerateLimit(60);

    PennyEngine::start(&testManager);
}