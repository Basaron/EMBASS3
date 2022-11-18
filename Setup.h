#pragma once
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

#include "State.h"
#include "ApplicationModeSetting.h"
#include "SimulateRealTime.h"

class Initializing;
class Failure;
class RealTimeLoop;

class PowerOnSelfTest : public State
{
  public:
    void SelfTestFailed() override{
        std::cout << "SelfTestFailed to Failure\n";
        this->context_->TransitionTo(new Failure);
    }

    void SelfTestOk() override{
        std::cout << "SelfTestFailed to Initializing\n";
        this->context_->TransitionTo(new Initializing);
    }
};

class Initializing : public State
{
  public:
    void Initailzed() override{
        std::cout << "Initializing to RealTimeLoop\n";
        this->context_->TransitionTo(new RealTimeLoop);
    }
};

class Failure : public State
{
  public:
    void Exit() override{
        std::cout << "Failure Exit program";
        exit (EXIT_FAILURE);
    }
    void Restart() override{
        std::cout << "Failure to PowerOnSelfTest\n";
        this->context_->TransitionTo(new PowerOnSelfTest);
    }
};

class RealTimeLoop : public State
{
  public:
    RealTimeLoop(){
        ApplicationModeSetting();
        SimulateRealTime();
    }
    void Restart() override{
        std::cout << "RealTimeLoop to PowerOnSelfTest\n";
        this->context_->TransitionTo(new PowerOnSelfTest);
    }
};

void Setup(){
    Context *context = new Context(new PowerOnSelfTest);
    context->RequestSelftestOk();
    context->RequestInitailzed();
    delete context;
}

