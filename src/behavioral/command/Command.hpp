#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace behavioral {
namespace command {

// Command interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver
class Light {
public:
    void turnOn() {
        std::cout << "Light is on" << std::endl;
    }
    
    void turnOff() {
        std::cout << "Light is off" << std::endl;
    }
};

// Concrete Commands
class LightOnCommand : public Command {
public:
    LightOnCommand(std::shared_ptr<Light> light) : light(light) {}
    
    void execute() override {
        light->turnOn();
    }
    
    void undo() override {
        light->turnOff();
    }
    
private:
    std::shared_ptr<Light> light;
};

class LightOffCommand : public Command {
public:
    LightOffCommand(std::shared_ptr<Light> light) : light(light) {}
    
    void execute() override {
        light->turnOff();
    }
    
    void undo() override {
        light->turnOn();
    }
    
private:
    std::shared_ptr<Light> light;
};

// Invoker
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> command) {
        this->command = command;
    }
    
    void pressButton() {
        if (command != nullptr) {
            command->execute();
        }
    }
    
    void pressUndo() {
        if (command != nullptr) {
            command->undo();
        }
    }
    
private:
    std::shared_ptr<Command> command;
};

} // namespace command
} // namespace behavioral 