#include <list>
#include "Clickable.h"

class EventManager
{
  public:
    EventManager();
    ~EventManager();

    void AddClickable(const Clickable* clickable);
    void CallbackClickable(int x, int y);
    void Draw(sf::RenderWindow& window);

  private:
   std::list<const Clickable*> _clickable; 
};
