/****************************************************************************
 *  File name:
 *  Description:
 *      - 
  
*****************************************************************************/
#pragma once

#include "SpriteSheet.h"

#include <string>
/* Constants                      */

/* Enums                          */

/* Public classes                 */

class AcrCharacter
{
public:
  AcrCharacter(const char* name, const char* sprite, std::string sound = "");
  ~AcrCharacter();
  std::string& GetName();
  SpritePtr GetSprite();
  std::string& GetSoundName();
private:
  std::string name_;
  SpritePtr sprite_;
  std::string sound_;
};

/* Public functions declarations  */

