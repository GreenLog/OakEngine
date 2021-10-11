/****************************************************************************
 *  File name: Component.h
 *  Description:
 *      - Contains the interface for the Component class for the component-based
 *        architecture of this engine.
  
*****************************************************************************/
#pragma once

typedef class GameObject* GameObjectPtr;

enum class ComponentType
{
  Invalid = -1,
  Transform,
  Sprite,
  Collider,
  Physics,
  ParticleEmitter,
  Behaviour,
  PlayerController,
  AnimationManager,
  Collectible,
  Grabbing,
  NPC,
  Door,
  BoolDummy,
  Button
};

/* Constants                      */

/* Enums                          */




/* Public classes                 */

class Component
{
public:
  Component(ComponentType type);
  ComponentType GetType();
  void SetParent(GameObjectPtr parent);
  GameObjectPtr GetParent();
  __inline virtual void Update() { return; };
  __inline virtual void Draw() { return; } ;
private:
  GameObjectPtr parent_;
  ComponentType type_;
};
typedef class Component* ComponentPtr;

/* Public functions declarations  */

