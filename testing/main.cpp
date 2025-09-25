//#define NO_CONSOLE_ON_STARTUP

#include "../PennyEngine/PennyEngine.h"
#include "TestGameManager.h"

// for testing

int main() {
    TestGameManager testManager;

    PennyEngine::setFullscreen(true);
    PennyEngine::useDisplayResForUI(true);
    PennyEngine::setRenderResolution({900, 900});
    PennyEngine::setDisplayResolution({ (int)sf::VideoMode::getDesktopMode().width, (int)sf::VideoMode::getDesktopMode().height });
    PennyEngine::setDisplayResolution({ 1920, 1080 });

    PennyEngine::setFramerateLimit(60);

    PennyEngine::start(&testManager);
}