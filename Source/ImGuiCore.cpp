/****************************************************************************
 *  File name: ImGuiCore.cpp
 *  Description:
 *      - Contains implementation for the core ImGui systems
  
*****************************************************************************/
#include "OEngine.h"
#include "ImGuiCore.h"
#include "imgui_sdl.h"
namespace ImGui
{
  /* Constants                      */

  /* Enums                          */

  /* Private classes                */

  /* Public variables               */

  /* Private variables              */

  /* Private functions declarations */

  /* Public functions definitions   */

  //Initializes the ImGui Systems
  void Init(SDL_Renderer* renderer, int width, int height)
  {
    ImGuiSDL::Initialize(renderer, width, height);
  }

  /* Private functions definitions  */

}