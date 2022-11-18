#pragma once
#include"State.h"
#include <iostream>
#include <typeinfo>

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