#include "VisibleGameObject.h"

class Map: public VisibleGameObject
{
  public:
    Map();
    ~Map();

    void DrawGrid(sf::RenderWindow& window);
};
