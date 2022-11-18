#pragma once

#include "State.h"

class Mode1 : public State
{
  public:
    void chMode() override{
        std::cout << "Mode1 to Mode2\n";
        this->context_->TransitionTo(new Mode2);
    }
};

class Mode2 : public State
{
  public:
    void chMode() override{
        std::cout << "Mode2 to Mode3\n";
        this->context_->TransitionTo(new Mode3);
    }
};

class Mode3 : public State
{
  public:
    void chMode() override{
        std::cout << "Mode3 to Mode1\n";
        this->context_->TransitionTo(new Mode1);
    }
};

void ApplicationModeSetting()
{
  Context *context = new Context(new Mode1);
  context->RequestchMode();
  context->RequestchMode();
  context->RequestchMode();
  delete context;
}
  



