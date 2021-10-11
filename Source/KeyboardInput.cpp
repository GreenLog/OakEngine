/****************************************************************************
 *  File name: PlayerInput.cpp
 *  Description:
 *      - Handles any sort of playerside keyboard input. 
 *        TODO: Implement gamepad support
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "KeyboardInput.h"
#include "EventHandler.h"
#include <vector>


/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */
 
VKey LastKeyHeld = VKey::VKey_UNKNOWN;


/* Private functions declarations */

void KeyRememberLast(VKey);

/* Public functions definitions   */

bool KeyPressed(VKey key)
{
  
  for(eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_KEYDOWN && (*eventVectorIterator).key.keysym.sym == (SDL_Keycode)key)
    {
      KeyRememberLast(key);
      eventVector.erase(eventVectorIterator);
      return true;
    }
  }
  KeyRememberLast(VKey::VKey_UNKNOWN);
  return false;
}

//TODO:
//Refactor this hacky mess
bool KeyIsDown(VKey key)
{
  
  const Uint8* keyState = SDL_GetKeyboardState(NULL);
  if (key == VKey::VKey_SPACE)
  {
    if (keyState[44])
      {
        return true;
      }
    return false;
  }

  if (key >= VKey::VKey_a && key <= VKey::VKey_z)
  {
    if (keyState[(int)key - 93])
    {
      return true;
    }
    return false;
  }

  SDL_Scancode keyScancode = (SDL_Scancode)((int)key - 1073741824);

  if (keyState[keyScancode])
  {
    return true;
  }
  return false;
}

bool KeyIsUp(VKey key)
{

  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_KEYUP && (*eventVectorIterator).key.keysym.sym == (SDL_Keycode)key)
    {
      KeyRememberLast(VKey::VKey_UNKNOWN);
      return true;
    }
  }
  KeyRememberLast(key);
  return false;
}

void KeyRememberLast(VKey key)
{
  LastKeyHeld = key;
}
