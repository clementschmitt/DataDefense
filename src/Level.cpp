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

    /* chargement du background map */
    this->_map = new Map();
    this->_map->Load("../assets/img/map1.png");

    /* le path représente le chemin que vont prendre
     * les ennemis */
    this->_path = new Path();

    /* test avec un ennemi */

    /* on charge une seule texture pour les ennemis
     * (du même type biensur)
     */
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile("../assets/img/worm.png");

    Enemy *e = new Enemy(texture);
    this->_enemy_wave.push_back(e);

    for (int i = 0; i < 20; ++i)
    {
      for (int j = 0; j < 15; ++j)
      {
        _towerMap[i][j] = 0;
      }
    }
    /*
    Utils *u = new Utils();
    Point start;
    start.x = _start_x;
    start.y = _start_y;
    Point end;
    end.x = _close_x;
    end.y = _close_y;
    std::vector<Point> path;
    //u->aStar(start, end, &path, _towerMap);
    u->aStar(start, end, path, _towerMap);
    */

}

Level::LevelResult Level::Show(sf::RenderWindow& window)
{
  
  return GetLevelResponse(window);
}

/* boucle de jeu */
Level::LevelResult  Level::GetLevelResponse(sf::RenderWindow& window)
{
  window.setFramerateLimit(60);
  sf::Clock frameClock;
  
  sf::Event levelEvent;

  while(true)
  {

    /* 
     * process input 
     */
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

    /*
     * update
     */
    this->_enemy_wave.Update();
    
    /*
     * render
     */
    window.clear(sf::Color(0,0,0));
    this->_map->Draw(window);
    this->_map->DrawGrid(window);
    this->_path->DrawPath(window,_start_x,_start_y,_close_x,_close_y);
    this->_enemy_wave.Draw(window,frameClock.restart());
    this->_event_manager->Draw(window);
    window.display();

  }
}
