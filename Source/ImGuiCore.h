/****************************************************************************
 *  File name: ImGuiCore.h
 *  Description:
 *      - Contains the interface for the core ImGui systems
  
*****************************************************************************/
#pragma once

SDL_Renderer;

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

namespace ImGui
{
  void Init(SDL_Renderer* renderer, int width, int height);

  void Update();
  

  void Shutdown();
}

