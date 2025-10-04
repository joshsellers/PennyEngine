// Copyright (c) 2025 Josh Sellers
// Licensed under the MIT License. See LICENSE file.

#include "UIManager.h"
#include "../PennyEngine.h"
#include "../core/Logger.h"

pe::intern::UIManager::UIManager() {
    PennyEngine::addInputListener(this);

    if (!_spriteSheet->loadFromFile("res/ui_sprite_sheet.png")) {
        Logger::log("Failed to load UI sprite sheet");
    }
}

void pe::intern::UIManager::update() {
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->update();
    }
}

void pe::intern::UIManager::draw() {
    if (!PennyEngine::isStarted()) return;

    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->draw(*getSurface());
    }
}

std::vector<s_p<pe::Menu>>& pe::intern::UIManager::getMenus() {
    return _menus;
}

void pe::intern::UIManager::setSurface(sf::RenderTexture* surface) {
    _surface = surface;
}

sf::RenderTexture* pe::intern::UIManager::getSurface() {
    return _surface;
}

s_p<sf::Texture> pe::intern::UIManager::getSpriteSheet() const {
    return _spriteSheet;
}

void pe::intern::UIManager::keyPressed(sf::Keyboard::Key& key) {
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->keyPressed(key);
    }
}

void pe::intern::UIManager::keyReleased(sf::Keyboard::Key& key) {
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->keyReleased(key);
    }
}

void pe::intern::UIManager::mouseButtonPressed(const int mx, const int my, const int button) {
    const sf::Vector2f mouseOffset = PennyEngine::getUIMouseOffset();
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->mouseButtonPressed(mx + mouseOffset.x, my + mouseOffset.y, button);
    }
}

void pe::intern::UIManager::mouseButtonReleased(const int mx, const int my, const int button) {
    const sf::Vector2f mouseOffset = PennyEngine::getUIMouseOffset();
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->mouseButtonReleased(mx + mouseOffset.x, my + mouseOffset.y, button);
    }
}

void pe::intern::UIManager::mouseMoved(const int mx, const int my) {
    const sf::Vector2f mouseOffset = PennyEngine::getUIMouseOffset();
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->mouseMoved(mx + mouseOffset.x, my + mouseOffset.y);
    }
}

void pe::intern::UIManager::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->mouseWheelScrolled(mouseWheelScroll);
    }
}

void pe::intern::UIManager::controllerButtonReleased(GAMEPAD_BUTTON button) {
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->controllerButtonReleased(button);
    }
}

void pe::intern::UIManager::controllerButtonPressed(GAMEPAD_BUTTON button) {
    for (const auto& menu : getMenus()) {
        if (menu->isActive()) menu->controllerButtonPressed(button);
    }
}

void pe::intern::UIManager::gamepadDisconnected() {

}

void pe::intern::UIManager::gamepadConnected() {
}
