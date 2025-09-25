#include "TestGameManager.h"
#include "../PennyEngine/PennyEngine.h"
#include <iostream>

TestGameManager::TestGameManager() : _testObject("MEMBERVARTEST") {
    PennyEngine::addInputListener(this);

    for (int i = 0; i < 5; i++) {
        _testObjects.push_back(std::shared_ptr<TestClass>(new TestClass("test" + std::to_string(i))));
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
}

void TestGameManager::keyPressed(sf::Keyboard::Key& key) {
}

void TestGameManager::keyReleased(sf::Keyboard::Key& key) {
    std::cout << _test << std::endl;
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
