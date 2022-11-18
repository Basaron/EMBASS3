#pragma once

#include <iostream>
#include <typeinfo>


class Context;

class State {
  /**
   * @var Context
   */
 protected:
  Context *context_;

 public:
  virtual ~State() {
  }

  void set_context(Context *context) {
    this->context_ = context;
  }

  virtual void SelfTestOk(){}
  virtual void Initailzed(){}
  virtual void SelfTestFailed(){}
  virtual void Restart(){}
  virtual void Exit(){}

  virtual void chMode(){}

  virtual void RunRealTime(){}
  virtual void Simulate(){}
};

class Context {
  /**
   * @var State A reference to the current state of the Context.
   */
 private:
  State *state_;

 public:
  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }
  ~Context() {
    delete state_;
  }
  /**
   * The Context allows changing the State object at runtime.
   */
  void TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }
  /**
   * The Context delegates part of its behavior to the current State object.
   */
  void RequestSelftestOk() {
    this->state_->SelfTestOk();
  }
  void RequestInitailzed() {
    this->state_->Initailzed();
  }
  void RequestSelfTestFailed() {
    this->state_->SelfTestFailed();
  }
  void RequestRestart() {
    this->state_->Restart();
  }
  void RequestExit() {
    this->state_->Exit();
  }


  void RequestchMode() {
    this->state_->chMode();
  }


  void RequestRunRealTime() {
    this->state_->RunRealTime();
  }
  void RequestSimulate() {
    this->state_->Simulate();
  }

};
