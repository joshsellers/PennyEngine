#include "TestGameManager.h"
#include "../PennyEngine/PennyEngine.h"
#include <iostream>
#include "../PennyEngine/audio/SoundManager.h"
#include "../PennyEngine/ui/UI.h"
#include "../PennyEngine/ui/components/Button.h"
#include "../PennyEngine/core/Defines.h"

TestGameManager::TestGameManager() : _testObject("MEMBERVARTEST", 1) {
    if (!_font.loadFromFile("res/font.ttf")) {
        pe::Logger::log("Failed to load font");
    }

    PennyEngine::addInputListener(this);

    for (int i = 0; i < 5; i++) {
        _testObjects.push_back(new_s_p(TestClass, ("test" + std::to_string(i), 1)));
    }

    pe::BUTTON_HOVER_CONFIG = pe::BASE_COMPONENT_CONFIG.offsetBy(48, 0);
    pe::BUTTON_CLICKED_CONFIG = pe::BUTTON_HOVER_CONFIG.offsetBy(48, 0);

    const auto& startMenu = new_s_p(pe::Menu, ("startMenu"));
    startMenu->addComponent(new_s_p(pe::Button, ("startButton", 50, 50, 9, 1, "start", _font, this)));
    startMenu->getComponent("startButton")->setGamepadSelectionId(0);
    startMenu->addComponent(new_s_p(pe::Button, ("settingsButton", 50, 55, 9, 1, "settings", _font, this)));
    startMenu->getComponent("settingsButton")->setGamepadSelectionId(1);
    startMenu->addComponent(new_s_p(pe::Button, ("exitButton", 50, 60, 9, 1, "exit", _font, this)));
    startMenu->getComponent("exitButton")->setGamepadSelectionId(2);
    startMenu->defineGamepadSelectionGrid({
        {0},
        {1},
        {2}
    });

    startMenu->open();
    pe::UI::addMenu(startMenu);

    const auto& subStartMenu = new_s_p(pe::Menu, ("subStartMenu"));
    subStartMenu->addComponent(new_s_p(pe::Button, ("test0", 50, 50, 9, 1, "test0", _font, this)));
    subStartMenu->getComponent("test0")->setGamepadSelectionId(0);
    subStartMenu->addComponent(new_s_p(pe::Button, ("test1", 50, 55, 9, 1, "test1", _font, this)));
    subStartMenu->getComponent("test1")->setGamepadSelectionId(1);
    subStartMenu->addComponent(new_s_p(pe::Button, ("back_subStartMenu", 50, 60, 9, 1, "back", _font, this)));
    subStartMenu->getComponent("back_subStartMenu")->setGamepadSelectionId(2);
    subStartMenu->defineGamepadSelectionGrid({
        {0},
        {1},
        {2}
    });

    startMenu->addChild(subStartMenu);
    pe::UI::addMenu(subStartMenu);

    pe::UI::addMenu(new_s_p(pe::Menu, ("settingsMenu")));
    pe::UI::getMenu("settingsMenu")->addComponent(new_s_p(pe::Button, ("fullscreen", 50, 50, 9, 1, "fullscreen", _font, this)));
    pe::UI::getMenu("settingsMenu")->getComponent("fullscreen")->setGamepadSelectionId(0);
    pe::UI::getMenu("settingsMenu")->addComponent(new_s_p(pe::Button, ("back_settingsMenu", 50, 55, 9, 1, "back", _font, this)));
    pe::UI::getMenu("settingsMenu")->getComponent("back_settingsMenu")->setGamepadSelectionId(1);
    pe::UI::getMenu("settingsMenu")->defineGamepadSelectionGrid({
        {0},
        {1}
    });

    pe::UI::getMenu("startMenu")->addChild(pe::UI::getMenu("settingsMenu"));
}

void TestGameManager::buttonPressed(std::string buttonId) {
    pe::Logger::log(buttonId);
    if (buttonId == "startButton") {
        pe::UI::getMenu("subStartMenu")->open();
    } else if (buttonId == "settingsButton") {
        pe::UI::getMenu("settingsMenu")->open();
    } else if (buttonId == "exitButton") {
        PennyEngine::stop();
    } else if (pe::stringStartsWith(buttonId, "back_")) {
        pe::UI::getMenu(pe::splitString(buttonId, "_")[1])->close();
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

    /*sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(200.f);
    circle.setPosition(PennyEngine::getRenderResolution().width / 2, PennyEngine::getRenderResolution().height / 2);

    surface.draw(circle);*/

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

    /*sf::CircleShape circle;
    circle.setFillColor(sf::Color::Blue);
    circle.setRadius(pe::UI::percentToScreenWidth(10));
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(100, 50);

    pe::UI::draw(circle);*/
}

void TestGameManager::keyPressed(sf::Keyboard::Key& key) {
}

void TestGameManager::keyReleased(sf::Keyboard::Key& key) {
    std::cout << _test << std::endl;

    if (key == sf::Keyboard::Key::Hyphen) PennyEngine::getCamera().zoom(2.f);
    else if (key == sf::Keyboard::Key::Equal) PennyEngine::getCamera().zoom(0.5f);

    if (key == sf::Keyboard::Key::Escape) PennyEngine::stop();
}

void TestGameManager::mouseButtonPressed(const int mx, const int my, const int button) {
}

void TestGameManager::mouseButtonReleased(const int mx, const int my, const int button) {
    //std::cout << button << std::endl;
}

void TestGameManager::mouseMoved(const int mx, const int my) {
}

void TestGameManager::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {
}

void TestGameManager::onShutdown() {
}
