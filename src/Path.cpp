#include "Path.h"
#include <vector>

Path::Path(){}
Path::~Path(){}

struct tg{
    int a;
    int b;
} ;

struct tg case_to_xy(int a, int b)
{
  tg tmp;
  tmp.a = a *40;
  tmp.b = b *40;

  return tmp;
}

void Path::DrawPath(sf::RenderWindow& window, int start_x, int start_y, int close_x, int close_y)
{
  std::vector<tg> v;
  /* appel à a* depuis utils */  
  for (int i=0;i<20;i++)
  {
    tg lol;
    lol.a = i;
    lol.b = 8;
    v.push_back(lol);
  }
  
  std::vector<tg>::iterator it;

  for (it = v.begin(); it != v.end(); ++it)
  {
    tg tmp = case_to_xy((*it).a,(*it).b);
    sf::RectangleShape rct(sf::Vector2f(39,39));
    rct.setFillColor(sf::Color(255,255,255,125));
    rct.setPosition(sf::Vector2f(tmp.a,tmp.b));
    window.draw(rct);
  }
}
