/****************************************************************************
 *  File name: AcornActions.h
 *  Description:
 *      - Actions for the Acorn Script. 
 *        Different operations for the Acorn Script language.
  
*****************************************************************************/
#pragma once
#include <string>


typedef class AcornScript AcornScript;
typedef class AcrVariable AcrVariable;
/* Constants                      */

/* Enums                          */

/* Public classes                 */

class AcornLabel
{
public:
  AcornLabel(const char* name, int position);
  std::string GetLabelName() const;
  int GetPosition() const;
private:
  int positionAfter_;
  std::string labelName_;
};

class AcornAction
{
public:
  AcornAction();
  AcornScript* GetParent() const;
  void SetParent(AcornScript* script);
  void Perform();
  bool IsInProgress() const;
  void Start();
  void Finish();
  bool IsFirstTime() const;
  void FirstTime(bool firsTime);
private:
  virtual void Invoke() = 0;
  AcornScript* parent_;
  bool isInProgress_;
  bool isFirstTime_;
};

class AcrActionPrint : public AcornAction
{
public:
  AcrActionPrint(std::string text, std::string name);
private:
  void Invoke();
  std::string text_;
  std::string name_;
};

class AcrActionGoto : public AcornAction
{
public:
  AcrActionGoto(std::string label);
private:
  void Invoke();
  std::string labelName_;
};

class AcrActionCalculate : public AcornAction
{
public:
  enum class Operators
  {
    Invalid = -1,
    Equals,
    Plus,
    PlusEquals,
  };
  AcrActionCalculate(Operators type, AcrVariable* variable, float amount);
private:
  void Invoke();
  AcrVariable& variable_;
  Operators type_;
  float amount_;
};

class AcrActionDummy : public AcornAction
{
public:
  AcrActionDummy();
private:
  void Invoke();
};

/* Public functions declarations  */


