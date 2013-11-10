#include <list>
#include "Clickable.h"

class EventManager
{
  public:
    EventManager();
    ~EventManager();

    void AddClickable(const Clickable* clickable);
    void CallbackClickable(int x, int y);

  private:
   std::list<const Clickable*> _clickable; 
};
