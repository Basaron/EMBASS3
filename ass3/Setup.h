#pragma once
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

#include "State.h"
#include "ApplicationModeSetting.h"
#include "SimulateRealTime.h"

// the tree dummy function for the behavior of the state
void systemSelftest()
{
    std::cout << "      Execute: systemSelftest \n";
    return;
}

void display()
{
    std::cout << "      Execute: display(): \n";
    return;
}

void startInitializing()
{
    std::cout << "      Execute: startInitializing \n";
    return;
}

// creates the given state by inharioting the public of the State class
// Here the behavior of the state is exicuted on the creation of the state
// Then the posible transtion of the state is override to go to the desiced state for this class
class PowerOnSelfTest : public State
{
public:
    PowerOnSelfTest()
    {
        systemSelftest();
    }
    void SelfTestFailed() override;

    void SelfTestOk() override;
};

// creates the given state by inharioting the public of the State class
// Here the behavior of the state is exicuted on the creation of the state
// Then the posible transtion of the state is override to go to the desiced state for this class
class Initializing : public State
{
public:
    Initializing()
    {
        Invoker *invoker = new Invoker;
        invoker->SetOnStart(new SimulationCommand());

        invoker->DoSomethingImportant();

        delete invoker;
        
        startInitializing();
    }

    void Initailzed() override;
};

// creates the given state by inharioting the public of the State class
// Here the behavior of the state is exicuted on the creation of the state
// Then the posible transtion of the state is override to go to the desiced state for this class
class Failure : public State
{
public:
    Failure()
    {

        display();
    }

    void Exit() override
    {
        std::cout << "      Failure Exit program\n";
        exit(EXIT_FAILURE);
    }
    void Restart() override;
};

// creates the given state by inharioting the public of the State class
// Here the behavior of the state is exicuted on the creation of the state
// Then the posible transtion of the state is override to go to the desiced state for this class
class RealTimeLoop : public State
{
public:
    // Here the behavio is to create two new state machine
    RealTimeLoop()
    {
        Invoker *invoker = new Invoker;
        invoker->SetOnStart(new SimulationCommand());

        invoker->DoSomethingImportant();

        ApplicationModeSetting();

        delete invoker;
    }
    void Restart() override;
};

// Here all the transtion overrides are created for all the difrent state classes
void PowerOnSelfTest::SelfTestFailed()
{
    std::cout << "  PowerOnSelfTest to Failure\n";
    this->context_->TransitionTo(new Failure);
}

void PowerOnSelfTest::SelfTestOk()
{
    std::cout << "  PowerOnSelfTest to Initializing\n";
    this->context_->TransitionTo(new Initializing);
}

void Initializing::Initailzed()
{
    std::cout << "  Initailzed to RealTimeLoop\n";
    this->context_->TransitionTo(new RealTimeLoop);
}
void Failure::Restart()
{
    std::cout << "  Failure to PowerOnSelfTest\n";
    this->context_->TransitionTo(new PowerOnSelfTest);
}

void RealTimeLoop::Restart()
{
    std::cout << "  RealTimeLoop to PowerOnSelfTest\n";
    this->context_->TransitionTo(new PowerOnSelfTest);
}

// Here the behavior of the State machin is created
void Setup()
{
    std::cout << "\nStart the Setup State machine \n";

    Context *context = new Context(new PowerOnSelfTest);
    context->RequestSelfTestFailed();
    context->RequestRestart();
    context->RequestSelftestOk();
    context->RequestInitailzed();
    context->RequestRestart();
    context->RequestSelfTestFailed();
    context->RequestExit();
    delete context;
}
