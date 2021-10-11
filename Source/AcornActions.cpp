/****************************************************************************
 *  File name: AcornActions.cpp
 *  Description:
 *      - Actions for the Acorn Script.
 *        Different operations for the Acorn Script language.

*****************************************************************************/
#include "OEngine.h"
#include "AcornActions.h"

#include "AcornScript.h"
#include "AcornCharacters.h"
#include "AcornScriptVariables.h"
#include "UI.h"
#include "AcornScriptUtils.h"
#include "AudioEngine.h"
#include <iostream>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

AcornAction::AcornAction()
  :parent_(nullptr)
  ,isInProgress_(false)
  ,isFirstTime_(true)
{
}

AcornScript* AcornAction::GetParent() const
{
  return parent_;
}

void AcornAction::SetParent(AcornScript* script)
{
  parent_ = script;
}


void AcornAction::Perform()
{
  Invoke();
  if (!IsInProgress())
  {
    Start();
    return;
  }
  
  if (MouseLeftIsClicked())
  {
    Finish();
    parent_->IncrementMarker();
  }
}

AcornLabel::AcornLabel(const char* name, int position)
  :labelName_(name)
  ,positionAfter_(position)
{

}

std::string AcornLabel::GetLabelName() const
{
  return labelName_;
}

int AcornLabel::GetPosition() const
{
  return positionAfter_;
}

bool AcornAction::IsInProgress() const
{
  return isInProgress_;
}

void AcornAction::Start()
{
  isInProgress_ = true;
}

void AcornAction::Finish()
{
  isInProgress_ = false;
  isFirstTime_ = true;
}

bool AcornAction::IsFirstTime() const
{
  return isFirstTime_;
}

void AcornAction::FirstTime(bool firsTime)
{
  isFirstTime_ = firsTime;
}



/*  ACTION PRINT  */
AcrActionPrint::AcrActionPrint(std::string text, std::string name)
  :text_(text)
  ,name_(name)
{
}

void AcrActionPrint::Invoke()
{
  if (IsFirstTime())
  {
    AcrCharacter* character = GetParent()->GetCharacter(name_);
    int i = 0;
    std::string temp = text_;

    Audio::PlaySound(character->GetSoundName());
    
    while ((i = temp.find('%', i)) != -1)
    {
      std::string name = Utils::AcornScript::ParseInsideBrackets(temp, '%', '%', i);
      std::string var = GetParent()->GetVariable(name);
      if (GetParent()->GetVariable(name).GetType() == AcrVariableType::FloatingPoint)
      {
      var.pop_back();
      var.pop_back();
      var.pop_back();
      var.pop_back();

      }
      temp.replace(i ,name.size() + 2, var);
      i += name.size();
    }
    UI::Dialogue::SetText(temp.c_str());
    UI::Dialogue::SetName(character->GetName().c_str());
    UI::Dialogue::SetSprite(character->GetSprite());
    UI::Dialogue::Trigger();
    FirstTime(false);
  }
}


/*  ACTION GOTO  */
AcrActionGoto::AcrActionGoto(std::string label)
  :labelName_(label)
{
}

void AcrActionGoto::Invoke()
{
  GetParent()->JumpToLabel(labelName_.c_str());
  Finish();
}




/*  ACTION DUMMY  */
AcrActionDummy::AcrActionDummy()
{
}

void AcrActionDummy::Invoke()
{
  Finish();
  GetParent()->IncrementMarker();
}

AcrActionCalculate::AcrActionCalculate(Operators type, AcrVariable* variable, float amount)
   :type_(type)
  ,variable_(*variable)
  ,amount_(amount)
{

}

void AcrActionCalculate::Invoke()
{
  switch (type_)
  {
  case AcrActionCalculate::Operators::Invalid:
    break;
  case AcrActionCalculate::Operators::Equals:
    variable_ = amount_;
    break;
  case AcrActionCalculate::Operators::Plus:
    break;
  case AcrActionCalculate::Operators::PlusEquals:
    variable_ += amount_;
    break;
  default:
    break;
  }
  Finish();
  GetParent()->IncrementMarker();
}
