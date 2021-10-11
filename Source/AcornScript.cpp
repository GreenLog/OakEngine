/****************************************************************************
 *  File name: AcornScript.cpp
 *  Description:
 *      - The implementation of the AcornScript class
  
*****************************************************************************/
#include "OEngine.h"
#include "AcornScript.h"
#include "AcornActions.h"
#include "AcornCharacters.h"
#include "AcornScriptUtils.h"
#include "AcornScriptVariables.h"
#include "AudioEngine.h"

#include "UI.h"

#include <fstream>
#include <sstream>
#include <iostream>

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

bool AcornScript::anyCurrentlyPlaying_ = false;

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */



bool AcornScript::IsAnyCurrentlyPlaying()
{
  return anyCurrentlyPlaying_;
}

AcornScript::AcornScript(const char* path)
  :isFinished_(true)
  ,lineMarker_(0)
  ,currState_(AcornScriptStates::Free)
{
  std::ifstream file(path);
  std::string line;
  int position = 0;
  while (std::getline(file, line))
  {
    std::stringstream lineString(line);
    std::string token;

    lineString >> token;

    if (line == "" || line[0] == '#')
    {
      continue;
    }

    else if (line[0] == '<')
    {
      AcrActionDummy* dummy = new AcrActionDummy();
      std::string temp = Utils::AcornScript::ParseInsideBrackets(line, '<', '>');
      AcornLabel* label = new AcornLabel(temp.c_str(), position + 1);
      AddAction(position, dummy);
      labels_.insert(std::pair<std::string, AcornLabel*>(temp, label));
    }

    else if (token == "define")
    {
      lineString >> token;
      if (token == "character")
      {
        lineString >> token;

        assert(token[0] == ':', "INVALID SYNTAX! VARIABLE NAMES MUST BEGIN WITH \":\"");
        
        std::string short_name = Utils::AcornScript::ParseInsideBrackets(line, ':', ' ');
        lineString >> token;
        assert(token[0] == '=', "INVALID SYNTAX; COULD NOT FIND OPERATOR \"=\"");
        lineString >> token;
        std::string full_name;
        while (token.back() != ',' && token.back() != '\"')
        {
          lineString >> token;
        }
        if (token.back() == ',')
        {
          token.pop_back();
          token.erase(token.begin());
          token.pop_back();
          token = ',';
        }
        else
        {
          token.erase(token.begin());
          token.pop_back();
          lineString >> token;
        }
        full_name = Utils::AcornScript::ParseInsideBrackets(line, '\"', '\"');
        assert(token[0] == ',', "INVALID SYNTAX; COULD NOT FIND OPERATOR \",\"");

        lineString >> token;
        std::string path;
        if (token.back() == ',')
        {
          token.pop_back();
          assert(token.front() == '\"' && token.back() == '\"', "INVALID SYNTAX; PATH_NAME DEFINED INCORRECTLY");
          path = Utils::AcornScript::ParseInsideBrackets(token, '\"', '\"');
          token.erase(token.begin());
          token.pop_back();

          token = ',';
        }
        else
        {
          assert(token.front() == '\"' && token.back() == '\"', "INVALID SYNTAX; PATH_NAME DEFINED INCORRECTLY");
          path = Utils::AcornScript::ParseInsideBrackets(token, '\"', '\"');
          token.erase(token.begin());
          token.pop_back();
          lineString >> token;
        }

        lineString >> token;
        if (!token.empty())
        {

        }
        assert(token.front() == '\"' && token.back() == '\"', "INVALID SYNTAX; PATH_NAME DEFINED INCORRECTLY");
        token.erase(token.begin());
        token.pop_back();
        std::string bark_path = token;
        Audio::LoadSound(bark_path, false, false, false);
        AcrCharacter* character = new AcrCharacter(full_name.c_str(), path.c_str(), bark_path.c_str());
        characters_.insert(std::pair<std::string, AcrCharacter*>(short_name, character));
      }

      else if (token == "integer")
      {
        lineString >> token;
        assert(token[0] == ':', "INVALID SYNTAX! VARIABLE NAMES MUST BEGIN WITH \":\"");
        token.erase(token.begin());
        std::string short_name = token;
        lineString >> token;
        assert(token[0] == '=', "INVALID SYNTAX; COULD NOT FIND OPERATOR \"=\"");
        lineString >> token;
        float value = std::stoi(token);
        AcrVariable* var = new AcrVariable(AcrVariableType::Integer, value);
        variables_.insert(std::pair<std::string, AcrVariable*>(short_name, var));
      }

      else if (token == "real")
      {
        lineString >> token;
        assert(token[0] == ':', "INVALID SYNTAX! VARIABLE NAMES MUST BEGIN WITH \":\"");
        token.erase(token.begin());
        std::string short_name = token;
        lineString >> token;
        assert(token[0] == '=', "INVALID SYNTAX; COULD NOT FIND OPERATOR \"=\"");
        lineString >> token;
        float value = std::stof(token);
        AcrVariable* var = new AcrVariable(AcrVariableType::FloatingPoint, value);
        variables_.insert(std::pair<std::string, AcrVariable*>(short_name, var));
      }

      else if (token == "boolean")
      {
        lineString >> token;
        assert(token[0] == ':', "INVALID SYNTAX! VARIABLE NAMES MUST BEGIN WITH \":\"");
        token.erase(token.begin());
        std::string short_name = token;
        lineString >> token;
        assert(token[0] == '=', "INVALID SYNTAX; COULD NOT FIND OPERATOR \"=\"");
        lineString >> token;
        float value = std::stoi(token);
        AcrVariable* var = new AcrVariable(AcrVariableType::Boolean, value);
        variables_.insert(std::pair<std::string, AcrVariable*>(short_name, var));
      }
      
      
      AcrActionDummy* dummy = new AcrActionDummy();
      AddAction(position, dummy);

    }

    else if (token == "say")
    {

      AcrActionPrint* print = new AcrActionPrint(Utils::AcornScript::ParseInsideBrackets(line, '\"', '\"'), Utils::AcornScript::ParseInsideBrackets(line, ':', ' '));
      AddAction(position, print);
    }
    
    else if (token == "goto")
    {

      AcrActionGoto* go_to = new AcrActionGoto(Utils::AcornScript::ParseInsideBrackets(line, '<', '>'));
      AddAction(position, go_to);
    }

    else if (token == "calculate")
    {
      AcrActionCalculate::Operators type = AcrActionCalculate::Operators::Invalid;
      std::string name = Utils::AcornScript::ParseInsideBrackets(line, ':', ' ');
      assert(variables_.find(name) != variables_.end(), "ERROR; CANNOT FIND THE SPECIFIED FIRST VARIABLE");
      AcrVariable* variable = variables_[name];
      lineString >> token >> token;
      float value = 0;
      if (token == "+=")
      {
        type = AcrActionCalculate::Operators::PlusEquals;
      }
      else if (token == "=")
      {
        AcrActionCalculate::Operators::Equals;
      }

      lineString >> token;

      if (token[0] == ':')
      {
        name = Utils::AcornScript::ParseInsideBrackets(line, ':', ' ', line.find(':') + 1);
        assert(variables_.find(name) != variables_.end(), "ERROR; CANNOT FIND THE SPECIFIED SECOND VARIABLE");
        AcrVariable* temp = variables_[name];
        value = *temp;
      }
      else
      {
        value = std::stof(token);
      }
      AcrActionCalculate* action = new AcrActionCalculate(type, variable, value);
      AddAction(position, action);
    }

    position++;
  }
 

}

AcornScriptStates AcornScript::GetCurrentState() const
{
  return currState_;
}

void AcornScript::SetCurrentState(AcornScriptStates state)
{
  currState_ = state;
}

bool AcornScript::IsFinished() const
{
  return isFinished_;
}

AcrVariable& AcornScript::GetVariable(std::string& name)
{

  return *variables_.find(name)->second;
}

void AcornScript::Trigger()
{
  isFinished_ = false;
  anyCurrentlyPlaying_ = true;
}

void AcornScript::Trigger(const char* startingLabel)
{
  JumpToLabel(startingLabel);
  Trigger();
}

void AcornScript::Finish()
{
  isFinished_ = true;
  anyCurrentlyPlaying_ = false;
}

void AcornScript::IncrementMarker()
{
  lineMarker_++;
}

void AcornScript::JumpToLabel(const char* name)
{
  lineMarker_ = labels_.find(name)->second->GetPosition();
}

void AcornScript::AddAction(int position, AcornAction* action)
{
  action->SetParent(this);
  actions_.insert(std::pair<int, AcornAction*>(position,action));
}

void AcornScript::Play()
{
  if (IsFinished())
  {
    return;
  }
  std::cout << "Playing action " << lineMarker_ << "\n";
  if (actions_.find(lineMarker_) != actions_.end())
  {
    actions_.find(lineMarker_)->second->Perform();
  }
  else
  {
    std::cout << "Terminating Script\n";
    Finish();
    UI::Dialogue::ForceStop();
  }
  
}


AcrCharacter* AcornScript::GetCharacter(std::string& name)
{
  return characters_.find(name)->second;
}


