/****************************************************************************
 *  File name: OEGameLoop.cpp
 *  Description:
 *      - Contains the interface for the  main gameloop functions: Init, Update and Shutdown.
 *        Ideally should only be called from main.cpp

*****************************************************************************/
#pragma once

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

/*!*******************************************
* void GameLoopInit()
* Initializes the important game variables
*
*********************************************/
void GameLoopInit();

/*!*******************************************
* void GameLoopUpdate()
* Fires every frame, everything happens here
*
*********************************************/
void GameLoopUpdate(bool&);

/*!**********************************************
* void GameLoopShutdown()
* Is called when the game is closed, frees memory
*
*************************************************/
void GameLoopShutdown();
