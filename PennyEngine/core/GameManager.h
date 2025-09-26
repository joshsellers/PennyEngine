#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H
#include "SFML/Graphics.hpp"

namespace pe {
    class GameManager {
    public:
        virtual void update() = 0;
        virtual void draw(sf::RenderTexture& surface) = 0;
        virtual void drawUI(sf::RenderTexture& surface) = 0;

        virtual void renderUI(sf::RenderTexture& surface);

        virtual void onShutdown() = 0;
    protected:

    private:

    };
}

#endif