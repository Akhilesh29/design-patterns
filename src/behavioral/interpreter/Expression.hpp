#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

namespace behavioral {
namespace interpreter {

// Abstract Expression
class Expression {
public:
    virtual ~Expression() = default;
    virtual int interpret(std::unordered_map<std::string, int>& context) = 0;
};

// Terminal Expression
class Number : public Expression {
public:
    Number(int value) : value(value) {}
    
    int interpret(std::unordered_map<std::string, int>&) override {
        return value;
    }
    
private:
    int value;
};

class Variable : public Expression {
public:
    Variable(const std::string& name) : name(name) {}
    
    int interpret(std::unordered_map<std::string, int>& context) override {
        return context[name];
    }
    
private:
    std::string name;
};

// Non-terminal Expressions
class Add : public Expression {
public:
    Add(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(left), right(right) {}
    
    int interpret(std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) + right->interpret(context);
    }
    
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};

class Subtract : public Expression {
public:
    Subtract(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(left), right(right) {}
    
    int interpret(std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) - right->interpret(context);
    }
    
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};

class Multiply : public Expression {
public:
    Multiply(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(left), right(right) {}
    
    int interpret(std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) * right->interpret(context);
    }
    
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};

} // namespace interpreter
} // namespace behavioral 