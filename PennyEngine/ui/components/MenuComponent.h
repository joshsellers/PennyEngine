#ifndef _MENU_COMPONENT_H
#define _MENU_COMPONENT_H

#include "SFML/Graphics/Font.hpp"
#include <SFML/Graphics/RenderStates.hpp>
#include "../../input/gamepad/GamepadButtons.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ComponentAppearanceConfig.h"
#include "AppearanceConfigs.h"

namespace pe {
    class MenuComponent {
    public:
        MenuComponent(const std::string id, float x, float y, float width, float height, sf::Font font, bool autoCenter = true, ComponentAppearanceConfig appearance = BASE_COMPONENT_CONFIG);

        virtual void show();
        void hide();
        bool isActive() const;

        void setGamepadSelectionId(int selectionId);
        int getGamepadSelectionId() const;

        bool blockGamepadInput = false;

        virtual void setCharacterSize(float size);
        virtual void setTextVerticalOffset(float offset);

        std::string getIdentifier() const;

        virtual void setAppearance(ComponentAppearanceConfig appearance);

        friend class Menu;
    protected:
        virtual void update() = 0;
        virtual void render(sf::RenderTexture& surface, const sf::RenderStates& states = sf::RenderStates::Default);
        virtual void drawShapes(sf::RenderTexture& surface, const sf::RenderStates& states = sf::RenderStates::Default);
        virtual void draw(sf::RenderTexture& surface) = 0;

        virtual void controllerButtonReleased(GAMEPAD_BUTTON button);
        virtual void controllerButtonPressed(GAMEPAD_BUTTON button);

        virtual void keyPressed(sf::Keyboard::Key& key);
        virtual void keyReleased(sf::Keyboard::Key& key);
        virtual void mouseButtonPressed(const int mx, const int my, const int button);
        virtual void mouseButtonReleased(const int mx, const int my, const int button);
        virtual void mouseMoved(const int mx, const int my) = 0;
        virtual void mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll);
        virtual void textEntered(const sf::Uint32 character);

        virtual sf::FloatRect getBounds() const;

        sf::Vector2f _pos;
        sf::Vector2f _size;

        sf::RectangleShape _shape;

        sf::Text _text;
        float _textYOffset = 0.f;
        sf::Font _font;

        void alignText();
        bool _disableAutomaticTextAlignment = false;

        bool _isActive = false;

        bool _isSelected = false;
        int _selectionId = 0;
        bool _disableMouseMovementDeselection = false;

        ComponentAppearanceConfig _appearance;

        sf::RectangleShape _leftEdge;
        sf::RectangleShape _leftTopCorner;
        sf::RectangleShape _leftBottomCorner;
        sf::RectangleShape _center;
        sf::RectangleShape _centerTop;
        sf::RectangleShape _centerBottom;
        sf::RectangleShape _rightEdge;
        sf::RectangleShape _rightTopCorner;
        sf::RectangleShape _rightBottomCorner;
    private:
        const std::string _id;
    };
}

#endif