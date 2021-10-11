/****************************************************************************
 *  File name EventHandler.h
 *  Description:
 *      - Handles engine events.
  
*****************************************************************************/
#pragma once
#include <vector>
typedef union SDL_Event Event;

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public variables               */

extern std::vector<Event> eventVector;
extern std::vector<Event>::iterator eventVectorIterator;

/* Public functions declarations  */


void EventHandlerGetEvents();

void EventHandlerFreeEvents();

