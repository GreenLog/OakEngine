/****************************************************************************
 *  File name: SpriteSheet.h
 *  Description:
 *      - Abstract class inhereting from the Sprite class
  
*****************************************************************************/
#pragma once
#include "Sprite.h"
#include "Vector2D.h"
/* Constants                      */

/* Enums                          */

/* Public classes                 */

class SpriteSheet : public Sprite
{
public:
  SpriteSheet(const char* filepath, float cellWidth, 
    float cellHeight, float sheetWidth, 
    float sheetHeight, float imageWidth, float imageHeight);
  SpriteSheet(const char* filepath, float cellWidth,
    float cellHeight, float sheetWidth,
    float sheetHeight, float imageWidth, float imageHeight,
    unsigned maxFrames);
  void SetFrame(unsigned frame);
  unsigned GetCurrentFrame();
  unsigned GetMaxFrame();
  void Draw(float x, float y, bool isCentered = 0);
  Vector2D GetCellSize();
  void FlipToggle(bool toggle);
private:
  Vector2D sheetSize_;
  Vector2D cellSize_;
  bool flip_;
  unsigned currFrame_;
  unsigned maxFrames_;
};

/* Public functions declarations  */

