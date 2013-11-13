#include "EventManager.h"

EventManager::EventManager(){}
EventManager::~EventManager(){}

/* add clickable to the list */
void EventManager::AddClickable(const Clickable* clickable)
{
  _clickable.push_front(clickable);
}

void EventManager::Draw(sf::RenderWindow& window)
{
  std::list<const Clickable*>::const_iterator iterator;

  for (iterator = _clickable.begin(); iterator != _clickable.end(); ++iterator)
  {
    //(*iterator)->Draw(window); 
  }
 
}

void EventManager::CallbackClickable(int x, int y)
{
  std::list<const Clickable*>::const_iterator iterator;

  for (iterator = _clickable.begin(); iterator != _clickable.end(); ++iterator)
  {
    (*iterator)->Exec(); 
  }
}
