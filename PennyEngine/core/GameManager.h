#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H
#include "SFML/Graphics.hpp"

namespace pe {
    class GameManager {
    public:
        virtual void update() = 0;
        virtual void draw(sf::RenderTexture& surface) = 0;
        virtual void drawUI(sf::RenderTexture& surface) = 0;

        void renderUI(sf::RenderTexture& surface);
    protected:

    private:

    };
}

#endif