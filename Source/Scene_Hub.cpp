/****************************************************************************
 *  File name: 
 *  Description:
 *      - 
  
*****************************************************************************/
#include "OEngine.h"
#include "Scene_Hub.h"
#include "Tiles.h"
#include "SpriteSheet.h"
#include "Animation.h"

#include "NPC.h"

#include "AcornScript.h"

#include "AudioEngine.h"

#include "GameObject.h"

#include "Grabbing.h"

#include "Transform.h"

#include "Collisions.h"
#include "PlayerController.h"

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */



void Scene_Hub_Load(Scene& scene)
{
  scene;

}

void Scene_Hub_Init(Scene& scene)
{
  scene;
  CursorSetState(CursorStates::Idle);
}

void Scene_Hub_Update(Scene& scene)
{
  Draw::WipeScreen(0x0);

  scene;
}

void Scene_Hub_Shutdown(Scene& scene)
{
  scene;
}

void Scene_Hub_Unload(Scene& scene)
{
  scene;
}
