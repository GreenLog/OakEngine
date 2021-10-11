/****************************************************************************
 *  File name: Transform.h
 *  Description:
 *      - Implementation for a transform component
  
*****************************************************************************/

#pragma once
#include "Component.h"
#include "Vector2D.h"
/* Constants                      */

/* Enums                          */

/* Public classes                 */

class Transform : public Component
{
public:
  Transform();
  Transform(Vector2D& translation);
  Transform(float x, float y);
  Vector2D& GetTranslation();
  Vector2D& GetOldTranslation();
  void SetTranslation(Vector2D& newTranslation);
  void RevertTranslation();
private:
  Vector2D translation_;
  Vector2D oldTranslation_;
};
typedef class Transform* TransformPtr;
/* Public functions declarations  */

