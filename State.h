#pragma once

#include <iostream>
#include <typeinfo>
#include "Context.h"

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

  virtual void SelfTestOk() = 0;
  virtual void Initailzed() = 0;
  virtual void SelfTestFailed() = 0;
  virtual void Restart() = 0;
  virtual void Exit() = 0;

  virtual void chMode() = 0;

  virtual void RunRealTime() = 0;
  virtual void Simulate() = 0;
};
