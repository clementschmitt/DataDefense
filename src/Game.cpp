#include <iostream>
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Level.h"

void Game::Start(void)
{
  if(_gameState != Uninitialized)
    return;

  _mainWindow.create(sf::VideoMode(800,600,32),"Data Defense");
  _gameState = Game::ShowingSplash;

  while(!IsExiting())
  {
    GameLoop();
  }

  _mainWindow.close();
}

bool Game::IsExiting()
{
  if(_gameState == Game::Exiting)
    return true;
  else
    return false;
}

void Game::ShowSplashScreen()
{
  SplashScreen spc;
  spc.Show(_mainWindow);
  _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
  MainMenu menu;
  MainMenu::MenuResult result = menu.Show(_mainWindow);
  switch(result)
  {
    case MainMenu::Exit:
    {
      _gameState = Game::Exiting;
      break;
    }
    case MainMenu::Play:
    {
      _gameState = Game::Playing;
      break;
    }
  }
}

void Game::ShowLevel()
{
    Level level;
    level.LevelInit(0,8,19,8);
    Level::LevelResult result = level.Show(_mainWindow);

    switch(result)
    {
        case Level::Exit:
        {
          _gameState = Game::ShowingMenu;
        }
    }
}

void Game::GameLoop()
{
  sf::Event currentEvent;
  while(_mainWindow.pollEvent(currentEvent))
  {
    switch(_gameState)
    {
      case Game::Playing:
      {
        ShowLevel();
      }
      case Game::ShowingSplash:
      {
        ShowSplashScreen();
        break;
      }
      case Game::ShowingMenu:
      {
        ShowMenu();
        break;
      }
    }
  }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
