#pragma once

#include "State.h"

//creates the given state by inharioting the public of the State class
//Then the posible transtion of the state is override to go to the desiced state for this class
class Mode1 : public State
{
public:
  void chMode() override;
};

//creates the given state by inharioting the public of the State class
//Then the posible transtion of the state is override to go to the desiced state for this class
class Mode2 : public State
{
public:
  void chMode() override;
};

//creates the given state by inharioting the public of the State class
//Then the posible transtion of the state is override to go to the desiced state for this class
class Mode3 : public State
{
public:
  void chMode() override;
};

//Here all the transtion overrides are created for all the difrent state classes
void Mode1::chMode()
{
  std::cout << "  Mode1 to Mode2\n";
  this->context_->TransitionTo(new Mode2);
}

void Mode2::chMode()
{
  std::cout << "  Mode2 to Mode3\n";
  this->context_->TransitionTo(new Mode3);
}

void Mode3::chMode()
{
  std::cout << "  Mode3 to Mode1\n";
  this->context_->TransitionTo(new Mode1);
}

//Here the behavior of the State machin is created
void ApplicationModeSetting()
{
  std::cout << "Start the ApplicationModeSetting State machine \n";

  Context *context = new Context(new Mode1);
  context->RequestchMode();
  context->RequestchMode();
  context->RequestchMode();

  std::cout << "\n";
  delete context;
}
