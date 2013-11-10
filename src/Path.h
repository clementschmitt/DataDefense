#include "VisibleGameObject.h"

class Path: public VisibleGameObject
{
  public:
    Path();
    ~Path();

    void DrawPath(sf::RenderWindow& window, int, int, int, int);
};
