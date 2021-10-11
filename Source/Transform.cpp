/****************************************************************************
 *  File name: Transform.cpp   
 *  Description:  
 *      - Implementation for a transform component
  
*****************************************************************************/
#include "OEngine.h"
#include "Transform.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

Transform::Transform()
  :Component(ComponentType::Transform)
  ,translation_(Vector2D(0,0))
  ,oldTranslation_(Vector2D(0,0))
{
}

Transform::Transform(Vector2D& translation)
  :Component(ComponentType::Transform)
  ,translation_(translation)
{
}

Transform::Transform(float x, float y)
  : Component(ComponentType::Transform)
  , translation_(Vector2D(x, y))
  , oldTranslation_(Vector2D(0, 0))
{
}

Vector2D& Transform::GetTranslation()
{
  return translation_;
}

Vector2D& Transform::GetOldTranslation()
{
  return oldTranslation_;
}

void Transform::SetTranslation(Vector2D& newTranslation)
{
  oldTranslation_ = translation_;
  translation_ = newTranslation;
}

void Transform::RevertTranslation()
{
  translation_ = oldTranslation_;
}

