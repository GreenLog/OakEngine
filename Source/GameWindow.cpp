/****************************************************************************
 *  File name: GameWindow.cpp
 *  Description: 
 *      - Implementation for the functions that interact with the game window
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "GameWindow.h"
#include "Vector2D.h"
#include "SpriteSheet.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

SDL_DisplayMode current;

CursorStates currCursorState = CursorStates::Invalid;

SpriteSheet* cursor;

/* Public functions definitions   */

void WindowCreate();

void WindowInit()
{
  cursor = new SpriteSheet("./Assets/UI/mouse.png", 16, 16, 32, 16, 32, 32);
  cursor->SetFrame(0);
}

void ShowWindowsCursor(bool toggle)
{
  SDL_ShowCursor(toggle);
}



void WindowFullscreen(bool toggle)
{
 
  
  if (toggle)
  {
    SDL_SetWindowPosition(window, 0, 0);
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
  }
  else
  {
    SDL_GetCurrentDisplayMode(0, &current);
    SDL_SetWindowFullscreen(window, 0);
    SDL_SetWindowResizable(window, SDL_TRUE);
    SDL_SetWindowSize(window, 1280, 720);
    SDL_SetWindowBordered(window, SDL_TRUE);
    SDL_SetWindowPosition(window, current.w / 2 - 1280 / 2, current.h / 2 - 720 / 2);
  }
  screenSurface = SDL_GetWindowSurface(window);
}

void WindowLockMouseToWindow(bool toggle)
{
  SDL_SetRelativeMouseMode((SDL_bool)toggle);
}

float GetCanvasWidth()
{
  int w;
  SDL_GetWindowSize(window, &w, nullptr);
  return (float)w;
}

float GetCanvasHeight()
{
  int h;
  SDL_GetWindowSize(window, nullptr, &h);
  return (float)h;
}

void CursorSetState(CursorStates state)
{
  currCursorState = state;
}

void DisplayCustomCursor()
{
  cursor->SetFrame((int)currCursorState);
  cursor->Draw(MouseX, MouseY, false);
}

void WindowFullscreenBorderless(bool toggle);

void WindowResizeble(bool toggle);
