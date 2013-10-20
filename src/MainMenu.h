#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class MainMenu
{
  public:
    enum MenuResult { Nothing, Play, Exit };

    struct MenuItem
    {
      public:
        sf::RectangleShape rect;
        MenuResult action;
    };

    MenuResult Show(sf::RenderWindow& window);

  private:
    MenuResult GetMenuResponse(sf::RenderWindow& window);
    MenuResult HandleClick(int x, int y);
    std::list<MenuItem> _menuItems;
};
