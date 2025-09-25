#include "EngineInstance.h"
#include <iostream>

void pe::intern::EngineInstance::start(GameManager* gameManager) {
    this->gameManager = gameManager;
    createWindow();

    //shutdown();
}

void pe::intern::EngineInstance::createWindow() {
    const Resolution physicalRes = { (int)sf::VideoMode::getDesktopMode().width, (int)sf::VideoMode::getDesktopMode().height };

    if (renderRes == Resolution(0, 0)) {
        constexpr float windowSize = 0.7f;
        if (displayRes == Resolution(0, 0)) {
            renderRes = {
                (int)((float)sf::VideoMode::getDesktopMode().width * windowSize),
                (int)((float)sf::VideoMode::getDesktopMode().height * windowSize)
            };

            displayRes = renderRes;
        } else {
            renderRes = displayRes;
        }
    } else if (displayRes == Resolution(0, 0)) {
        displayRes = renderRes;
    } else if (displayRes != renderRes && autoScaleRenderRes) {
        renderRes.height = (float)renderRes.width / ((float)displayRes.width / (float)displayRes.height);
    }

    const sf::Vector2u windowRes = fullscreen ? 
        sf::Vector2u((unsigned int)physicalRes.width, (unsigned int)physicalRes.height) : sf::Vector2u((unsigned int)displayRes.width, (unsigned int)displayRes.height);

    window.create(sf::VideoMode(windowRes.x, windowRes.y), windowTitle, fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    if (framerateLimit != 0) window.setFramerateLimit(framerateLimit);

    camera.setCenter((float)renderRes.width / 2, (float)renderRes.height / 2);
    camera.setSize(renderRes.width, renderRes.height);

    // check for icon and cursor file and if found set them

    bool adjustForFullscreen = false;
    if (fullscreen && physicalRes != displayRes) {
        float scale = 1.0;
        if (displayRes.width > displayRes.height) {
            scale = (float)physicalRes.width / (float)displayRes.width;
        } else {
            scale = (float)physicalRes.height / (float)displayRes.height;
        }

        displayRes.width *= scale;
        displayRes.height *= scale;

        adjustForFullscreen = true;
    }

    sf::RenderTexture mainSurface;
    mainSurface.create(renderRes.width, renderRes.height);
    const sf::Texture& mainSurfaceTexture = mainSurface.getTexture();

    sf::Sprite mainSurfaceSprite;
    mainSurfaceSprite.setTexture(mainSurfaceTexture);
    if (renderRes != displayRes && autoScaleRenderRes) {
        mainSurfaceSprite.setScale((float)displayRes.width / (float)renderRes.width, (float)displayRes.height / (float)renderRes.height);

        if (adjustForFullscreen) {
            mainSurfaceSprite.setPosition((float)physicalRes.width / 2.f - (float)mainSurfaceSprite.getGlobalBounds().width / 2.f,
                (float)physicalRes.height / 2.f - (float)mainSurfaceSprite.getGlobalBounds().height / 2.f);
        }
    } else if (!autoScaleRenderRes && renderRes != displayRes) {
        float scale = 1.f;
        if (renderRes.width > renderRes.height) {
            scale = (float)displayRes.width / (float)renderRes.width;
        } else {
            scale = (float)displayRes.height / (float)renderRes.height;
        }

        mainSurfaceSprite.setScale(scale, scale);

        if (!adjustForFullscreen) {
            mainSurfaceSprite.setPosition((float)displayRes.width / 2.f - (float)mainSurfaceSprite.getGlobalBounds().width / 2.f,
                (float)displayRes.height / 2.f - (float)mainSurfaceSprite.getGlobalBounds().height / 2.f);
        } else {
            mainSurfaceSprite.setPosition((float)physicalRes.width / 2.f - (float)mainSurfaceSprite.getGlobalBounds().width / 2.f,
                (float)physicalRes.height / 2.f - (float)mainSurfaceSprite.getGlobalBounds().height / 2.f);
        }
    }

    sf::RenderTexture uiSurface;
    uiSurface.create(useDisplayResForUI ? displayRes.width : renderRes.width, useDisplayResForUI ? displayRes.height : renderRes.height);
    const sf::Texture& uiSurfaceTexture = uiSurface.getTexture();

    sf::Sprite uiSurfaceSprite;
    uiSurfaceSprite.setTexture(uiSurfaceTexture);
    if (!useDisplayResForUI) {
        if (renderRes != displayRes && autoScaleRenderRes) {
            uiSurfaceSprite.setScale((float)displayRes.width / (float)renderRes.width, (float)displayRes.height / (float)renderRes.height);

            if (adjustForFullscreen) {
                uiSurfaceSprite.setPosition((float)physicalRes.width / 2.f - (float)uiSurfaceSprite.getGlobalBounds().width / 2.f,
                    (float)physicalRes.height / 2.f - (float)uiSurfaceSprite.getGlobalBounds().height / 2.f);
            }
        } else if (!autoScaleRenderRes && renderRes != displayRes) {
            float scale = 1.f;
            if (renderRes.width > renderRes.height) {
                scale = (float)displayRes.width / (float)renderRes.width;
            } else {
                scale = (float)displayRes.height / (float)renderRes.height;
            }

            uiSurfaceSprite.setScale(scale, scale);

            if (!adjustForFullscreen) {
                uiSurfaceSprite.setPosition((float)displayRes.width / 2.f - (float)uiSurfaceSprite.getGlobalBounds().width / 2.f,
                    (float)displayRes.height / 2.f - (float)uiSurfaceSprite.getGlobalBounds().height / 2.f);
            } else {
                uiSurfaceSprite.setPosition((float)physicalRes.width / 2.f - (float)uiSurfaceSprite.getGlobalBounds().width / 2.f,
                    (float)physicalRes.height / 2.f - (float)uiSurfaceSprite.getGlobalBounds().height / 2.f);
            }
        }
    } else if (adjustForFullscreen) {
        uiSurfaceSprite.setPosition((float)physicalRes.width / 2.f - (float)uiSurfaceSprite.getGlobalBounds().width / 2.f,
            (float)physicalRes.height / 2.f - (float)uiSurfaceSprite.getGlobalBounds().height / 2.f);
    }

    _started = true;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        gameManager->update();

        mainSurface.setView(camera);

        mainSurface.clear();
        gameManager->draw(mainSurface);

        mainSurface.display();

        uiSurface.clear(sf::Color::Transparent);
        gameManager->renderUI(uiSurface);
        uiSurface.display();

        window.clear();
        window.draw(mainSurfaceSprite);
        window.draw(uiSurfaceSprite);
        window.display();
    }
}

bool pe::intern::EngineInstance::isStarted() const {
    return _started;
}