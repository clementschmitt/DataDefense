#include "Level.h"
#include <iostream>

Level::~Level()
{
    std::cout << "destruction level \n";
}

void Level::LevelInit()
{
    std::cout << "level initilization \n";
    this->map = new Map();
    this->map->Load("../assets/img/map1.png");
}

Level::LevelResult Level::Show(sf::RenderWindow& window)
{
  window.clear(sf::Color(0,0,255));
  this->map->Draw(window);
  this->map->DrawGrid(window);
  window.display();

  return GetLevelResponse(window);
}

/* boucle de jeu */
Level::LevelResult  Level::GetLevelResponse(sf::RenderWindow& window)
{
  sf::Event levelEvent;
  while(true)
  {
    while(window.pollEvent(levelEvent))
    {
      if(levelEvent.type == sf::Event::Closed)
      {
        exit(1);
        return Exit;
      }
      if(levelEvent.type == sf::Event::KeyPressed)
      {
        return Exit;
      }
    }
  }
}
