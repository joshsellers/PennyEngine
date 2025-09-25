// For this to work, need to set subsystem to "not set" in properties -> linker -> system -> subsystem
#ifdef NO_CONSOLE_ON_STARTUP
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#ifndef _PENNY_ENGINE_H
#define _PENNY_ENGINE_H

#include "core/EngineInstance.h"

class PennyEngine {
public:
    static void start(pe::GameManager* gameManager);
    static bool isStarted();

    static void setFramerateLimit(int framerate);

    static sf::RenderWindow& getWindow();
    static sf::View& getCamera();

    static void setRenderResolution(pe::Resolution res);
    static pe::Resolution getRenderResolution();

    static void autoScaleRenderResolution(bool should);
    static bool shouldAutoScaleRenderResultion();

    static void useDisplayResForUI(bool should);

    static void setDisplayResolution(pe::Resolution res);
    static pe::Resolution getDisplayResolution();

    static void setFullscreen(bool fullscreen);
    static bool windowIsFullscreen();

    static void setWindowTitle(std::string title);
    static std::string getWindowTitle();

private:
    static inline pe::intern::EngineInstance _instance;
};
#endif