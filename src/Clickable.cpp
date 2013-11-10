#include "Clickable.h"

Clickable::Clickable(){}
Clickable::~Clickable(){}


void Clickable::Callback( void (*f)())
{
  _callback = f;
}

void Clickable::Exec() const
{
  (*_callback)();
}
