#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
  sf::Font font;
  font.loadFromFile("../assets/fonts/bd.ttf");

  MenuItem playButton;
  playButton.rect.setSize(sf::Vector2f(600,150));
  playButton.rect.setPosition(sf::Vector2f(100,100));
  sf::Text playText;
  playText.setFont(font);
  playText.setString("Play");
  playText.setPosition(sf::Vector2f(300,80));
  playText.setColor(sf::Color(0,0,0));
  playText.setCharacterSize(150);

  
  MenuItem exitButton;
  exitButton.rect.setSize(sf::Vector2f(600,150));
  exitButton.rect.setPosition(sf::Vector2f(100,350));
  sf::Text exitText;
  exitText.setFont(font);
  exitText.setString("Exit");
  exitText.setPosition(sf::Vector2f(300,330));
  exitText.setColor(sf::Color(0,0,0));
  exitText.setCharacterSize(150);


  _menuItems.push_back(playButton);
  _menuItems.push_back(exitButton);

  window.clear(sf::Color(0,0,0));
  window.draw(playButton.rect);
  window.draw(exitButton.rect);
  window.draw(playText);
  window.draw(exitText);
  window.display();

  return GetMenuResponse(window);
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
  sf::Event menuEvent;
  while(true)
  {
    while(window.pollEvent(menuEvent))
    {
      if(menuEvent.type == sf::Event::MouseButtonPressed)
      {
        return Play;
      }
      if(menuEvent.type == sf::Event::Closed)
      {
        return Exit;
      }
    }
  }
}
