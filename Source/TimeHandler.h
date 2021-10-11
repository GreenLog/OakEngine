/****************************************************************************
 *  File name: TimeHandler.h
 *  Description:
 *      - Interface for functions dealing with time handling, most notably
 *        dt calculations
  
*****************************************************************************/

#define dt TimeHandler::GetDeltaTime()

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

namespace TimeHandler
{
  /*************************************************
  * float GetDeltaTime()
  * returns how much time has passed between the
  * previous frame an the current one (in millisecs)
  *************************************************/
  float GetDeltaTime();

  /*************************************************
  * float GetTimeSinceStart()
  * returns how much time has passed since the start
  * of the game (in millisecs)
  *************************************************/
  float GetTimeSinceStart();

  /*************************************************
  * float TimerHandlerUpdate()
  * updates the dt and timeSinceStart values
  * only called in GameLoopUpdate()
  *************************************************/
  void Update();

  /*************************************************
  * void Initialize()
  * Calculates the amount of ticks at the start of the frame
  * only called in GameLoopUpdate()
  *************************************************/
  void Initialize();

}
