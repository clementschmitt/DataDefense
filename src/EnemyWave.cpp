#include "EnemyWave.h"

void EnemyWave::Draw(sf::RenderWindow& window, sf::Time time)
{
    std::list<Enemy*>::iterator it;
    for (it = this->begin(); it!=this->end(); it++)
    {
        (*it)->update(time);
        window.draw(**it);
    }
}

/* changement d'état */
void EnemyWave::Update()
{
    std::list<Enemy*>::iterator it;
    for (it = this->begin(); it!=this->end(); it++)
    {
        (*it)->UpdateEnemy();
    }
}
