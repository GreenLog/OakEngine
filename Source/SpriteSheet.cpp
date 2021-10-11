/****************************************************************************
 *  File name: SpriteSheet.cpp
 *  Description:
 *      - Abstract class inhereting from the Sprite class
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "SpriteSheet.h"
#include <iostream>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

SDL_Rect clipRectangle = { 0,0,0,0 };
Rect quad = { 0,0,0,0 };

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

SpriteSheet::SpriteSheet(const char* filepath, float cellWidth, float cellHeight, float sheetWidth, float sheetHeight, float imageWidth, float imageHeight)
  : Sprite(filepath, imageWidth, imageHeight)
  , sheetSize_(sheetWidth, sheetHeight)
  , currFrame_(0)
  , cellSize_(Vector2D(cellWidth, cellHeight))
  , maxFrames_(0)
  , flip_(false)
{
}

SpriteSheet::SpriteSheet(const char* filepath, float cellWidth, float cellHeight, float sheetWidth, float sheetHeight, float imageWidth, float imageHeight, unsigned maxFrames)
  : Sprite(filepath, imageWidth, imageHeight)
  , sheetSize_(sheetWidth, sheetHeight)
  , currFrame_(0)
  , cellSize_(Vector2D(cellWidth, cellHeight))
  , maxFrames_(maxFrames)
  , flip_(false)
{
}

void SpriteSheet::SetFrame(unsigned frame)
{
  currFrame_ = frame;
}

unsigned SpriteSheet::GetCurrentFrame()
{
  return currFrame_;
}

unsigned SpriteSheet::GetMaxFrame()
{
  return maxFrames_;
}

void SpriteSheet::Draw(float xCoor, float yCoor, bool isCentered)
{
  clipRectangle.w = cellSize_.x;
  clipRectangle.h = cellSize_.y;
  if (((currFrame_)* (clipRectangle.w)  ) >= sheetSize_.x)
  {
    //clipRectangle.x = currFrame_ * clipRectangle.w - sheetSize_.x * (int)(currFrame_ * clipRectangle.w / sheetSize_.x);
    clipRectangle.x = clipRectangle.w * (currFrame_ % (int)(sheetSize_.x / cellSize_.x));
    clipRectangle.y = (int)(currFrame_ * clipRectangle.w / sheetSize_.x) * clipRectangle.h;
  }
  else
  {
    clipRectangle.x = currFrame_ * clipRectangle.w;
    clipRectangle.y = 0;
  }
 

  if (isCentered)
  {
    xCoor -= GetSize().x / 2;
    yCoor -= GetSize().y / 2;
  }

  quad.x = xCoor;
  quad.y = yCoor;
  quad.w = GetSize().x;
  quad.h = GetSize().y;

  if (flip_)
  {
    SDL_RenderCopyExF(renderer, GetTexture(), &clipRectangle, &quad, 0, NULL, SDL_FLIP_HORIZONTAL);
  }
  else
    SDL_RenderCopyF(renderer, GetTexture(), &clipRectangle, &quad);
  
  
  

  
}

void SpriteSheet::FlipToggle(bool toggle)
{
  flip_ = toggle;
}
