#ifndef _APPEARANCE_CONFIIGS_H
#define _APPEARANCE_CONFIIGS_H

#include "ComponentAppearanceConfig.h"

namespace pe {
    inline ComponentAppearanceConfig BASE_COMPONENT_CONFIG = {
        0.2f,
        {32, 80, 2, 2},
        {32, 83, 2, 1},
        {32, 85, 2, 2},
        {35, 80, 1, 2},
        {35, 83, 1, 1},
        {35, 85, 1, 2},
        {37, 80, 2, 2},
        {37, 83, 2, 1},
        {37, 85, 2, 2}
    };

    inline ComponentAppearanceConfig BUTTON_HOVER_CONFIG = {
        6.f,
        {112, 321, 3, 2},
        {112, 339, 3, 9},
        {112, 332, 3, 3},
        {96, 321, 1, 2},
        {96, 339, 1, 9},
        {96, 332, 1, 3},
        {128, 321, 2, 2},
        {128, 339, 3, 9},
        {128, 332, 3, 3}
    };

    inline ComponentAppearanceConfig BUTTON_CLICKED_CONFIG = {
        6.f,
        {112, 321, 3, 2},
        {112, 339, 3, 9},
        {112, 332, 3, 3},
        {96, 321, 1, 2},
        {96, 339, 1, 9},
        {96, 332, 1, 3},
        {128, 321, 2, 2},
        {128, 339, 3, 9},
        {128, 332, 3, 3}
    };

    inline ComponentAppearanceConfig PANEL_CONFIG = {
        0.2f,
        {48, 96, 3, 3},
        {48, 100, 3, 1},
        {48, 102, 3, 3},
        {52, 96, 1, 3},
        {52, 100, 1, 1},
        {52, 102, 1, 3},
        {54, 96, 3, 3},
        {54, 100, 3, 1},
        {54, 102, 3, 3}
    };
}

#endif