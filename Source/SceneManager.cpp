/****************************************************************************
 *  File name: SceneManager.cpp
 *  Description:
 *      - 
  
*****************************************************************************/
#include "OEngine.h"
#include "Scene.h"
#include "SDL.h"
#include <deque>

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

std::deque<Scene> sceneQueue(1);

int position;

bool isRestarting = 0;

void SceneManagerSetFirstScene(Scene& scene)
{
  position = 0;
  sceneQueue[0] = scene;
}

void SceneManagerSetNextScene(Scene& scene, bool forced)
{
  sceneQueue.insert(sceneQueue.begin() + position + 1, scene);
  if (forced)
  {
    sceneQueue[position].Abort();
    sceneQueue.pop_front();
  }
 
}

void SceneManagerAddScene(Scene& scene)
{
  sceneQueue.push_back(scene);
}

void SceneManagerPopScene()
{
  sceneQueue.pop_back();
}

void SceneManagerPopSceneFront()
{
  sceneQueue.pop_front();
}

void SceneManagerRemoveScene(Scene& scene)
{
  for (int i = 0; i < sceneQueue.size(); i++)
  {
    if (&scene == &(sceneQueue[i]))
    {
      sceneQueue.erase(sceneQueue.begin() + i);
      break;
    }
  }
}

void SceneManagerRemoveScene(int givenPosition)
{
  sceneQueue.erase(sceneQueue.begin() + givenPosition);
}

void SceneManagerInsertScene(Scene& scene, int givenPosition)
{
  sceneQueue.insert(sceneQueue.begin() + givenPosition, scene);
}

void SceneManagerPlayCurrentScene()
{
  Scene& currScene = sceneQueue[position];
  switch (currScene.CurrentState())
  {
  case Scene::SceneStates::smInvalid:
    currScene.Load();
    break;
  case Scene::SceneStates::smLoad:
    currScene.Init();
    break;
  case Scene::SceneStates::smInit:
    currScene.Update();
    break;
  case Scene::SceneStates::smUpdate:
    currScene.Update();
    
    break;
  case Scene::SceneStates::smShutdown:
    if (currScene.IsLooping())
    {
      currScene.Init();
    }
    else
    {
      currScene.Unload();
    }
    
    
    break;
  }
}

void SceneManagerAdvanceScene()
{
  position++;
}
