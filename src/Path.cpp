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
  /* appel à a* depuis utils */  
  std::vector<tg> v;
  tg lol;
  lol.a = 0;
  lol.b = 0;
  v.push_back(lol);

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
