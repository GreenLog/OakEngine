/****************************************************************************
 *  File name: AcornScriptVariables.h
 *  Description:
 *      - Variables for the AcornScript language
*****************************************************************************/
#pragma once
#include <string>
/* Constants                      */

/* Enums                          */

enum class AcrVariableType
{
  Invalid = -1,
  Integer,
  FloatingPoint,
  Boolean
};

/* Public classes                 */

class AcrVariable
{
public:
  AcrVariable(AcrVariableType type, float value);
  float GetValue() const;
  AcrVariableType GetType() const;
  float operator+(float rhs) const;
  AcrVariable& operator+=(float rhs);
  operator float();
  AcrVariable& operator=(float rhs);
  operator std::string();
private:
  float value_;
  AcrVariableType type_;
};

/* Public functions declarations  */

