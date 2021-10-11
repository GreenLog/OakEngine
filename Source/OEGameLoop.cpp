/****************************************************************************
 *  File name: OEGameLoop.cpp
 *  Description:
 *      - Contains the main gameloop functions: Init, Update and Shutdown.
  
*****************************************************************************/
#include "OEngine.h"
#include "OEGameLoop.h"
#include "TimeHandler.h"
#include "FrameRateController.h"
#include "AudioEngine.h"
#include "SceneManager.h"
#include "Scene.h"



#include "Scene_Hub.h"

#include "Graphics.h"
#include "SpriteSheet.h"

#include "EventHandler.h"
#include "SDL.h"
#include "UI.h"

#include "WindowEvents.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "glad/glad.h"
#include "SDL.h"

#include "GameWindow.h"

#include <iostream>
#include <vector>

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

bool isFullScreen = false;


/* Private functions declarations */

/* Public functions definitions   */

/*!*******************************************
* void GameLoopInit()
* Initializes the important game variables
*
*********************************************/
void GameLoopInit()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_GL_SetAttribute(
      SDL_GL_CONTEXT_PROFILE_MASK,
      SDL_GL_CONTEXT_PROFILE_CORE
  );

  std::string glsl_version = "";
  glsl_version = "#version 130";
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);               

  window = SDL_CreateWindow("OakEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);

  SDL_GLContext gl_context = SDL_GL_CreateContext(window);
  SDL_GL_MakeCurrent(window, gl_context);

  SDL_GL_SetSwapInterval(1);

  screenSurface = SDL_GetWindowSurface(window);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  assert(gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress));
  printf("AQ\n");
//  glViewport(0, 0, 1280, 720);


  Scene Hub(Scene_Hub_Load, Scene_Hub_Init, Scene_Hub_Update, Scene_Hub_Shutdown, Scene_Hub_Unload);

  //Scene Banana(Scene_Banana_Load, Scene_Banana_Init, Scene_Banana_Update, Scene_Banana_Shutdown, Scene_Banana_Unload);

  SceneManagerSetFirstScene(Hub);

  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  
  WindowInit();

  ShowWindowsCursor(false);

  UI::Init();

  Audio::Initialize();
  
}

/*!*******************************************
* void GameLoopUpdate()
* Fires every frame, everything happens here
*
*********************************************/
void GameLoopUpdate(bool &exiting)
{

  while (!exiting)
  {

    //FrameControllerForceFrameRate();
    TimeHandler::Initialize();
    EventHandlerGetEvents();
    MouseUpdate();
    Audio::Update();
    // Start the Dear ImGui frame
    

    

    if (KeyPressed(VKey::VKey_ESCAPE) || WindowEventWindowClosed())
    {
      OEngine::SetExitFlag(true);
    }
    

    if (KeyPressed(VKey::VKey_F1))
    {
      std::cout << "Enter the framerate:\n";
      float frames;
      std::cin >> frames;
      FrameControllerSetFramesPerSecond(frames);
      std::cout << "\nThe framerate has been set to " << FrameControllerGetFramesPerSecond() << ".\n";
    }

    if (KeyIsDown(VKey::VKey_LALT) && KeyPressed(VKey::VKey_RETURN))
    {
      if (!isFullScreen)
      {
        WindowFullscreen(true);
        isFullScreen = true;
      }
      else
      {
        WindowFullscreen(false);
        isFullScreen = false;
      }
    }

    
    SceneManagerPlayCurrentScene();
    UI::Dialogue::Display();
    DisplayCustomCursor();

    GraphicsRenderCurrentFrame();
    EventHandlerFreeEvents();
    
    FrameControllerForceFrameRate();
    TimeHandler::Update();
  }
}

/*!**********************************************
* void GameLoopShutdown()
* Is called when the game is closed, frees memory
*
*************************************************/
void GameLoopShutdown()
{
  Audio::Shutdown();
  SDL_DestroyWindow(window);
  SDL_Quit();
}


