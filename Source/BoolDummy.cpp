/****************************************************************************
 *  File name: BoolDummy.cpp
 *  Description:
 *      - Contains the definitions for the BoolDummy class, a bool implementation that supports
 *        encapsulation.
  
*****************************************************************************/
#include "OEngine.h"
#include "BoolDummy.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

BoolDummy::BoolDummy() : Component(ComponentType::BoolDummy)
{
}

BoolDummy::~BoolDummy()
{
}

void BoolDummy::SetValue(bool value)
{
  value_ = value;
}

bool BoolDummy::GetValue()
{
  return value_;
}
