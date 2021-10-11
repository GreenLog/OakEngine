/*************************************************************************
  * File name : SpriteText.h
  * Description :
  * Interface for the SpriteText component that inherits from the spriteSheet class.
  * Deals specifically with the in - game text implementation.
  * TODO : implement appropriate spacing.

  * ****************************************************************************/
#pragma once
#include "SpriteSheet.h"
#include <string>
#include <vector>
/* Constants                      */

/* Enums                          */

/* Public classes                 */

struct Character
{
  Character(char character);
  operator int();
  char character_;
  bool displayed_;
};

class SpriteText : public SpriteSheet
{
public:
  SpriteText(const char* filepath, float cellWidth, float cellHeight, float sheetWidth, float sheetHeight, float charWidth, float charHeight);
  SpriteText(const char* filepath, float cellWidth, float cellHeight, float sheetWidth, float sheetHeight, float charWidth, float charHeight, std::string text);
  void Display(float x, float y, bool incrementally, bool isCentered = 0, int shakiness = 0);
  void SetSpaceBetween(int space);
  int GetSpaceBetween();
  bool IsFinished();
  void Skip();
  void SetText(const char* text);

  void operator=(const char* text);
  bool operator==(const char* text) const;
  bool operator!=(const char* text) const;
private:
  std::vector<Character> text_;
  int currentlyDisplayed_;
  int spaceBetween_;
  float timer_;
  bool finished_;
};



/* Public functions declarations  */

