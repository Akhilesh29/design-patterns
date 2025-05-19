#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace structural {
namespace decorator {

// Component
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual double cost() const = 0;
    virtual std::string description() const = 0;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    double cost() const override { return 1.0; }
    std::string description() const override { return "Simple Coffee"; }
};

// Decorator
class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    
    double cost() const override { return coffee->cost(); }
    std::string description() const override { return coffee->description(); }
    
protected:
    std::shared_ptr<Coffee> coffee;
};

// Concrete Decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    
    double cost() const override {
        return coffee->cost() + 0.5;
    }
    
    std::string description() const override {
        return coffee->description() + " with Milk";
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    
    double cost() const override {
        return coffee->cost() + 0.2;
    }
    
    std::string description() const override {
        return coffee->description() + " with Sugar";
    }
};

class CaramelDecorator : public CoffeeDecorator {
public:
    CaramelDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    
    double cost() const override {
        return coffee->cost() + 0.7;
    }
    
    std::string description() const override {
        return coffee->description() + " with Caramel";
    }
};

} // namespace decorator
} // namespace structural 