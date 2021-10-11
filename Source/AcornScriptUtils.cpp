/****************************************************************************
 *  File name: 
 *  Description:
 *      - 
  
*****************************************************************************/
#include "OEngine.h"
#include "AcornScriptUtils.h"
#include <iostream>




/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

namespace Utils
{
  namespace AcornScript
  {
    std::string ParseInsideBrackets(std::string& line, char opening, char closing, int start)
    {
      std::string result;
      int i = line.find(opening, start);
      if (i == std::string::npos || line.find(closing,start) == std::string::npos)
      {
        assert(false, "SYNTAX ERROR IN SCRIPT");
      }
      i++;
      while (line[i] != closing)
      {
        result.push_back(line[i]);
        i++;
      }
      return result;
    }
  }
}


/* Private functions definitions  */



