/****************************************************************************
 *  File name: AcornScript.h
 *  Description:
 *      - The interface for the AcornScript class
  
*****************************************************************************/
#pragma once

#include "AcornActions.h"

#include <map>
#include <vector>
#include <string>

typedef class AcornAction AcornAction;
typedef class AcornLabel AcornLabel;
class AcrActionPrint;
class AcrCharacter;
class AcrVariable;

/* Constants                      */

/* Enums                          */

enum class AcornScriptStates
{
  Invalid = -1,
  Free,
  ParsingName,
  ParsingVariable,
  ParsingAction,
};

/* Public classes                 */
class AcornScript
{
public:
  AcornScript(const char* path);
  AcornScriptStates GetCurrentState() const;
  void SetCurrentState(AcornScriptStates state);
  void Trigger();
  void Trigger(const char* startingLabel);
  void Finish();
  void IncrementMarker();
  void JumpToLabel(const char* name);
  void AddAction(int position, AcornAction* action);
  void Play();
  AcrCharacter* GetCharacter(std::string& name);
  static bool IsAnyCurrentlyPlaying();
  bool IsFinished() const;
  AcrVariable& GetVariable(std::string& name);
private:
  static bool anyCurrentlyPlaying_;
  AcornScriptStates currState_;
  int lineMarker_;
  bool isFinished_;
  std::map <int, AcornAction*> actions_;
  std::map<std::string, AcornLabel*> labels_;
  std::map<std::string, AcrCharacter*> characters_;
  std::map<std::string, AcrVariable*> variables_;
};

/* Public functions declarations  */

