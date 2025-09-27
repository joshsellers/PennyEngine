#include "UIManager.h"
#include "../PennyEngine.h"

pe::intern::UIManager::UIManager() {
    PennyEngine::addInputListener(this);
}

void pe::intern::UIManager::update() {
}

void pe::intern::UIManager::draw() {
    if (!PennyEngine::isStarted()) return;

    // draw menus
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

void pe::intern::UIManager::keyPressed(sf::Keyboard::Key& key) {
}

void pe::intern::UIManager::keyReleased(sf::Keyboard::Key& key) {
}

void pe::intern::UIManager::mouseButtonPressed(const int mx, const int my, const int button) {
}

void pe::intern::UIManager::mouseButtonReleased(const int mx, const int my, const int button) {
}

void pe::intern::UIManager::mouseMoved(const int mx, const int my) {
}

void pe::intern::UIManager::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {
}

void pe::intern::UIManager::controllerButtonReleased(GAMEPAD_BUTTON button) {
}

void pe::intern::UIManager::controllerButtonPressed(GAMEPAD_BUTTON button) {
}

void pe::intern::UIManager::gamepadDisconnected() {
}

void pe::intern::UIManager::gamepadConnected() {
}
