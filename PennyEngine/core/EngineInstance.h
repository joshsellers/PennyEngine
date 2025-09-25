#ifndef _ENGINE_INSTANCE_H
#define _ENGINE_INSTANCE_H

#include "GameManager.h"
#include "Resolution.h"

namespace pe {
    namespace intern {

        class EngineInstance {
        public:
            void start(GameManager* gameManager);
            GameManager* gameManager;

            sf::RenderWindow window;
            int framerateLimit = 0;
            Resolution renderRes;
            Resolution displayRes;
            bool autoScaleRenderRes = true;
            bool useDisplayResForUI = false;

            bool fullscreen = false;
            std::string windowTitle = "";

            sf::View camera;

            bool isStarted() const;
        private:
            void createWindow();

            bool _started = false;
        };
    }
}

#endif