/****************************************************************************
 *  File name: OEngine.cpp
 *  Description:
 *      - The main cpp file. Contains defginitions for some core engine functions.
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "OEGameLoop.h"

#include <iostream>


/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

bool exiting = false;
/* Private functions declarations */

/* Public functions definitions   */


extern SDL_Renderer* renderer = nullptr;

extern SDL_Window* window = nullptr;

extern WindowPtr window2 = nullptr;

extern SDL_Surface* screenSurface = nullptr;

SDL_DisplayMode* mode = nullptr;

int main(int argc, char* args[])
{
 
  GameLoopInit();
  
  GameLoopUpdate(exiting);

  GameLoopShutdown();

  return 0;
}

namespace OEngine
{
  void SetExitFlag(bool flag)
  {
    exiting = flag;
  }

  float GetMonitorWidth()
  {
    SDL_GetCurrentDisplayMode(0, mode);
    return mode->w;
  }

  float GetMonitorHeight()
  {
    SDL_GetCurrentDisplayMode(0, mode);
    return mode->h;

  }

  int GetCpuCount()
  {
    return SDL_GetCPUCount();
  }

  const char* GetPlatform()
  {
    return SDL_GetPlatform();
  }

  int GetSystemRam()
  {
    return SDL_GetSystemRAM();
  }

}


