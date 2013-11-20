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
    VisibleGameObject isHeadingTo();
    void grabData();
    void dropData();

    /* animation */
    void setWalkAnimation();

  private:
    std::string _name; //nom de l'ennemi (peut être inutile car l'ennemi a aussi un type)
  	int _life;
  	int _speed;
  	bool _isDead; 
    bool _isCarryingData;
    attack _type; 
    state _state;
    sf::Texture* _texture;
    Animation _walking;
};

#endif
