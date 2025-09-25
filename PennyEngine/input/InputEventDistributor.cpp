#include "InputEventDistributor.h"

void pe::intern::InputEventDistributor::handleEvent(sf::Event& event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
        {
            for (const auto& listener : _keyListeners) listener->keyPressed(event.key.code);
            break;
        }
        
        case sf::Event::KeyReleased:
        {
            for (const auto& listener : _keyListeners) listener->keyReleased(event.key.code);
            break;
        }

        case sf::Event::MouseButtonPressed:
        {
            for (const auto& listener : _mouseListeners) listener->mouseButtonPressed(event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
            break;
        }

        case sf::Event::MouseButtonReleased:
        {
            for (const auto& listener : _mouseListeners) listener->mouseButtonReleased(event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
            break;
        }

        case sf::Event::MouseMoved:
        {
            for (const auto& listener : _mouseListeners) listener->mouseMoved(event.mouseMove.x, event.mouseMove.y);
            break;
        }

        case sf::Event::MouseWheelScrolled:
        {
            for (const auto& listener : _mouseListeners) listener->mouseWheelScrolled(event.mouseWheelScroll);
            break;
        }
    }
}

void pe::intern::InputEventDistributor::addListener(InputListener* listener) {
    if (listener->_isKeyListener) {
        _keyListeners.push_back(dynamic_cast<KeyListener*>(listener));
    }

    if (listener->_isMouseListener) {
        _mouseListeners.push_back(dynamic_cast<MouseListener*>(listener));
    }
}
