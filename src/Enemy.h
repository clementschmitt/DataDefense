#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "VisibleGameObject.h"
#include "Animation.h"
#include "AnimatedSprite.h"

enum attack{
  virus,
  spyware,
  malware,
  trojan,
  phising,
  scam
  //à compléter
};


class Enemy : public AnimatedSprite
{
  public:
    enum state{Walking};
    Enemy(sf::Texture* texture);
    ~Enemy();

    void UpdateEnemy();
    void Walk();

    void moveTo();
    void grabData();
    void dropData();

    /* animation */
    void setWalkAnimation();

  private:
    int _life;
    int _speed;
    bool _isDead; 
    bool _isCarryingData;
    attack _type; 
    state _state;
    sf::Texture* _texture;
    Animation _walking;
    //std::vector<Point> _path;
};

#endif
