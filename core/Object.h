#pragma once

#include "../pch.h"


class Object
{
  protected:
    std::vector<Action> actions;
    void receiveSignal(Signal_);
};
