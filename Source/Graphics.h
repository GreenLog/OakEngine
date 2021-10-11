/****************************************************************************
 *  File name: Graphics.h
 *  Description:
 *      - Interface for the main graphical features of the engine.
 *        Most drawing functions are contained in here.
  
*****************************************************************************/
#pragma once

#include "Sprite.h"
#include "Shapes.h"

typedef int Colour;

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

namespace Draw
{
  void WipeScreen(Colour rgb);
  void FillScreen(Colour rgb, int alpha);
}


void GraphicsRenderCurrentFrame();
