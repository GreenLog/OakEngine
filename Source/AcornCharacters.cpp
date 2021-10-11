/****************************************************************************
 *  File name: 
 *  Description:
 *      - 
  
*****************************************************************************/
#include "OEngine.h"
#include "AcornCharacters.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

AcrCharacter::AcrCharacter(const char* name, const char* sprite, std::string sound)
  :name_(name)
  ,sound_(sound)
{
  sprite_ = new Sprite(sprite);
}

AcrCharacter::~AcrCharacter()
{
  delete sprite_;
}

std::string& AcrCharacter::GetName()
{
  return name_;
}

SpritePtr AcrCharacter::GetSprite()
{
  return sprite_;
}

std::string& AcrCharacter::GetSoundName()
{
  return this->sound_;
}



