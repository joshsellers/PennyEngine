#include "Menu.h"

pe::Menu::Menu(const std::string id) : _id(id) {
}

void pe::Menu::update() {
}

void pe::Menu::draw(sf::RenderTexture& surface) {
}

void pe::Menu::addComponent(s_p<MenuComponent> component) {

}

s_p<pe::MenuComponent> pe::Menu::getComponent(std::string id) const {

}

std::vector<s_p<pe::MenuComponent>> pe::Menu::getComponents() const {

}

void pe::Menu::clearComponents() {
}

void pe::Menu::addChild(s_p<Menu> menu) {

}

s_p<pe::Menu> pe::Menu::getChild(std::string id) const {

}

std::vector<s_p<pe::Menu>> pe::Menu::getChildren() const {

}

void pe::Menu::setParent(s_p<pe::Menu> menu) {

}

s_p<pe::Menu> pe::Menu::getParent() const {

}

void pe::Menu::open(bool closeParents) {

}

void pe::Menu::close(bool openParent) {

}

bool pe::Menu::isActive() const {
    return _isActive;
}

void pe::Menu::defineGamepadSelectionGrid(std::vector<std::vector<int>> grid) {
}

std::string pe::Menu::getIdentifier() const {
    return _id;
}

void pe::Menu::controllerButtonReleased(GAMEPAD_BUTTON button) {
}

void pe::Menu::controllerButtonPressed(GAMEPAD_BUTTON button) {
}

void pe::Menu::keyPressed(sf::Keyboard::Key& key) {
}

void pe::Menu::keyReleased(sf::Keyboard::Key& key) {
}

void pe::Menu::mouseButtonPressed(const int mx, const int my, const int button) {
}

void pe::Menu::mouseButtonReleased(const int mx, const int my, const int button) {
}

void pe::Menu::mouseMoved(const int mx, const int my) {
}

void pe::Menu::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {
}

void pe::Menu::textEntered(sf::Uint32 character) {
}
