#ifndef _BUTTON_H
#define _BUTTON_H

#include "MenuComponent.h"
#include "ButtonListener.h"

namespace pe {
    class Button : public pe::MenuComponent {
    public:
        Button(std::string buttonId, float x, float y, float width, float height, std::string labelText, sf::Font font, ButtonListener* listner, bool centerOnCoords = true);

        void setLabelText(std::string labelText);

        bool pressWhenSelected = false;

        virtual void show();

    protected:
        bool _mouseDown = false;

        void update();
        //virtual void render(sf::RenderTexture& surface, const sf::RenderStates& states = sf::RenderStates::Default);
        void draw(sf::RenderTexture& surface);

        sf::Vector2i getMousePos() const;

        virtual void mouseButtonPressed(const int mx, const int my, const int button);
        virtual void mouseButtonReleased(const int mx, const int my, const int button);
        virtual void mouseMoved(const int mx, const int my);

        virtual void controllerButtonReleased(GAMEPAD_BUTTON button);
        virtual void controllerButtonPressed(GAMEPAD_BUTTON button);
    private:
        sf::Vector2i _mousePos;

        ButtonListener* _listener = nullptr;
        
        bool _wasJustSelected = false;
    };
}

#endif