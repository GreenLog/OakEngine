/****************************************************************************
 *  File name: Component.cpp
 *  Description:
 *      - Contains the implementation for the Component class for the component-based
 *        architecture of this engine.

*****************************************************************************/
#include "OEngine.h"
#include "Component.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

Component::Component(ComponentType type)
  :type_(type)
  ,parent_(nullptr)
{
}

ComponentType Component::GetType()
{
  return type_;
}

void Component::SetParent(GameObjectPtr parent)
{
  parent_ = parent;
}

GameObjectPtr Component::GetParent()
{
  return parent_;
}
