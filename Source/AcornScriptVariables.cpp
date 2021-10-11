/****************************************************************************
 *  File name: AcornScriptVariables.cpp
 *  Description:
 *      - Variables for the AcornScript language
*****************************************************************************/
#include "OEngine.h"
#include "AcornScriptVariables.h"
#include <string>
#include <iostream>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

AcrVariable::AcrVariable(AcrVariableType type, float value)
  :type_(type)
  ,value_(value)
{
}

float AcrVariable ::GetValue() const
{
  return value_;
}

AcrVariableType AcrVariable ::GetType() const
{
  return type_;
}



float AcrVariable ::operator+(float rhs) const
{
  return this->GetValue() + rhs;
}

AcrVariable& AcrVariable::operator+=(float rhs)
{
  this->value_ = this->value_ + rhs;
  return *this;
}

AcrVariable ::operator float()
{
  return this->GetValue();
}

AcrVariable& AcrVariable::operator=(float rhs)
{
  this->value_ = rhs;
  return *this;
}

AcrVariable::operator std::string()
{
  switch (type_)
  {
  case AcrVariableType::Invalid:
    return "I AM ERROR";
    break;
  case AcrVariableType::Integer:
    return std::to_string((int)value_);
    break;
  case AcrVariableType::FloatingPoint:
    return std::to_string(value_);
    break;
  case AcrVariableType::Boolean:
    if (value_)
    {
      return "TRUE";
    }
    return "FALSE";
    break;
  default:
    break;
  }
}


