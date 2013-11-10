#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "VisibleGameObject.h"

class Clickable : public VisibleGameObject
{
  public:
    Clickable();
    ~Clickable();

    void Callback( void (*f)());
    void Exec() const;

  private:
    void (*_callback)();
    
};

#endif
