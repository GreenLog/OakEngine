/****************************************************************************
 *  File name: UI.h
 *  Description:
 *      - Interface for the different UI-related functions,
 *        mainly ImGui wrappers
  
*****************************************************************************/
#pragma once

class Sprite;
typedef class Sprite* SpritePtr;

/* Constants                      */

/* Enums                          */



/* Public classes                 */

/* Public functions declarations  */


namespace UI
{
  void Init();
  namespace Dialogue
  {
    void Trigger();
    void ForceStop();
    void Display();
    void SetText(const char* text);
    bool IsTriggered();
    void SetName(const char* name);
    void SetSprite(SpritePtr sprite);
  }
}
