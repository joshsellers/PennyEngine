#include "TestGameManager.h"
#include "../PennyEngine/PennyEngine.h"
#include <iostream>
#include "../PennyEngine/audio/SoundManager.h"
#include "../PennyEngine/ui/UI.h"

#include "../PennyEngine/core/Defines.h"

TestGameManager::TestGameManager() : _testObject("MEMBERVARTEST", 1) {
    PennyEngine::addInputListener(this);

    for (int i = 0; i < 5; i++) {
        _testObjects.push_back(new_s_p(TestClass, ("test" + std::to_string(i), 1)));
    }
}

void TestGameManager::update() {
    constexpr float speed = 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) PennyEngine::getCamera().move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) PennyEngine::getCamera().move(0, speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) PennyEngine::getCamera().move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) PennyEngine::getCamera().move(speed, 0);
}

void TestGameManager::draw(sf::RenderTexture& surface) {
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::White);
    shape.setSize({ (float)PennyEngine::getRenderResolution().width, (float)PennyEngine::getRenderResolution().height});
    shape.setPosition(0, 0);

    surface.draw(shape);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(200.f);
    circle.setPosition(PennyEngine::getRenderResolution().width / 2, PennyEngine::getRenderResolution().height / 2);

    surface.draw(circle);

    sf::RectangleShape border;
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Blue);
    border.setOutlineThickness(-2.f);
    border.setSize({ (float)PennyEngine::getRenderResolution().width, (float)PennyEngine::getRenderResolution().height });

    surface.draw(border);
}

void TestGameManager::drawUI(sf::RenderTexture& surface) {
    sf::RectangleShape border;
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Red);
    border.setOutlineThickness(-1.f);
    border.setSize({ (float)surface.getSize().x, (float)surface.getSize().y});

    surface.draw(border);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Blue);
    circle.setRadius(pe::UI::percentToScreenWidth(10));
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(100, 50);

    pe::UI::draw(circle);
}

void TestGameManager::keyPressed(sf::Keyboard::Key& key) {
}

void TestGameManager::keyReleased(sf::Keyboard::Key& key) {
    std::cout << _test << std::endl;

    if (key == sf::Keyboard::Key::Hyphen) PennyEngine::getCamera().zoom(2.f);
    else if (key == sf::Keyboard::Key::Equal) PennyEngine::getCamera().zoom(0.5f);
}

void TestGameManager::mouseButtonPressed(const int mx, const int my, const int button) {
}

void TestGameManager::mouseButtonReleased(const int mx, const int my, const int button) {
    std::cout << button << std::endl;
}

void TestGameManager::mouseMoved(const int mx, const int my) {
}

void TestGameManager::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {
}

void TestGameManager::onShutdown() {
}
