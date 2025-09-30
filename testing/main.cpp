//#define NO_CONSOLE_ON_STARTUP

#include "../PennyEngine/PennyEngine.h"
#include "TestGameManager.h"
#include <iostream>

// for testing

int main() {
    TestClass testObject("MAINTEST", 2); 

    PennyEngine::setAppName("TestApp");
    PennyEngine::setWindowTitle(PennyEngine::getAppName());

    PennyEngine::setFullscreen(true);
    PennyEngine::useDisplayResForUI(true);
    PennyEngine::setRenderResolution({400, 400});
    //PennyEngine::setDisplayResolution({ (int)sf::VideoMode::getDesktopMode().width, (int)sf::VideoMode::getDesktopMode().height });
    PennyEngine::setDisplayResolution({ 900, 900 });

    PennyEngine::setFramerateLimit(60);


    TestGameManager testManager;

    PennyEngine::start(&testManager);
}