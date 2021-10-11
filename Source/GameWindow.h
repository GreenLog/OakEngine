/****************************************************************************
 *  File name: GameWindow.h
 *  Description:
 *      - Interface for the functions that interact with the game window
  
*****************************************************************************/
#pragma once

#define WindowWidth GetCanvasWidth()
#define WindowHeight GetCanvasHeight()

enum class CursorStates
{
  Invalid = -1,
  Idle,
  Interesting
};

typedef class Vector2D Vector2D;

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

void WindowCreate();

void WindowInit();


void ShowWindowsCursor(bool toggle);

void WindowFullscreen(bool toggle);

void WindowFullscreenBorderless(bool toggle);

void WindowResizeble(bool toggle);

void WindowLockMouseToWindow(bool toggle);

float GetCanvasWidth();

float GetCanvasHeight();

void CursorSetState(CursorStates state);

void DisplayCustomCursor();

