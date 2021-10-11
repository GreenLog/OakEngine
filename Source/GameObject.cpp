/****************************************************************************
 *  File name: GameObject.cpp
 *  Description:
 *      - Contains the definitions for the GameObject class.
*****************************************************************************/

#include "OEngine.h"
#include "GameObject.h"
#include "Component.h"
#include "Sprite.h"
#include "Transform.h"
#include "TimeHandler.h"
#include "Animation.h"

#define GetComponent(type) _TEMPLETIZED_COMPONENT_GETTER_<type>(ComponentType::##type)
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

GameObject::GameObject(const char* name, ...)
  : name_(name)
  , timer_(-1)
{
  va_list args;
  va_start(args, name);
  ComponentPtr component;
  while ((component = va_arg(args, ComponentPtr)))
  {
    AddComponent(component);
  }
  va_end(args);

}

GameObject::~GameObject()
{
  foreach(component, components_)
  {
    delete component.second;
  }
  
  components_.erase(components_.begin(), components_.end());
}

void GameObject::AddComponent(ComponentPtr component)
{
  component->SetParent(this);
  components_.insert(std::pair<ComponentType, ComponentPtr>(component->GetType(), component));
}

void GameObject::Update()
{
  foreach (component, components_)
  {
    component.second->Update();
  }
  if (timer_ > 0)
  {
    timer_ -= dt;
  }
  else
  {
    timer_ = -1;
  }
  
}

void GameObject::SetTimer(float timer)
{
  timer_ = timer;
}

bool GameObject::IsTimerFinished()
{
  if (timer_ <= 0)
  {
    return true;
  }
}

void GameObject::Draw()
{
  SpritePtr sprite = GetComponent(Sprite);
  AnimationManager* ani = GetComponent(AnimationManager);

  if (ani)
  {
    TransformPtr transform = GetComponent(Transform);
    ani->Draw(transform->GetTranslation().x, transform->GetTranslation().y, true);
  }
  else if (sprite)
  {
    TransformPtr transform = GetComponent(Transform);
    sprite->Draw(transform->GetTranslation().x, transform->GetTranslation().y, true);
  }
  return;
}

