#include "MenuComponent.h"
#include "../UI.h"
#include "../../core/Logger.h"

pe::MenuComponent::MenuComponent(const std::string id, float x, float y, float width, float height, sf::Font font, bool autoCenter, ComponentAppearanceConfig appearance) : 
    _id(id), _appearance(appearance) {
    _pos = UI::percentToScreenPos(x, y);
    _size = UI::percentToScreenDimensions(width, height);

    _font = font;

    _appearance = appearance;

    if (autoCenter) {
        _pos.x -= _size.x / 2.f;
        _pos.y -= _size.y / 2.f;
    }

    const auto& spriteSheet = UI::getSpriteSheet().get();
    _leftEdge.setTexture(spriteSheet);
    _leftTopCorner.setTexture(spriteSheet);
    _leftBottomCorner.setTexture(spriteSheet);
    _center.setTexture(spriteSheet);
    _centerTop.setTexture(spriteSheet);
    _centerBottom.setTexture(spriteSheet);
    _rightEdge.setTexture(spriteSheet);
    _rightTopCorner.setTexture(spriteSheet);
    _rightBottomCorner.setTexture(spriteSheet);
}

void pe::MenuComponent::render(sf::RenderTexture& surface, const sf::RenderStates& states) {
    drawShapes(surface, states);

    alignText();
    surface.draw(_text);

    draw(surface);
}

void pe::MenuComponent::drawShapes(sf::RenderTexture& surface, const sf::RenderStates& states) {
    const float padding = 0;//UI::percentToScreenWidth(1.5f);

    const float x = _pos.x - padding;
    const float y = _pos.y;
    const float width = _size.x + padding * 2;
    const float height = _size.y;

    const float pixelSize = UI::percentToScreenWidth(_appearance.pixelSize);

    _leftEdge.setSize({ pixelSize * _appearance.leftEdge.width, height });
    _leftEdge.setPosition(x, y);
    _leftEdge.setTextureRect({ _appearance.leftEdge.left, _appearance.leftEdge.top, _appearance.leftEdge.width, _appearance.leftEdge.height });

    _leftTopCorner.setSize({ pixelSize * _appearance.topLeftCorner.width, pixelSize * _appearance.topLeftCorner.height });
    _leftTopCorner.setPosition(x, y - pixelSize * _appearance.topLeftCorner.height);
    _leftTopCorner.setTextureRect({ _appearance.topLeftCorner.left, _appearance.topLeftCorner.top, _appearance.topLeftCorner.width, _appearance.topLeftCorner.height });

    _leftBottomCorner.setSize({ pixelSize * _appearance.bottomLeftCorner.width, pixelSize * _appearance.bottomLeftCorner.height });
    _leftBottomCorner.setPosition(x, y + _leftEdge.getGlobalBounds().height);
    _leftBottomCorner.setTextureRect({ _appearance.bottomLeftCorner.left, _appearance.bottomLeftCorner.top, _appearance.bottomLeftCorner.width, _appearance.bottomLeftCorner.height });

    _center.setSize({ width - _leftEdge.getGlobalBounds().width, height });
    _center.setPosition(x + _leftEdge.getGlobalBounds().width, y);
    _center.setTextureRect({ _appearance.center.left, _appearance.center.top, _appearance.center.width, _appearance.center.height });

    _centerTop.setSize({ width - _leftTopCorner.getGlobalBounds().width, pixelSize * _appearance.centerTop.height });
    _centerTop.setPosition(_leftTopCorner.getGlobalBounds().width + _leftTopCorner.getPosition().x, y - pixelSize * _appearance.centerTop.height);
    _centerTop.setTextureRect({ _appearance.centerTop.left, _appearance.centerTop.top, _appearance.centerTop.width, _appearance.centerTop.height });

    _centerBottom.setSize({ width - _leftEdge.getGlobalBounds().width, pixelSize * _appearance.centerBottom.height });
    _centerBottom.setPosition(x + _leftEdge.getGlobalBounds().width, y + _center.getGlobalBounds().height);
    _centerBottom.setTextureRect({ _appearance.centerBottom.left, _appearance.centerBottom.top, _appearance.centerBottom.width, _appearance.centerBottom.height });

    _rightEdge.setSize({ pixelSize * _appearance.rightEdge.width, height });
    _rightEdge.setPosition(x + _leftEdge.getGlobalBounds().width + _center.getGlobalBounds().width, y);
    _rightEdge.setTextureRect({ _appearance.rightEdge.left, _appearance.rightEdge.top, _appearance.rightEdge.width, _appearance.rightEdge.height });

    _rightTopCorner.setSize({ pixelSize * _appearance.topRightCorner.width, pixelSize * _appearance.topRightCorner.height });
    _rightTopCorner.setPosition(x + _leftEdge.getGlobalBounds().width + _center.getGlobalBounds().width, y - pixelSize * _appearance.topRightCorner.height);
    _rightTopCorner.setTextureRect({ _appearance.topRightCorner.left, _appearance.topRightCorner.top, _appearance.topRightCorner.width, _appearance.topRightCorner.height });

    _rightBottomCorner.setSize({ pixelSize * _appearance.bottomRightCorner.width, pixelSize * _appearance.bottomRightCorner.height });
    _rightBottomCorner.setPosition(x + _leftEdge.getGlobalBounds().width + _center.getGlobalBounds().width, y + _rightEdge.getGlobalBounds().height);
    _rightBottomCorner.setTextureRect({ _appearance.bottomRightCorner.left, _appearance.bottomRightCorner.top, _appearance.bottomRightCorner.width, _appearance.bottomRightCorner.height });

    constexpr int maxAttempts = 10;
    int timesLeft = 1;
    while (!_leftEdge.getGlobalBounds().intersects(_center.getGlobalBounds())) {
        constexpr float gapCorrectionStep = 0.1f;
        _leftTopCorner.move(gapCorrectionStep, 0);
        _leftEdge.move(gapCorrectionStep, 0);
        _leftBottomCorner.move(gapCorrectionStep, 0);
        timesLeft++;
        if (timesLeft > maxAttempts) break;
    }

    int timesRight = 1;
    while (!_rightEdge.getGlobalBounds().intersects(_center.getGlobalBounds())) {
        constexpr float gapCorrectionStep = -0.1f;
        _rightTopCorner.move(gapCorrectionStep, 0);
        _rightEdge.move(gapCorrectionStep, 0);
        _rightBottomCorner.move(gapCorrectionStep, 0);
        timesRight++;
        if (timesRight > maxAttempts) break;
    } 

    if (timesLeft > 5 || timesRight > 5) {
        Logger::log("Cap correction took longer than five attempts\ntimesLeft was: " + std::to_string(timesLeft) + "\ntimesRight was: " + std::to_string(timesRight));
    }

    surface.draw(_leftEdge);
    surface.draw(_leftTopCorner);
    surface.draw(_leftBottomCorner);
    surface.draw(_center);
    surface.draw(_centerTop);
    surface.draw(_centerBottom);
    surface.draw(_rightEdge);
    surface.draw(_rightTopCorner);
    surface.draw(_rightBottomCorner);
}

void pe::MenuComponent::alignText() {
    if (!_disableAutomaticTextAlignment) {
        _text.setOrigin(_text.getLocalBounds().width / 2.f + _text.getLocalBounds().left, _text.getLocalBounds().height / 2.f + _text.getLocalBounds().top);
       
        const sf::FloatRect bounds = getBounds();
        const float width = bounds.width;
        const float height = bounds.height;
        _text.setPosition(
            bounds.left + (width / 2.f),
            bounds.top + (height / 2.f)
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

void pe::MenuComponent::setAppearance(ComponentAppearanceConfig appearance) {
    _appearance = appearance;
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

sf::FloatRect pe::MenuComponent::getBounds() const {
    const float width = _leftEdge.getSize().x + _center.getSize().x + _rightEdge.getSize().x;
    const float height = _centerTop.getSize().y + _center.getSize().y + _centerBottom.getSize().y;
    return {_pos.x, _pos.y - _centerTop.getSize().y, width, height};
}
