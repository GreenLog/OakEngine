/****************************************************************************
 *  File name: Scene.h
 *  Description:
 *      - 
  
*****************************************************************************/
#pragma once
/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

class Scene
{
public:

  enum class SceneStates
  {
    smInvalid = -1,
    smLoad,
    smInit,
    smUpdate,
    smShutdown,
    smUnload
  };
  /*!************************************************************************************
  * Scene(void (*loadFunction)(), void (*initFunction)(), void (*updateFunction)(), 
    void (*shutdownFunction)(), void (*unloadFunction)(), bool loopingFlag)
  * The default constructor for the Scene Class.
  * Ideally, you would pass all of the function pointers inside of it.
  * However, there may be situations where a scene does not need an init or a shutdown. 
  ***************************************************************************************/
  Scene(void (*loadFunction)(Scene&) = nullptr, void (*initFunction)(Scene&) = nullptr,
    void (*updateFunction)(Scene&) = nullptr, void (*shutdownFunction)(Scene&) = nullptr,
    void (*unloadFunction)(Scene&) = nullptr, bool loopingFlag = false);
  /*!************************************************************************************
  * ~Scene()
  * Default destructor.
  ***************************************************************************************/
	~Scene();
  /*!************************************************************************************
  * void Load()
  * Initializes the important scene memory.
  * Only called if the Scene is not looping
  ***************************************************************************************/
  void Load();
  /*!************************************************************************************
  * void Init()
  * Initializes the important scene variables.
  ***************************************************************************************/
  void Init();
  /*!************************************************************************************
  * void Update()
  * The main loop of the scene
  ***************************************************************************************/
  void Update();
  /*!************************************************************************************
  * void Shutdown()
  * Resets the important scene variables
  ***************************************************************************************/
  void Shutdown();
  /*!************************************************************************************
  * void Unload()
  * Frees the important scene memory.
  * Only called if the Scene is not looping
  ***************************************************************************************/
  void Unload();
  /*!************************************************************************************
  * void Loop(bool flag)
  * Makes the scene repeat indefinetely, or, otherwise stop repeating
  ***************************************************************************************/
  void Loop(bool flag = true);
  /*!************************************************************************************
  * void Abort()
  * Forces the scene to go to Shutdown immediately
  ***************************************************************************************/
  void Abort();
  /*!************************************************************************************
  * bool IsLooping() const
  * Returns true if the scene is currently looping
  ***************************************************************************************/
  bool IsLooping() const;
  /*!************************************************************************************
  * ceneStates CurrentState() const
  * Returns the current state of the boat
  ***************************************************************************************/
  SceneStates CurrentState() const;
private:
  bool isLooping_;
  bool abortFlag_;
  SceneStates currState_;

  void (*loadFunction_)(Scene&);
  void (*initFunction_)(Scene&);
  void (*updateFunction_)(Scene&);
  void (*shutdownFunction_)(Scene&);
  void (*unloadFunction_)(Scene&);

};

