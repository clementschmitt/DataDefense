#include <iostream>
#include "SplashScreen.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
  /* chargement image splashscreen */
  sf::Image image;
  if(image.loadFromFile("../assets/img/splashscreen.png") != true)
    return;

  sf::Texture texture;
  texture.loadFromImage(image);

  sf::Sprite sprite(texture);

  renderWindow.draw(sprite);
  renderWindow.display();

  sf::Event event;
  while(true)
  {
    while(renderWindow.pollEvent(event))
    {
      if(event.type == sf::Event::KeyPressed
         || event.type == sf::Event::MouseButtonPressed
         || event.type == sf::Event::Closed)
      {
        return;
      }
    }
  }
}
