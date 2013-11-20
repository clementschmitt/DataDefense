#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H

#include <list>
#include "Enemy.h"

class EnemyWave: public std::list<Enemy*>
{
    public:
      void Draw(sf::RenderWindow& window, sf::Time time);
      void Update();

    private:

};

#endif
