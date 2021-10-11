/****************************************************************************
 *  File name: utils.h
 *  Description:
 *      - Contains the interface for miscellaneous utilities functions.
  
*****************************************************************************/
#pragma once
/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

namespace Utils
{

  //An implementation of std::swap
  template<typename T>
  void Swap(T& first, T& second)
  {
    T temp = first;
    first = second;
    second = temp;
  }

}
