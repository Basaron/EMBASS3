#pragma once

#include "State.h"
#include "Command.h"

// creates the global SimCount counter
int SimCount = 0;

//Creates a Command Simulation
class SimulationCommand : public Command
{
public:
  void Execute() const override
  {
    std::cout << "    Command do Simulation\n";
    SimCount++;
    std::cout << "   " << SimCount << "\n";
  }
};

//Creates a Command RealTimeExecution
class RealTimeExecutionCommand : public Command
{
public:
  void Execute() const override
  {
    std::cout << "Command do RealTimeExecution";
  }
};
