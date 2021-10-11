/****************************************************************************
 *  File name: SpriteText.cpp
 *  Description:
 *      - Implementation for the SpriteText component that inherits from the spriteSheet class.
 *        Deals specifically with the in-game text implementation. 
 *        TODO: implement appropriate spacing.
  
*****************************************************************************/
#include "OEngine.h"
#include "SpriteText.h"
#include "TimeHandler.h"

#include <cmath>

#define SPEED 15

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

SpriteText::SpriteText(const char* filepath, float cellWidth, float cellHeight, float sheetWidth, float sheetHeight, float charWidth, float charHeight)
  : SpriteSheet(filepath, cellWidth, cellHeight, sheetWidth, sheetHeight, charWidth, charHeight)
  , text_()
  , currentlyDisplayed_(-1)
  , spaceBetween_(cellWidth / 2)
  , timer_(0)
  , finished_(0)
{
  
}

SpriteText::SpriteText(const char* filepath, float cellWidth, float cellHeight, float sheetWidth, float sheetHeight, float charWidth, float charHeight, std::string text)
  : SpriteSheet(filepath, cellWidth, cellHeight, sheetWidth, sheetHeight, charWidth, charHeight)
  , currentlyDisplayed_(-1)
  , spaceBetween_(cellWidth)
  , timer_(0)
  , finished_(0)
{
  foreach(character, text)
  {
    text_.push_back(character);
  }
}

void SpriteText::SetSpaceBetween(int space)
{
  spaceBetween_ = space;
}

int SpriteText::GetSpaceBetween()
{
  return spaceBetween_;
}

bool SpriteText::IsFinished()
{
  return finished_;
}

void SpriteText::Skip()
{
  foreach(character, text_)
  {
    character.displayed_ = true;
  }
  finished_ = true;
}

void SpriteText::SetText(const char* text)
{
  if (!text)
  {
    SetText("");
    return;
  }
  text_.erase(text_.begin(), text_.end());
  int i = 0;
    while (text[i] != '\0')
  {
    text_.push_back(text[i]);
    i++;
  }
  finished_ = 0;
}

void SpriteText::operator=(const char* text)
{
  SetText(text);
}

bool SpriteText::operator!=(const char* text) const
{
  return !this->operator==(text);
}

bool SpriteText::operator==(const char* text) const
{
  int i = 0;
  foreach(character, text_)
  {
    if (character.character_ != text[i])
    {
      return false;
    }
    i++;
  }
  if (text[i] != '\0')
  {
    return false;
  }
  return true;
}


void SpriteText::Display(float x, float y, bool incrementally, bool isCentered, int shakiness)
{
  if (incrementally)
  {
    int yoffset = 0;

    int i = 0;
    int xposition = 0;
    foreach(character, text_)
    {

      if (character.character_ == '1')
      {
        xposition = -1;
        yoffset++;
        continue;
      }
      else
      {
        xposition++;
      }
      ++currentlyDisplayed_;
      if (text_[currentlyDisplayed_].displayed_ == false)
      {
        if (timer_ <= 0)
        {
          timer_ = 0.8;
          text_[currentlyDisplayed_].displayed_ = true;
          if (currentlyDisplayed_ == text_.size() - 1)
          {
            finished_ = true;
          }
        }       
        currentlyDisplayed_ = -1;
        timer_ -= dt * SPEED;
        return;
      }
      SetFrame(character);
      
      Draw(x + spaceBetween_/2 * xposition, y + sinf(rand()) * shakiness+ 32*yoffset, isCentered);
    }
    currentlyDisplayed_ = -1;
    return;
  }

  foreach(character, text_)
  {
    ++currentlyDisplayed_;
    SetFrame(character);
    Draw(x + spaceBetween_/2 * currentlyDisplayed_, y, isCentered);
  }
  currentlyDisplayed_ = -1;
}

Character::Character(char character)
  : character_(character)
  , displayed_(false)
{
}

Character::operator int()
{
  
  if (character_ >= 'a')
    return (character_ - 64);
  return character_ - 32;
}

