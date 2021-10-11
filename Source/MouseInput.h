/****************************************************************************
 *  File name: MouseInput.h
 *  Description:
 *      - Handles playerside mouse input
  
*****************************************************************************/
#pragma once

#define MouseX MouseGetX()
#define MouseY MouseGetY()

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

void MouseUpdate();

float MouseGetX();

float MouseGetY();

bool MouseLeftIsClicked();

bool MouseRightIsClicked();

bool MouseMiddleIsClikced();

bool MouseLeftIsUp();

bool MouseRightIsUp();

bool MouseMiddleIsUp();

bool MouseLeftIsDown();

bool MouseRightIsDown();

bool MouseMiddleIsDown();

float MouseGetHorizontalMotion();

float MouseGetVerticalMotion();
