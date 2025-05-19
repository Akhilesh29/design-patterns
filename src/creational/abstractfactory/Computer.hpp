#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace creational {
namespace abstractfactory {

// Abstract Products
class CPU {
public:
    virtual ~CPU() = default;
    virtual void process() = 0;
};

class RAM {
public:
    virtual ~RAM() = default;
    virtual void store() = 0;
};

// Concrete Products for Windows
class WindowsCPU : public CPU {
public:
    void process() override {
        std::cout << "Windows CPU processing" << std::endl;
    }
};

class WindowsRAM : public RAM {
public:
    void store() override {
        std::cout << "Windows RAM storing" << std::endl;
    }
};

// Concrete Products for Mac
class MacCPU : public CPU {
public:
    void process() override {
        std::cout << "Mac CPU processing" << std::endl;
    }
};

class MacRAM : public RAM {
public:
    void store() override {
        std::cout << "Mac RAM storing" << std::endl;
    }
};

// Abstract Factory
class ComputerFactory {
public:
    virtual ~ComputerFactory() = default;
    virtual std::unique_ptr<CPU> createCPU() = 0;
    virtual std::unique_ptr<RAM> createRAM() = 0;
};

// Concrete Factories
class WindowsFactory : public ComputerFactory {
public:
    std::unique_ptr<CPU> createCPU() override {
        return std::make_unique<WindowsCPU>();
    }
    
    std::unique_ptr<RAM> createRAM() override {
        return std::make_unique<WindowsRAM>();
    }
};

class MacFactory : public ComputerFactory {
public:
    std::unique_ptr<CPU> createCPU() override {
        return std::make_unique<MacCPU>();
    }
    
    std::unique_ptr<RAM> createRAM() override {
        return std::make_unique<MacRAM>();
    }
};

} // namespace abstractfactory
} // namespace creational 