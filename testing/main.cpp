// Copyright (c) 2025 Josh Sellers
// Licensed under the MIT License. See LICENSE file.

//#define NO_CONSOLE_ON_STARTUP

#include "../PennyEngine/PennyEngine.h"
#include "TestGameManager.h"
#include <iostream>

// for testing

int main() {
    PennyEngine::setAppName("TestApp");
    PennyEngine::setWindowTitle(PennyEngine::getAppName());
    PennyEngine::setFont("res/font.ttf");

    PennyEngine::setFullscreen(true);
    PennyEngine::useDisplayResForUI(true);
    PennyEngine::setRenderResolution({400, 400});
    //PennyEngine::setDisplayResolution({ (int)sf::VideoMode::getDesktopMode().width, (int)sf::VideoMode::getDesktopMode().height });
    //PennyEngine::setDisplayResolution({ 1080, 1080 });
    PennyEngine::setDisplayResolution({ (int)(sf::VideoMode::getDesktopMode().width * 0.6f), (int)(sf::VideoMode::getDesktopMode().height * 0.6f) });

    PennyEngine::setFramerateLimit(60);

    TestGameManager testManager;

    PennyEngine::start(&testManager);
}