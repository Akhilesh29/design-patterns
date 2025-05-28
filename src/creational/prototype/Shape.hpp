#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace creational {
namespace prototype {

// Prototype interface---> its similler to inheritance in oops, but inheritacne is not feasible for large and complex projects
class Shape {
public:
    virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

// Concrete Prototypes
class Circle : public Shape {
public:
    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}
    
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }
    
    void draw() const override {
        std::cout << "Drawing Circle at (" << x << "," << y << ") with radius " << radius << std::endl;
    }
    
private:
    int x;
    int y;
    int radius;
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int width, int height) 
        : x(x), y(y), width(width), height(height) {}
    
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }
    
    void draw() const override {
        std::cout << "Drawing Rectangle at (" << x << "," << y 
                  << ") with width " << width << " and height " << height << std::endl;
    }
    
private:
    int x;
    int y;
    int width;
    int height;
};

} // namespace prototype
} // namespace creational 
