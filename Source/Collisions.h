/****************************************************************************
 *  File name:  Collisions.h
 *  Description:
 *      - Interface for the Collider component. 
  
*****************************************************************************/
#pragma once
#include <vector>
/* Constants                      */

/* Enums                          */

/* Public classes                 */

class Collider : public Component
{
public:

  Collider();

  ~Collider();

  void Update();

  bool IsColliding(Component& other);

private:

  static std::vector<Collider*> colliders_;





};

/* Public functions declarations  */

