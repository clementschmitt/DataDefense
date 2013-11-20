#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture)
{
  _texture = texture;
  _isCarryingData = false;
  _state = Walking;
  
  this->setPosition(100,100);
  this->setFrameTime(sf::seconds(0.2));
  
  _walking.setSpriteSheet(*_texture);
  _walking.addFrame(sf::IntRect(0,60,30,30));
  _walking.addFrame(sf::IntRect(30,60,30,30));
  _walking.addFrame(sf::IntRect(60,60,30,30));
  _walking.addFrame(sf::IntRect(90,60,30,30));
  this->setAnimation(_walking);

}

Enemy::~Enemy(){}

/**
 * \brief fonction pour déplacer l'ennemi vers son but (les données ou la sortie)
 * \param target la cible vers laquelle l'ennemi doit se dirige
 * \return void
 */
void Enemy::moveTo()
{
}

/**
 * \brief l'ennemi attrape des données si il est à portée
 * \param 
 * \return void 
 */
void Enemy::grabData()
{

}

/**
 * \brief l'ennemi lâche les données qu'il possedait lorsqu'il meurt
 * \param
 * \return void 
 */
void Enemy::dropData()
{

}

void Enemy::UpdateEnemy()
{
   switch(_state)
   {
     case Enemy::Walking:
         Walk();
         break;
     default:
         break;
   } 
}

void Enemy::Walk()
{
  std::cout << "walk\n";
  _state = Enemy::Walking;
}

void Enemy::setWalkAnimation()
{
  }
