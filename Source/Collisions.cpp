/****************************************************************************
 *  File name:  Collisions.cpp
 *  Description:
 *      - Implementation for the Collider component.

*****************************************************************************/
#include "OEngine.h"
#include "GameObject.h"
#include "Collisions.h"
#include "Component.h"
#include "Transform.h"
#include "Sprite.h"
#include <vector>
#include "UI.h"
#include "BoolDummy.h"
#include "PlayerController.h"

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */
std::vector<Collider*> Collider::colliders_;

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

Collider::Collider() : Component(ComponentType::Collider)
{
  colliders_.push_back(this);
}

Collider::~Collider()
{
}

void Collider::Update()
{
  unsigned size = colliders_.size();

  for (unsigned i = 0; i < size; i++)
  {
    Collider* other = colliders_[i];
    if (other != this)
    {
      if (GetParent()->GetComponent(PlayerController))
      {
        if (IsColliding(*other))
        {
          Transform* tempoary = GetParent()->GetComponent(Transform);
          Vector2D oldTrans = tempoary->GetOldTranslation();
          tempoary->SetTranslation(oldTrans);
        }
      }

    }
  }

}

bool Collider::IsColliding(Component& other)
{
  Transform* thisTrans = GetParent()->GetComponent(Transform);
  Transform* otherTrans = other.GetParent()->GetComponent(Transform);

  if (thisTrans && otherTrans)
  {
    Vector2D posOne = thisTrans->GetTranslation();
    Vector2D posTwo = otherTrans->GetTranslation();

    Sprite* thisSpr = GetParent()->GetComponent(Sprite);
    Sprite* otherSpr = other.GetParent()->GetComponent(Sprite);
    
    if (thisSpr && otherSpr)
    {
      Vector2D oneSize = thisSpr->GetSize();
      Vector2D twoSize = otherSpr->GetSize();


      /*if (rect1.x < rect2.x + rect2.width &&
        rect1.x + rect1.width > rect2.x &&
        rect1.y < rect2.y + rect2.height &&
        rect1.y + rect1.height > rect2.y) {
        // collision detected!
      }

      // filling in the values =>

      if (5 < 30 &&
        55 > 20 &&
        5 < 20 &&
        55 > 10) {
        // collision detected!
      }*/

      if (posOne.x < posTwo.x + twoSize.x &&
        posOne.x + oneSize.x > posTwo.x &&
        posOne.y < posTwo.y + twoSize.y &&
        posOne.y + oneSize.y > posTwo.y)
      {
        return true;
      }
      else
        return false;
    }
  }

  return false;
}


