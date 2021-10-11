/****************************************************************************
 *  File name: WindowEvents.cpp
 *  Description:
 *      - Wrappers for the SDL window events
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "EventHandler.h"
#include "WindowEvents.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

bool WindowEventsMouseInScreen()
{
  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_WINDOWEVENT && (*eventVectorIterator).window.event == SDL_WINDOWEVENT_ENTER)
    {
      return true;
    }
  }
  return false;
}

bool WindowEventWindowClosed()
{

  for (eventVectorIterator = eventVector.begin(); eventVectorIterator < eventVector.end(); eventVectorIterator++)
  {
    if ((*eventVectorIterator).type == SDL_WINDOWEVENT && (*eventVectorIterator).window.event == SDL_WINDOWEVENT_CLOSE)
    {
      return true;
    }
  }
  return false;
}

