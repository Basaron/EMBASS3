#pragma once

#include "State.h"

class Simulation : public State
{
  public:
    void RunRealTime() override{
        std::cout << "RunRealTime to RealTimeExecution\n";
        this->context_->TransitionTo(new RealTimeExecution);
    }
};

class RealTimeExecution : public State
{
  public:
    void Simulate() override{
        std::cout << "RealTimeExecution to RunRealTime\n";
        this->context_->TransitionTo(new RunRealTime);
    }
};

void SimulateRealTime()
{
    Context *context = new Context(new RealTimeExecution);
    context->RequestSimulate();
    context->RequestRunRealTime();
    delete context;
}

