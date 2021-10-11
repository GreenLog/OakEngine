/****************************************************************************
 *  File name: GameObject.h
 *  Description:
 *      - Contains the definitions for the GameObject class.
*****************************************************************************/
#pragma once
#include "Component.h"

#include <vector>
#include <cstdarg>
#include <map>

#define GetComponent(type) _TEMPLETIZED_COMPONENT_GETTER_<type>(ComponentType::##type)
#define RemoveComponent(type) _COMPONENT_REMOVOER_(ComponentType::##type)

/* Constants                      */

/* Enums                          */

/* Public classes                 */

class GameObject
{
public:
  GameObject(const char* name, ...);
  ~GameObject();
  void AddComponent(ComponentPtr component);
  template<typename T>

  //NOTE: ONLY TO BE CALLED THROUGH THE "GetComponent(type)" MACRO
  auto _TEMPLETIZED_COMPONENT_GETTER_(ComponentType typeId)
  {
    auto comp = components_.find(typeId);
    if (comp == components_.end())
    {
      T* thing = nullptr;
      return thing;
    }
    else
    {
      return reinterpret_cast<T*>(comp->second);
    }
  };

  //NOTE: ONLY TO BE CALLED THROUGH THE "RemoveComponent(type)" MACRO
  void _COMPONENT_REMOVOER_(ComponentType typeId)
  {
    components_.erase(typeId);
  }

  void SetTimer(float timer);
  bool IsTimerFinished();

  void Update();
  void Draw();
private:
  const char* name_;
  float timer_;
  std::map<ComponentType, ComponentPtr> components_;
};

/* Public functions declarations  */

