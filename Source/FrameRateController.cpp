/****************************************************************************
 *  File name:  FrameRateController.cpp
 *  Description:
 *      - Definitions for FrameRateController Functions.

*****************************************************************************/
#include "OEngine.h"
#include "FrameRateController.h"
#include "TimeHandler.h"
#include "SDL.h"

#include <iostream>


/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

static bool FirstTime = true;

static float framesPerSecond = 60;

float startOfFrame = 0;

/* Private functions declarations */

/* Public functions definitions   */


/*************************************************
* FrameControllerSetFramesPerSecond(float fps)
* Changes the framerate to the given float value
*************************************************/
void FrameControllerSetFramesPerSecond(float fps)
{
  framesPerSecond = fps;
}

/*************************************************
* FrameControllerGetFramesPerSecond(float fps)
* Returns the current framerate
*************************************************/
float FrameControllerGetFramesPerSecond()
{
  return framesPerSecond;
}

/*************************************************
* void FrameControllerForceFrameRate()
* Limits the game's framerate to the current value
* Called within the game loop
*************************************************/
void FrameControllerForceFrameRate()
{
  Uint32 target = (((1.0f / framesPerSecond)) * 1000);
  Uint32 delayAmount = target - dt * 1000;
  if (dt * 1000 > target)
  {
    return;
  }
  SDL_Delay(delayAmount);

}


