#pragma once

#include "State.h"

class Simulation : public State
{
  public:
    void RunRealTime() override;
};

class RealTimeExecution : public State
{
  public:
    void Simulate() override;
};

void Simulation::RunRealTime(){
  std::cout << "RunRealTime to RealTimeExecution\n";
  this->context_->TransitionTo(new RealTimeExecution);
}

void RealTimeExecution::Simulate(){
  std::cout << "RealTimeExecution to RunRealTime\n";
  this->context_->TransitionTo(new Simulation);
}

void SimulateRealTime()
{
  Context *context = new Context(new RealTimeExecution);
  context->RequestSimulate();
  context->RequestRunRealTime();
  delete context;
}

