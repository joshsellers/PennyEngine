#ifndef _COMPONENT_GRAPHICS_CONFIG_H
#define _COMPONENT_GRAPHICS_CONFIG_H

#include <SFML/Graphics/Rect.hpp>

namespace pe {
    struct ComponentAppearanceConfig {
        ComponentAppearanceConfig(sf::IntRect topLeftCorner, sf::IntRect leftEdge, sf::IntRect bottomLeftCorner,
            sf::IntRect centerTop, sf::IntRect center, sf::IntRect centerBottom,
            sf::IntRect topRightCorner, sf::IntRect rightEdge, sf::IntRect bottomRightCorner) {
            this->topLeftCorner = topLeftCorner;
            this->leftEdge = leftEdge;
            this->bottomLeftCorner = bottomLeftCorner;

            this->centerTop = centerTop;
            this->center = center;
            this->centerBottom = centerBottom;

            this->topRightCorner = topRightCorner;
            this->rightEdge = rightEdge;
            this->bottomRightCorner = bottomRightCorner;
        }

        sf::IntRect topLeftCorner;
        sf::IntRect leftEdge;
        sf::IntRect bottomLeftCorner;

        sf::IntRect centerTop;
        sf::IntRect center;
        sf::IntRect centerBottom;

        sf::IntRect topRightCorner;
        sf::IntRect rightEdge;
        sf::IntRect bottomRightCorner;
    };
}

#endif