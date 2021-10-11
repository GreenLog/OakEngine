/****************************************************************************
 *  File name: Scene.cpp
 *  Description:
 *      - 
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "Graphics.h"
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/*!************************************************************************************
* Scene(void (*loadFunction)(), void (*initFunction)(), void (*updateFunction)(),
* void (*shutdownFunction)(), void (*unloadFunction)())
* The default constructor for the Scene Class.
* Ideally, you would pass all of the function pointers inside of it.
* However, there may be situations where a scene does not need an init or a shutdown.
***************************************************************************************/
Scene::Scene(void (*loadFunction)(Scene&), void (*initFunction)(Scene&),
  void (*updateFunction)(Scene&), void (*shutdownFunction)(Scene&),
  void (*unloadFunction)(Scene&), bool loopingFlag)
  :loadFunction_ (loadFunction)
  ,initFunction_(initFunction)
  ,updateFunction_(updateFunction)
  ,shutdownFunction_(shutdownFunction)
  ,unloadFunction_(unloadFunction)
  ,isLooping_(loopingFlag)
  ,abortFlag_(false)
  ,currState_(SceneStates::smInvalid)
{
  
}
/*!************************************************************************************
* ~Scene()
* Default destructor.
***************************************************************************************/
Scene::~Scene()
{

}
/*!************************************************************************************
* void Load()
* Initializes the important scene memory.
* Only called if the Scene is not looping
***************************************************************************************/
void Scene::Load()
{
  currState_ = SceneStates::smLoad;
  loadFunction_(*this);
}
/*!************************************************************************************
* void Init()
* Initializes the important scene variables.
***************************************************************************************/
void Scene::Init()
{
  currState_ = SceneStates::smInit;
  initFunction_(*this);
}
/*!************************************************************************************
* void Update()
* The main loop of the scene
***************************************************************************************/
void Scene::Update()
{
  currState_ = SceneStates::smUpdate;
  updateFunction_(*this);
  
}
/*!************************************************************************************
* void Shutdown()
* Resets the important scene variables
***************************************************************************************/
void Scene::Shutdown()
{
  currState_ = SceneStates::smShutdown;
  shutdownFunction_(*this);
}
/*!************************************************************************************
* void Unload()
* Frees the important scene memory.
* Only called if the Scene is not looping
***************************************************************************************/
void Scene::Unload()
{
  currState_ = SceneStates::smUnload;
  unloadFunction_(*this);
}
/*!************************************************************************************
* void Loop(bool flag)
* Makes the scene repeat indefinetely, or, otherwise stop repeating
***************************************************************************************/
void Scene::Loop(bool flag)
{
  isLooping_ = flag;
}
/*!************************************************************************************
* void Abort()
* Forces the scene to go to Shutdown immediately
***************************************************************************************/
void Scene::Abort()
{
  Shutdown();
}
/*!************************************************************************************
* bool IsLooping() const
* Returns true if the scene is currently looping
***************************************************************************************/
bool Scene::IsLooping() const
{
  return isLooping_;
}
/*!************************************************************************************
* ceneStates CurrentState() const
* Returns the current state of the boat
***************************************************************************************/
Scene::SceneStates Scene::CurrentState() const
{
  return currState_;
}
