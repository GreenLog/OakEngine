/****************************************************************************
 *  File name:
 *  Description:
 *      - 
  
*****************************************************************************/
#pragma once
#include <string>
/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */


namespace Utils
{
  namespace AcornScript
  {
    std::string ParseInsideBrackets(std::string& line, char opening, char closing, int start = 0);
  }
}
