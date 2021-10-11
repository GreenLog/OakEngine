/****************************************************************************
 *  File name EventHandler.cpp
 *  Description:
 *      - Handles engine events.

*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "EventHandler.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

std::vector<Event> eventVector;
std::vector<Event>::iterator eventVectorIterator;

static SDL_Event eventTemp;

static std::vector<Event> a;

/* Public functions definitions   */

void EventHandlerGetEvents()
{
  if (eventVector.size())
  {
    //if (false) {}
  }
  while (SDL_PollEvent(&eventTemp))
  {
    eventVector.push_back(eventTemp);
  }
  eventVectorIterator = eventVector.begin();
}

void EventHandlerFreeEvents()
{
  eventVector.erase(eventVector.begin(), eventVector.end());
}
