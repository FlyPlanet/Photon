#pragma once

#include "../pch.h"
#include "DOMTree.h"
#include "Observer.h"
class Object
{
  private:
    DOMUnit* self;

  public:
    std::vector<ObserveFunction> observeFunctions;
    Object(){}

};
