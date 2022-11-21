#pragma once

// Is heavly inspired by the folling Design Pattern
//https://refactoring.guru/design-patterns/state/cpp/example

#include <iostream>
#include <typeinfo>

//lests State know there is a Context class
class Context;

//creates the state and the let them know the transistions
class State
{
  /*
   * @var Context
   */
protected:
  //creates a Context pointer
  Context *context_;

public:
  virtual ~State(){}

  //Lets the sate know what Context it has when called
  void set_context(Context *context)
  {
    this->context_ = context;
  }

  //All the state transtions that exits
  //For setup
  virtual void SelfTestOk() {}
  virtual void Initailzed() {}
  virtual void SelfTestFailed() {}
  virtual void Restart() {}
  virtual void Exit() {}

  //For ApplicationModeSetting
  virtual void chMode() {}

  //For SimulateRealTime
  virtual void RunRealTime() {}
  virtual void Simulate() {}
};

//
class Context
{
  /**
   * @var State A reference to the current state of the Context.
   */
private:

  State *state_;

public:
  Context(State *state) : state_(nullptr)
  {
    this->TransitionTo(state);
  }
  ~Context()
  {
    delete state_;
  }
  /**
   * The Context allows changing the State object at runtime.
   */
  void TransitionTo(State *state)
  {
    //std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }
  /**
   * The Context delegates part of its behavior to the current State object.
   */

  //Creates all the Request for transtions from the current state to others
  void RequestSelftestOk()
  {
    this->state_->SelfTestOk();
  }
  void RequestInitailzed()
  {
    this->state_->Initailzed();
  }
  void RequestSelfTestFailed()
  {
    this->state_->SelfTestFailed();
  }
  void RequestRestart()
  {
    this->state_->Restart();
  }
  void RequestExit()
  {
    this->state_->Exit();
  }

  void RequestchMode()
  {
    this->state_->chMode();
  }

  void RequestRunRealTime()
  {
    this->state_->RunRealTime();
  }
  void RequestSimulate()
  {
    this->state_->Simulate();
  }
};
