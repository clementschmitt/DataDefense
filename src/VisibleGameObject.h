#ifndef VISIBLE_H
#define VISIBLE_H

#include <iostream>
#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class VisibleGameObject
{
  public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow& window);

    virtual void SetPosition(float x, float y);

  private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    std::string _filename;
    bool _isLoaded;
};
#endif
