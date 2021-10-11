/****************************************************************************
 *  File name: BoolDummy.h
 *  Description:
 *      - Contains the declarations for the BoolDummy class, a bool implementation that supports
 *        encapsulation.

*****************************************************************************/
#pragma once
#include "Component.h"
/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

class BoolDummy : public Component
{
public:
  BoolDummy();
  ~BoolDummy();
  void SetValue(bool value);
  bool GetValue();
private:
  bool value_;
};