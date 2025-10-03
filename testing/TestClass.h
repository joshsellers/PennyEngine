// Copyright (c) 2025 Josh Sellers
// Licensed under the MIT License. See LICENSE

#pragma once

#include "../PennyEngine/input/KeyListener.h"
#include "../PennyEngine/input/MouseListener.h"
#include "../PennyEngine/PennyEngine.h"
#include <iostream>

class TestClass : public pe::KeyListener, public pe::MouseListener {
public:
    TestClass(std::string str, int n) {
        PennyEngine::addInputListener(this);
        _test = str;
        _n = n;
    }
protected:
    virtual void keyPressed(sf::Keyboard::Key& key) {};
    virtual void keyReleased(sf::Keyboard::Key& key) { std::cout << _test + " " + std::to_string(_n) << std::endl; };

    virtual void mouseButtonPressed(const int mx, const int my, const int button) {};
    virtual void mouseButtonReleased(const int mx, const int my, const int button) {};
    virtual void mouseMoved(const int mx, const int my) {};
    virtual void mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll) {};
private:
    std::string _test;

    int _n;
};