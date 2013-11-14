#ifndef ENEMY_H
#define ENEMY_H

#include "VisibleGameObject.h"

enum attack{
	virus,
	spyware,
	malware,
	trojan,
	phising,
	scam
	//à compléter
}

class Enemy : public VisibleGameObject
{
  public:
    Enemy();
    ~Enemy();
    void moveTo(VisibleGameObject target);
    VisibleGameObject isHeadingTo();
    void grabData();
    void dropData();

  private:
  	string _name;  	         //nom de l'ennemi (peut être inutile car l'ennemi a aussi un type)
  	int _life;
  	int _speed;
  	bool _isDead; 
    bool _isCarryingData;
    attack _type; 
};

#endif
