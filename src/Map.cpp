#include "Map.h"

Map::Map(){}
Map::~Map(){}

void Map::DrawGrid(sf::RenderWindow& window)
{
  sf::Vertex vertices[]
  {
    /* vertical */
    sf::Vertex(sf::Vector2f( 40, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 40, 600), sf::Color::White, sf::Vector2f( 0, 10)),

    sf::Vertex(sf::Vector2f( 80, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 80, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 120, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 120, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 160, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 160, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 200, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 200, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 240, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 240, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 280, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 280, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 320, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 320, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 360, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 360, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 400, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 400, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 440, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 440, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 480, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 480, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 520, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 520, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 560, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 560, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 600, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 600, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 640, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 640, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 680, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 680, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 720, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 720, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 760, 0), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 760, 600), sf::Color::White, sf::Vector2f( 0, 10)),
    
    /* horizontal */
    sf::Vertex(sf::Vector2f( 0, 40), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 40), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 80), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 80), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 120), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 120), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 160), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 160), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 200), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 200), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 240), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 240), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 280), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 280), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 320), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 320), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 360), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 360), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 400), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 400), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 440), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 440), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 480), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 480), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 520), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 520), sf::Color::White, sf::Vector2f( 0, 10)),
    
    sf::Vertex(sf::Vector2f( 0, 560), sf::Color::White, sf::Vector2f( 0, 0)),
    sf::Vertex(sf::Vector2f( 800, 560), sf::Color::White, sf::Vector2f( 0, 10)),
  };

  window.draw(vertices,66,sf::Lines);
}
