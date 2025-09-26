#ifndef _UI_H
#define _UI_H

#include "UIManager.h"
#include <SFML/System/Vector2.hpp>
#include "../core/EngineInstance.h"

#include "../PennyEngine.h"

namespace pe {
    class UI {
    public:
        static sf::Vector2f percentToScreenPos(sf::Vector2f pos);
        static sf::Vector2f percentToScreenPos(float x, float y);
        static sf::Vector2f percentToScreenDimensions(sf::Vector2f dimensions);
        static sf::Vector2f percentToScreenDimensions(float x, float y);
        static float percentToScreenWidth(float width);
        static float percentToScreenHeight(float height);

        template <typename T>
        static void draw(T& graphic) {
            if (!PennyEngine::isStarted()) return;
            static_assert(std::is_base_of<sf::Drawable, T>::value, "pe::UI::draw parameter must be a subclass of sf::Drawable");
            static_assert(std::is_base_of<sf::Transformable, T>::value, "pe::UI::draw parameter must be a subclass of sf::Transformable");

            graphic.setPosition(percentToScreenPos(graphic.getPosition()));
            _instance.getSurface()->draw(graphic);
        }

        // void addMenu();
        // void getMenu(std::string identifier); // elements/components could have identifiers too & menu can have a getElement(std::string identifier)
                                                 // could use maps instead of vectors for this
                                                 // so we don't have to store shared_ptrs to elements or menus as member vars anywhere
                                                 // call elements either MenuElement or MenuComponent
                                                 // menu->addSubMenu(menu) / UI::getMenu(id)->addSubMenu(menu)
                                                 // Menu::close(openSuperMenu = true) - by default opens the next menu higher in the chain
                                                 // Menu::open(closeSupermenus = true) - by default closes all menus higher in the chain
                                                 // Don't forget pendingActivation thing, check PL UIMenu.cpp
                                                 // should still be able to close supermenus IN Menu::open
                                                 // Also look at what's going on in PL UIMenu::show/hide

        friend class pe::intern::EngineInstance;
    private:
        static inline intern::UIManager _instance;
    };
}

#endif