// Copyright (c) 2025 Josh Sellers
// Licensed under the MIT License. See LICENSE file.

#include "TestGameManager.h"
#include "../PennyEngine/PennyEngine.h"
#include <iostream>
#include "../PennyEngine/audio/SoundManager.h"
#include "../PennyEngine/ui/UI.h"
#include "../PennyEngine/ui/components/Button.h"
#include "../PennyEngine/ui/components/Panel.h"
#include "../PennyEngine/ui/components/Slider.h"
#include "../PennyEngine/ui/components/TextField.h"
#include "../PennyEngine/core/Defines.h"

TestGameManager::TestGameManager() {
    
}

void TestGameManager::init() {
    PennyEngine::addInputListener(this);

    const auto& panel = new_s_p(pe::Panel, ("panel", 50, 50, 10, 20, "menu", true));
    panel->setTextPosition(50, 10);

    const auto& menu = pe::UI::addMenu("menu");
    menu->addComponent(new_s_p(pe::Button, ("open_startMenu", 50, 47, 7, 3, "start", this)));
    menu->getComponent("open_startMenu")->setGamepadSelectionId(0);
    menu->addComponent(new_s_p(pe::Button, ("open_settings", 50, 52, 7, 3, "settings", this)));
    menu->getComponent("open_settings")->setGamepadSelectionId(1);
    menu->addComponent(new_s_p(pe::Button, ("exit", 50, 57, 7, 3, "exit", this)));
    menu->getComponent("exit")->setGamepadSelectionId(2);
    menu->defineGamepadSelectionGrid({
        {0},
        {1},
        {2}
    });

    menu->addComponent(panel);
    panel->attach("open_startMenu");
    panel->attach("open_settings");
    panel->attach("exit");
    menu->open();

    const auto& settingsMenu = pe::UI::addMenu("settings");
    menu->addChild(settingsMenu);
    settingsMenu->addComponent(new_s_p(pe::Slider, ("volume", 50, 47, { 7, 1 }, { 1, 1 }, "volume", this)));
    settingsMenu->getComponent("volume")->setGamepadSelectionId(0);
    settingsMenu->addComponent(new_s_p(pe::Button, ("back_settings", 50, 57, 7, 3, "back", this)));
    settingsMenu->getComponent("back_settings")->setGamepadSelectionId(1);
    settingsMenu->defineGamepadSelectionGrid({
        {0},
        {1}
    });

    settingsMenu->addComponent(panel);
    panel->attach("volume");
    panel->attach("back_settings");

    const auto& startMenu = pe::UI::addMenu("startMenu");
    menu->addChild(startMenu);
    startMenu->addComponent(new_s_p(pe::TextField, ("testTextField", 50, 47, 7, 3, "textField", "test")));
    startMenu->getComponent("testTextField")->setGamepadSelectionId(0);
    startMenu->addComponent(new_s_p(pe::Button, ("back_startMenu", 50, 52, 7, 3, "back", this)));
    startMenu->getComponent("back_startMenu")->setGamepadSelectionId(1);
    startMenu->defineGamepadSelectionGrid({
        {0},
        {1}
    });

    startMenu->addComponent(panel);
    panel->attach("testTextField");
    panel->attach("back_startMenu");
}

void TestGameManager::buttonPressed(std::string buttonId) {
    pe::Logger::log(buttonId);
    if (buttonId == "exit") {
        PennyEngine::stop();
    } else if (pe::stringStartsWith(buttonId, "back_")) {
        pe::UI::getMenu(pe::splitString(buttonId, "_")[1])->close();
    } else if (pe::stringStartsWith(buttonId, "open_")) {
        pe::UI::getMenu(pe::splitString(buttonId, "_")[1])->open();
    }
}

void TestGameManager::sliderMoved(std::string sliderId, float value) {
    pe::Logger::log(sliderId + ": " + std::to_string(value));
}

void TestGameManager::update() {
    /*constexpr float speed = 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) PennyEngine::getCamera().move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) PennyEngine::getCamera().move(0, speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) PennyEngine::getCamera().move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) PennyEngine::getCamera().move(speed, 0);*/
}

void TestGameManager::draw(sf::RenderTexture& surface) {
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color(0x665867FF));
    shape.setSize({ (float)PennyEngine::getRenderResolution().width, (float)PennyEngine::getRenderResolution().height});
    shape.setPosition(0, 0);

   surface.draw(shape);

    /*sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(200.f);
    circle.setPosition(PennyEngine::getRenderResolution().width / 2, PennyEngine::getRenderResolution().height / 2);

    surface.draw(circle);*/

    /*sf::RectangleShape border;
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Blue);
    border.setOutlineThickness(-2.f);
    border.setSize({ (float)PennyEngine::getRenderResolution().width, (float)PennyEngine::getRenderResolution().height });

    surface.draw(border);*/
}

void TestGameManager::drawUI(sf::RenderTexture& surface) {
    /*sf::RectangleShape border;
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Red);
    border.setOutlineThickness(-1.f);
    border.setSize({ (float)surface.getSize().x, (float)surface.getSize().y});

    surface.draw(border);*/

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
