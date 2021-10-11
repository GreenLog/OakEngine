/****************************************************************************
 *  File name: OEngine.h
 *  Description:
 *      - Contains some main engine declarations
  
*****************************************************************************/
#pragma once
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "Shapes.h"
#include "Graphics.h"
#include "GameWindow.h"
#include "Scene.h"

#define MonitorWidth OEngine::GetMonitorWidth()
#define MonitorHeight OEngine::GetMonitorHeight()
#define foreach(variableName, container) for (auto& ##variableName : ##container )

#ifdef NDEBUG
#define assert(condition, message) 0
#else
#define assert(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), "\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort(), 0) : 1
#endif

typedef struct SDL_Window Window;
typedef struct SDL_Window* WindowPtr;

typedef struct SDL_Surface ScreenSurface;
typedef struct SDL_Surface ScreenSurfacePtr;

typedef struct SDL_Renderer Renderer;
typedef struct SDL_Renderer* RendererPtr;

typedef struct SDL_FRect Rect;

typedef int Colour;


extern SDL_Renderer* renderer;

extern SDL_Window* window;

extern WindowPtr window2;

extern SDL_Surface* screenSurface;


/* Constants                      */

/* Enums                          */

/* Public classes                 */



namespace OEngine
{
  void  SetExitFlag(bool);
  float GetMonitorWidth();
  float GetMonitorHeight();
  int GetCpuCount();
  const char* GetPlatform();
  int GetSystemRam();
}

/* Public functions declarations  */

