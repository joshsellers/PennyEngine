#ifndef _INPUT_LISTENER_H
#define _INPUT_LISTENER_H

namespace pe {
    namespace intern {
        class InputListener {
        public:
            friend class InputEventDistributor;
        protected:
            bool _isKeyListener;
            bool _isMouseListener;
            bool _isGamepadListener;

            virtual void listenToAll() {
                _isKeyListener = true;
                _isMouseListener = true;
                _isGamepadListener = true;
            };
        };
    }
}

#endif