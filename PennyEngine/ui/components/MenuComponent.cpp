#include "MenuComponent.h"
#include "../UI.h"

pe::MenuComponent::MenuComponent(const std::string id, float x, float y, float width, float height, sf::Font font, bool autoCenter) : _id(id) {

    _pos = UI::percentToScreenPos(x, y);
    _size = UI::percentToScreenDimensions(width, height);

    _font = font;

    if (autoCenter) {
        _shape.setPosition(_pos.x - _size.x / 2.f, _pos.y - _size.y / 2.f);
    } else _shape.setPosition(_pos);
}

void pe::MenuComponent::render(sf::RenderTexture& surface, const sf::RenderStates& states) {
    alignText();

    surface.draw(_shape, states);
    surface.draw(_text);

    draw(surface);
}

void pe::MenuComponent::alignText() {
    if (!_disableAutomaticTextAlignment) {
        _text.setPosition(
            _shape.getPosition().x + _shape.getGlobalBounds().width / 2 - _text.getGlobalBounds().width / 2,
            _shape.getPosition().y + _text.getGlobalBounds().height / 2
        );
    }
}

void pe::MenuComponent::show() {
    _isActive = true;
}

void pe::MenuComponent::hide() {
    _isActive = false;
}

bool pe::MenuComponent::isActive() const {
    return _isActive;
}

void pe::MenuComponent::setGamepadSelectionId(int selectionId) {
    _selectionId = selectionId;
}

int pe::MenuComponent::getGamepadSelectionId() const {
    return _selectionId;
}

void pe::MenuComponent::setCharacterSize(float size) {
    _text.setCharacterSize(UI::percentToScreenWidth(size));
}

std::string pe::MenuComponent::getIdentifier() const {
    return _id;
}

void pe::MenuComponent::controllerButtonReleased(GAMEPAD_BUTTON button) {
}

void pe::MenuComponent::controllerButtonPressed(GAMEPAD_BUTTON button) {
}

void pe::MenuComponent::keyPressed(sf::Keyboard::Key& key) {
}

void pe::MenuComponent::keyReleased(sf::Keyboard::Key& key) {
}

void pe::MenuComponent::mouseButtonPressed(const int mx, const int my, const int button) {
}

void pe::MenuComponent::mouseButtonReleased(const int mx, const int my, const int button) {
}

void pe::MenuComponent::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {
}

void pe::MenuComponent::textEntered(const sf::Uint32 character) {
}
