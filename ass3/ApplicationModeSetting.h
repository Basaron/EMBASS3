#pragma once

#include "State.h"

class Mode1 : public State
{
  public:
    void chMode() override;
};

class Mode2 : public State
{
  public:
    void chMode() override;
};

class Mode3 : public State
{
  public:
    void chMode() override;
};

void Mode1::chMode(){
  std::cout << "Mode1 to Mode2\n";
  this->context_->TransitionTo(new Mode2);
}

void Mode2::chMode(){
  std::cout << "Mode1 to Mode2\n";
  this->context_->TransitionTo(new Mode3);
}

void Mode3::chMode(){
  std::cout << "Mode1 to Mode2\n";
  this->context_->TransitionTo(new Mode1);
}


void ApplicationModeSetting()
{
  Context *context = new Context(new Mode1);
  context->RequestchMode();
  context->RequestchMode();
  context->RequestchMode();
  delete context;
}
  



