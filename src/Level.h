#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Map.h"
#include "Path.h"
#include "EventManager.h"

class Level
{
  public:
    ~Level();
    enum LevelResult { Nothing, Exit };
    LevelResult Show(sf::RenderWindow& window);
    void LevelInit(int start_x, int start_y, int close_x, int close_y);

  private:
    LevelResult GetLevelResponse(sf::RenderWindow& window);
    Map *_map;
    Path *_path;
    EventManager *_event_manager;

    int _start_x;
    int _start_y;
    int _close_x;
    int _close_y;
};
