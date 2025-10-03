#ifndef _SLIDER_H
#define _SLIDER_H

#include "MenuComponent.h"
#include "ButtonListener.h"
#include "SliderHandle.h"
#include "../../core/Defines.h"

namespace pe {
    class Slider : public MenuComponent {
    public:
        Slider(std::string id, float x, float y, sf::Vector2f railSize, sf::Vector2f handleSize, std::string label, ButtonListener* listener, bool autoCenter = true);

        void setValue(float value);
        float getValue() const;

        virtual void move(sf::Vector2f delta);

        void setLabelText(std::string labelText);

        virtual bool hasMousePriority() const;
    protected:
        void update();
        void draw(sf::RenderTexture& surface);

        sf::Vector2i getMousePos() const;

        virtual void mouseButtonPressed(const int mx, const int my, const int button);
        virtual void mouseButtonReleased(const int mx, const int my, const int button);
        virtual void mouseMoved(const int mx, const int my);
    private:
        float _lastValue = 0;
        float _value = 0;

        bool _mouseDown = false;
        bool _mouseSelected = false;

        sf::Vector2i _mousePos;

        ButtonListener* _listener = nullptr;

        s_p<SliderHandle> _handle = nullptr;
    };
}

#endif