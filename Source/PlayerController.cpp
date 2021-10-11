/****************************************************************************
 *  File name: PlayerController.cpp
 *  Description:
 *      - Implementation of the PlayerController component class
  
*****************************************************************************/
#include "OEngine.h"
#include "TimeHandler.h"
#include "PlayerController.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector2D.h"
#include "UI.h"
#include "AcornScript.h"
#include "Animation.h"
#include <iostream>
#include "Grabbing.h"
/* Constants                      */

/* Enums                          */
enum class Axis
{
  None = -1,
  xAxis,
  yAxis
};
/* Private classes                */

/* Public variables               */

/* Private variables              */

Axis lastAxis = Axis::None;

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

PlayerController::PlayerController(ControllerType type, float speed)
  : Component(ComponentType::PlayerController)
  , controllerType_(type)
  , speed_(speed)
{

}

void PlayerController::Update()
{
  if (AcornScript::IsAnyCurrentlyPlaying())
  {
    return;
  }
  float xAxis = 0;
  float yAxis = 0;


  xAxis = (KeyIsDown(VKey::VKey_d) - KeyIsDown(VKey::VKey_a)) * speed_ * dt;
  yAxis = (KeyIsDown(VKey::VKey_s) - KeyIsDown(VKey::VKey_w)) * speed_ * dt;

  AnimationManager* temp = GetParent()->GetComponent(AnimationManager);

  if (temp)
  {
    
    if ((temp->GetSheet() != 4) && (temp->GetSheet() != 5))
    {
      bool moved = false;
      bool grabbed = false;

      if (KeyIsDown(VKey::VKey_g))
      {
        
        Grabbing* grab = GetParent()->GetComponent(Grabbing);
        grab->Interact();

        if (temp->GetSheet() == 1)
        {
          temp->SwitchSheet(5,1);
          moved = true;
          temp->RunToggle(true);
          if (grab->Grab())
            holding = true;
          
        }
        else if (temp->GetSheet() == 0)
        {
          temp->SwitchSheet(4, 0);
          moved = true;
          temp->RunToggle(true);
          if (grab->Grab())
            holding = true;
        }
        grabbed = true;

      }

      if (KeyIsDown(VKey::VKey_d) && !grabbed)
      {
        temp->SwitchSheet(1);
        moved = true;

        temp->RunToggle(true);

      }
      if (KeyIsDown(VKey::VKey_a) && !grabbed)
      {
        temp->SwitchSheet(0);
        moved = true;

        temp->RunToggle(true);

      }
      if (KeyIsDown(VKey::VKey_w) && !grabbed)
      {
        temp->SwitchSheet(1);
        moved = true;

        temp->RunToggle(true);

      }
      if (KeyIsDown(VKey::VKey_s) && !grabbed)
      {
        temp->SwitchSheet(0);
        moved = true;

        temp->RunToggle(true);

      }

      if (!moved && !grabbed)
      {
        if (temp->GetSheet() == 1)
        {
          temp->SwitchSheet(3);
          temp->RunToggle(true);
        }
        else if (temp->GetSheet() == 0)
        {
          temp->SwitchSheet(2);
          temp->RunToggle(true);
        }
      }
    }
  }




  if (!xAxis && !yAxis)
  {
    lastAxis = Axis::None;
    return;
  }

  switch (controllerType_)
  {  

  case ControllerType::Invalid:
    return;
    break;

  case ControllerType::FourDirectional:
    if (xAxis && yAxis)
    {
      switch (lastAxis)
      {
      case Axis::None:
        yAxis = 0;
        lastAxis = Axis::xAxis;
        break;
      case Axis::xAxis:
        xAxis = 0;
        break;
      case Axis::yAxis:
        yAxis = 0;
        break;
      default:
        break;
      }
      break;
    }
    else if (xAxis)
    {
      lastAxis = Axis::xAxis;
      break;
    }
    else if (yAxis)
    {
      lastAxis = Axis::yAxis;
      break;
    }
    break;
  case ControllerType::EightDirectional:
    if (xAxis && yAxis)
    {
      xAxis /= 1.4142136f;
      yAxis /= 1.4142136f;
    }
    break;
  default:
    break;
  }

 TransformPtr transform = GetParent()->GetComponent(Transform);
 Vector2D vec = transform->GetTranslation();
 vec.x += xAxis;
 vec.y += yAxis;
 transform->SetTranslation(vec);



}
