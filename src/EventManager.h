#include <list>
#include "Clickable.h"

class EventManager
{
  public:
    EventManager();
    ~EventManager();

    void AddClickable(const Clickable* clickable);
    void CallbackClickable();

  private:
   std::list<const Clickable*> _clickable; 
};
