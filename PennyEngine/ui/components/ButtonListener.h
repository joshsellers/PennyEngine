// Copyright (c) 2025 Josh Sellers
// Licensed under the MIT License. See LICENSE

#ifndef _BUTTON_LISTENER_H
#define _BUTTON_LISTENER_H

#include <string>

namespace pe {
    class ButtonListener {
    public:
        friend class Button;
        friend class Slider;
    protected:
        virtual void buttonPressed(std::string buttonId) = 0;
    };
}

#endif