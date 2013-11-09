#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Map.h"

class Level
{
  public:
    ~Level();
    enum LevelResult { Nothing, Exit };
    LevelResult Show(sf::RenderWindow& window);
    void LevelInit();

  private:
    LevelResult GetLevelResponse(sf::RenderWindow& window);
    Map *map;
    /* background img */
    sf::Sprite img_map;
};
