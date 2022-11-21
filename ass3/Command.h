#pragma once
#include <iostream>
#include <typeinfo>

// Is heavly inspired by the folling Design Pattern
//https://refactoring.guru/design-patterns/command/cpp/example

/**
 * The Command interface declares a method for executing a command.
 */
class Command {
 public:
  virtual ~Command() {
  }
  virtual void Execute() const = 0;
};


/**
 * The Invoker is associated with one or several commands. It sends a request to
 * the command.
 */
class Invoker {
  /**
   * @var Command
   */
 private:
  Command *on_start_;
  /**
   * @var Command
   */
  Command *on_finish_;
  /**
   * Initialize commands.
   */
 public:
  ~Invoker() {
    delete on_start_;
    delete on_finish_;
  }

  void SetOnStart(Command *command) {
    this->on_start_ = command;
  }
  void SetOnFinish(Command *command) {
    this->on_finish_ = command;
  }
  /**
   * The Invoker does not depend on concrete command or receiver classes. The
   * Invoker passes a request to a receiver indirectly, by executing a command.
   */
  void DoSomethingImportant() {
    if (this->on_start_) {
      this->on_start_->Execute();
    }

    if (this->on_finish_) {
      this->on_finish_->Execute();
    }
  }
};

