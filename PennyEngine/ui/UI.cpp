#include "UI.h"
#include "../core/Resolution.h"
#include "../core/Logger.h"

sf::Vector2f pe::UI::percentToScreenPos(sf::Vector2f pos) {
    const Resolution res = PennyEngine::useDisplayResForUI() ? PennyEngine::getDisplayResolution() : PennyEngine::getRenderResolution();
    return sf::Vector2f((float)res.width * (pos.x / 100.f), (float)res.height * (pos.y / 100.f));
}

sf::Vector2f pe::UI::percentToScreenPos(float x, float y) {
    return percentToScreenPos({ x, y });
}

sf::Vector2f pe::UI::percentToScreenDimensions(sf::Vector2f dimensions) {
    return percentToScreenPos(dimensions);
}

sf::Vector2f pe::UI::percentToScreenDimensions(float x, float y) {
    return percentToScreenPos(x, y);
}

float pe::UI::percentToScreenWidth(float width) {
    const Resolution res = PennyEngine::useDisplayResForUI() ? PennyEngine::getDisplayResolution() : PennyEngine::getRenderResolution();
    return (float)res.width * (width / 100.f);
}

float pe::UI::percentToScreenHeight(float height) {
    const Resolution res = PennyEngine::useDisplayResForUI() ? PennyEngine::getDisplayResolution() : PennyEngine::getRenderResolution();
    return (float)res.height * (height / 100.f);
}

void pe::UI::addMenu(s_p<Menu> menu) {
    _instance.getMenus().push_back(menu);
}

s_p<pe::Menu> pe::UI::getMenu(std::string id) {
    for (const auto& menu : _instance.getMenus()) {
        if (menu->getIdentifier() == id) return menu;
    }

    Logger::log("Did not find menu with id \"" + id + "\"");
    return nullptr;
}

s_p<sf::Texture> pe::UI::getSpriteSheet() {
    return _instance.getSpriteSheet();
}