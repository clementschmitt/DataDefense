#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game
{
  public:
    static void Start();

  private:
    static bool IsExiting();
    static void GameLoop();

    static void ShowSplashScreen();
    static void ShowMenu();
    static void ShowLevel();

    enum GameState { Uninitialized, ShowingSplash, ShowingMenu, Playing, Exiting};

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};
