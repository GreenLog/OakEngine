/****************************************************************************
 *  File name: TimeHandler.cpp
 *  Description:
 *      - Contains the defintions for functions dealing with TimeHandling.
  
*****************************************************************************/
#include "OEngine.h"
#include "TimeHandler.h"
#include "SDL.h"

#include <chrono>
#include <iostream>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

static float deltaTime = 0;

static float timeAtTheStart = 0;

std::chrono::steady_clock::time_point prevFrame;
std::chrono::steady_clock::time_point currFrame;

static bool firstTime = true;

/* Private functions declarations */

/* Public functions definitions   */

namespace TimeHandler
{
  /*************************************************
  * float GetDeltaTime()
  * returns how much time has passed between the
  * previous frame an the current one (in millisecs)
  *************************************************/
  float GetDeltaTime()
  {
    return deltaTime * 0.001;
  }

  /*************************************************
  * float GetTimeSinceStart()
  * returns how much time has passed since the start
  * of the game (in millisecs)
  *************************************************/
  float GetTimeSinceStart()
  {
    return SDL_GetTicks();
  }

  /*************************************************
  * float Update()
  * updates the dt and timeSinceStart values
  * only called in GameLoopUpdate()
  *************************************************/
  void Update()
  {
    deltaTime = GetTimeSinceStart() - timeAtTheStart;
  }

  void Initialize()
  {
    timeAtTheStart = GetTimeSinceStart();
  }

}
