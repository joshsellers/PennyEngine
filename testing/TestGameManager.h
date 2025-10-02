#ifndef _TEST_GAME_MANAGER_H
#define _TEST_GAME_MANAGER_H

#include "../PennyEngine/core/GameManager.h"

#include "../PennyEngine/input/KeyListener.h"
#include "../PennyEngine/input/MouseListener.h"
#include "../PennyEngine/ui/components/ButtonListener.h"
#include "TestClass.h"

class TestGameManager : public pe::GameManager, public pe::KeyListener, public pe::MouseListener, public pe::ButtonListener {
public:
    TestGameManager();

    virtual void init();

    virtual void update();
    virtual void draw(sf::RenderTexture& surface);
    virtual void drawUI(sf::RenderTexture& surface);
protected:
    virtual void buttonPressed(std::string buttonId);

    virtual void keyPressed(sf::Keyboard::Key& key);
    virtual void keyReleased(sf::Keyboard::Key& key);

    virtual void mouseButtonPressed(const int mx, const int my, const int button);
    virtual void mouseButtonReleased(const int mx, const int my, const int button);
    virtual void mouseMoved(const int mx, const int my);
    virtual void mouseWheelScrolled(sf::Event::MouseWheelScrollEvent mouseWheelScroll);

    virtual void onShutdown();
private:
    std::string _test = "MANAGERTEST";
    TestClass _testObject;

    std::vector<std::shared_ptr<TestClass>> _testObjects;
};

#endif