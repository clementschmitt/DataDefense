#include <iostream>
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
  _isLoaded = false;
}

VisibleGameObject::~VisibleGameObject(){}

void VisibleGameObject::Load(std::string filename)
{
  if(!_texture.loadFromFile(filename))
  {
    _filename = "";
    _isLoaded = false;
  } else {
    _filename = filename;
    _sprite.setTexture(_texture);
    _isLoaded = true;
  }
}

void VisibleGameObject::Draw(sf::RenderWindow& window)
{
  if(_isLoaded)
  {
    window.draw(_sprite);
  } else {
    std::cout << "Error: can't draw sprite !\n";
  }
}

void VisibleGameObject::SetPosition(float x, float y)
{
}
