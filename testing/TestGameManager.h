#ifndef _TEST_GAME_MANAGER_H
#define _TEST_GAME_MANAGER_H

#include "../PennyEngine/core/GameManager.h"

class TestGameManager : public pe::GameManager {
public:
    virtual void update();
    virtual void draw(sf::RenderTexture& surface);
    virtual void drawUI(sf::RenderTexture& surface);
protected:

private:

};

#endif