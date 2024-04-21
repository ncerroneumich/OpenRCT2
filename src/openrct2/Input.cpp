/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Input.h"

#include "Context.h"
#include "Game.h"

InputState _inputState;
uint8_t _inputFlags;
uint8_t gInputPlaceObjectModifier;

WidgetRef gHoverWidget;
WidgetRef gPressedWidget;

uint32_t _tooltipNotShownTimeout;

Tool gCurrentToolId;
WidgetRef gCurrentToolWidget;

/**
 *
 *  rct2: 0x006E3B43
 */
void TitleHandleKeyboardInput()
{
    ContextInputHandleKeyboard(true);
}

/**
 *
 *  rct2: 0x006E3B43
 */
void GameHandleKeyboardInput()
{
    ContextInputHandleKeyboard(false);
}

void InputSetFlag(INPUT_FLAGS flag, bool on)
{
    if (on)
    {
        _inputFlags |= flag;
    }
    else
    {
        _inputFlags &= ~flag;
    }
}

bool InputTestFlag(INPUT_FLAGS flag)
{
    return _inputFlags & flag;
}

void InputResetFlags()
{
    _inputFlags = 0;
}

void InputSetState(InputState state)
{
    _inputState = state;
}

InputState InputGetState()
{
    return _inputState;
}

void ResetTooltipNotShown()
{
    _tooltipNotShownTimeout = (gCurrentRealTimeTicks + RealTimeTicks(50)).Value;
}

void InputResetPlaceObjModifier()
{
    gInputPlaceObjectModifier = PLACE_OBJECT_MODIFIER_NONE;
}
