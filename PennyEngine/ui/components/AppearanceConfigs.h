#ifndef _APPEARANCE_CONFIIGS_H
#define _APPEARANCE_CONFIIGS_H

#include "ComponentAppearanceConfig.h"

namespace pe {
    inline ComponentAppearanceConfig BASE_COMPONENT_CONFIG = {
        0.2f,
        {112, 256, 4, 6},
        {112, 276, 4, 10},
        {112, 267, 4, 5},
        {96, 256, 1, 6},
        {96, 276, 1, 10},
        {96, 267, 1, 5},
        {128, 256, 4, 6},
        {128, 276, 4, 10},
        {128, 267, 4, 5}
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