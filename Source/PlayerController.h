/****************************************************************************
 *  File name: PlayerController.h
 *  Description:
 *      - Interface for the PlayerController component class
  
*****************************************************************************/
#pragma once
#include "Component.h"

/* Constants                      */

/* Enums                          */

enum class ControllerType
{
  Invalid = -1,
  FourDirectional,
  EightDirectional,
};

/* Public classes                 */

class PlayerController : public Component
{
public:
  PlayerController(ControllerType type, float speed);
  void Update();
private:
  ControllerType controllerType_;
  float speed_;
  bool holding;
};
typedef class PlayerController* PlayerControllerPtr;

/* Public functions declarations  */

