/****************************************************************************
 *  File name: Graphics.cpp
 *  Description:
 *      - Implemenation for the basic functions containing graphical features
 *        of the language.
 *        Most drawing functions are contained in here.
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

void Draw::WipeScreen(Colour rgb)
{
  int width;
  int height;
  SDL_GetWindowSize(window, &width, &height);
  Shape::Rectangle(0, 0, (float)width, (float)height, rgb, 255, false, true);
}

void Draw::FillScreen(Colour rgb, int alpha)
{
  Shape::Rectangle(0, 0, WindowWidth, WindowHeight, rgb, alpha, false, true);
}


void GraphicsRenderCurrentFrame()
{
  SDL_RenderPresent(renderer);
}
