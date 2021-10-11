/****************************************************************************
 *  File name:  FrameRateController.h
 *  Description:
 *      - Declarations for FrameRateController Functions. 
  
*****************************************************************************/


/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

/*************************************************
* FrameControllerSetFramesPerSecond(float fps)
* Changes the framerate to the given float value
*************************************************/
void FrameControllerSetFramesPerSecond(float fps);

/*************************************************
* FrameControllerGetFramesPerSecond(float fps)
* Returns the current framerate
*************************************************/
float FrameControllerGetFramesPerSecond();

/*************************************************
* void FrameControllerForceFrameRate()
* Limits the game's framerate to the current value
* Called within the game loop
*************************************************/
void FrameControllerForceFrameRate(); 
