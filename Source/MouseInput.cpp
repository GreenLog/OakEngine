/****************************************************************************
 *  File name: MouseInput.cpp
 *  Description:
 *      - Handles playerside mouse input

*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "EventHandler.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */
namespace MouseInput
{
  int x = 0;
  int y = 0;
}

typedef struct Mouse
{
  bool leftMouse;
  bool rightMouse;
  bool middleMouse;
}Mouse;

Mouse mouse = { 0,0,0 };
/* Private functions declarations */

/* Public functions definitions   */
using namespace MouseInput;

void MouseUpdate()
{
  if (MouseLeftIsClicked())
  {
    mouse.leftMouse = true;
  }
  if (MouseLeftIsUp())
  {
    mouse.leftMouse = false;
  }

  if (MouseRightIsClicked())
  {
    mouse.rightMouse = true;
  }
  if (MouseRightIsUp())
  {
    mouse.rightMouse = false;
  }

  if (MouseMiddleIsClikced())
  {
    mouse.middleMouse = true;
  }
  if (MouseMiddleIsUp())
  {
    mouse.middleMouse = false;
  }
}

float MouseGetX()
{
  SDL_GetMouseState(&x, nullptr);
  return static_cast<float>(x);
}

float MouseGetY()
{
  SDL_GetMouseState(nullptr, &y);
  return static_cast<float>(y);
}

bool MouseLeftIsClicked()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEBUTTONDOWN && (*eventVectorIterator).button.button == SDL_BUTTON_LEFT)
    {
      return true;
    }
  }
  return false;
}

bool MouseRightIsClicked()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEBUTTONDOWN && (*eventVectorIterator).button.button == SDL_BUTTON_RIGHT)
    {
      return true;
    }
  }
  return false;
}

bool MouseMiddleIsClikced()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEBUTTONDOWN && (*eventVectorIterator).button.button == SDL_BUTTON_MIDDLE)
    {
      return true;
    }
  }
  return false;
}

bool MouseLeftIsUp()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEBUTTONUP && (*eventVectorIterator).button.button == SDL_BUTTON_LEFT)
    {
      return true;
    }
  }
  return false;
}

bool MouseRightIsUp()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEBUTTONUP && (*eventVectorIterator).button.button == SDL_BUTTON_RIGHT)
    {
      return true;
    }
  }
  return false;
}

bool MouseMiddleIsUp()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEBUTTONUP && (*eventVectorIterator).button.button == SDL_BUTTON_MIDDLE)
    {
      return true;
    }
  }
  return false;
}

bool MouseLeftIsDown()
{
  return mouse.leftMouse;
}

bool MouseRightIsDown()
{
  return mouse.rightMouse;
}

bool MouseMiddleIsDown()
{
  return mouse.middleMouse;
}

float MouseGetHorizontalMotion()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEMOTION)
    {
      return (*eventVectorIterator).motion.xrel;
    }
  }
  return 0.0f;
}

float MouseGetVerticalMotion()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_MOUSEMOTION)
    {
      return (*eventVectorIterator).motion.yrel;
    }
  }
  return 0.0f;
}
