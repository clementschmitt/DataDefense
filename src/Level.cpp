#include "Level.h"
#include <iostream>
#include "Clickable.h"

Level::~Level()
{
    std::cout << "destruction level \n";
}

/* CALLBACK */
void play_action(){
}

void pause_action()
{
    std::cout << "pause\n";
}

void Level::LevelInit(int start_x, int start_y, int close_x, int close_y)
{
    if (start_x < 0 || start_x > 19 || start_y < 0 || start_y > 15
     || close_x < 0 || close_x > 19 || close_y < 0 || close_y > 15)
    {
      std::cout << "Error: start/close coord fail\n";
      exit(1);
    } else {
      _start_x = start_x;
      _start_y = start_y;
      _close_x = close_y;
      _close_y = close_y;
    }

    std::cout << "level initilization \n";

    Clickable *pause_button = new Clickable();
    pause_button->Load("../assets/img/pause.png");
    pause_button->Callback(&pause_action);

    /* Event Manager */
    this->_event_manager = new EventManager();
    this->_event_manager->AddClickable(pause_button);

    this->_map = new Map();
    this->_map->Load("../assets/img/map1.png");

    this->_path = new Path();
}

Level::LevelResult Level::Show(sf::RenderWindow& window)
{
  window.clear(sf::Color(0,0,255));
  this->_map->Draw(window);
  this->_map->DrawGrid(window);
  this->_path->DrawPath(window,_start_x,_start_y,_close_x,_close_y);
  this->_event_manager->Draw(window);
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
      if(levelEvent.type == sf::Event::MouseButtonPressed)
      {
        this->_event_manager->CallbackClickable(levelEvent.mouseButton.x, levelEvent.mouseButton.y);
      }
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
