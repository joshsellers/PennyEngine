#ifndef _SLIDER_HANDLE_H
#define _SLIDER_HANDLE_H

#include "MenuComponent.h"

namespace pe {
    class SliderHandle : public MenuComponent {
    public:
        SliderHandle(std::string id, float x, float y, float width, float height);

        friend class Slider;
    protected:
        void update();
        void draw(sf::RenderTexture& surface);
    private:
    };
}

#endif