#ifndef _APPEARANCE_CONFIIGS_H
#define _APPEARANCE_CONFIIGS_H

#include "ComponentAppearanceConfig.h"

namespace pe {
    inline ComponentAppearanceConfig BASE_COMPONENT_CONFIG = {
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
}

#endif