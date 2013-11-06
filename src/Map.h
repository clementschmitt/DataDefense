#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string>

class Map
{
  public:
    void Show(sf::RenderWindow& window);

  private:
    std::string map_path;
};
