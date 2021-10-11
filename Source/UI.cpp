/****************************************************************************
 *  File name: UI.cpp
 *  Description:
 *      - Implementation for the different UI-related functions, 
 *        mainly ImGui wrappers
  
*****************************************************************************/
#include "OEngine.h"
#include "UI.h"

#include "SpriteText.h"
#include "Vector2D.h"

#include <iostream>
#include <string>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

SpriteText* dialog_text;
SpriteText* tooltip_text;
SpriteText* name_text;

SpritePtr dialog_box;

SpritePtr portrait = nullptr;

bool isTriggered = 0;

const char* current_text = "I am error!";

const char* current_name = "OOPS!";

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

namespace UI
{
  void Init()
  {
    dialog_box = new Sprite("./Assets/UI/dialogue2.png", WindowWidth, WindowHeight);
    name_text = new SpriteText("./Assets/fonts/ExportedFont.bmp", 64, 64, 1024, 256, WindowWidth / 30, WindowWidth / 30, "I am error!");
    dialog_text = new SpriteText("./Assets/fonts/ExportedFont.bmp", 64, 64, 1024, 256, WindowWidth / 30, WindowWidth/30, "I am error!");
  }

  namespace Dialogue
  {
    void Display()
    {
      if (isTriggered)
      {
        //Draw::FillScreen(0x0, 50);
        
        dialog_box->Draw(0,0);
        name_text->Display(525, WindowHeight - 385 + WindowWidth / 40 + 40, false, false, 1);
        dialog_text->Display(200, WindowHeight - 300 + WindowWidth / 40 + 40, true, false, 0);
        portrait->Draw(WindowWidth - portrait->GetSize().x - 30, WindowHeight - WindowHeight/3 - 20);
      }
      
    }

    void Trigger()
    {
      isTriggered = true;
    }

    void ForceStop()
    {
      isTriggered = false;
    }

    void SetText(const char* text)
    {

      current_text = text;
      dialog_text->SetText(text);

    }
    bool IsTriggered()
    {
      return isTriggered;
    }

    void SetName(const char* name)
    {
      name_text->SetText(name);
    }
    void SetSprite(SpritePtr sprite)
    {
      portrait = sprite;
    }
  }
}