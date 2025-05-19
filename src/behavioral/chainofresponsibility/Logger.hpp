#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace behavioral {
namespace chainofresponsibility {

// Handler
class Logger {
public:
    virtual ~Logger() = default;
    
    void setNext(std::shared_ptr<Logger> next) {
        this->next = next;
    }
    
    virtual void log(const std::string& message, int level) {
        if (next != nullptr) {
            next->log(message, level);
        }
    }
    
protected:
    std::shared_ptr<Logger> next;
};

// Concrete Handlers
class ConsoleLogger : public Logger {
public:
    ConsoleLogger(int level) : level(level) {}
    
    void log(const std::string& message, int messageLevel) override {
        if (messageLevel <= level) {
            std::cout << "Console Logger: " << message << std::endl;
        }
        Logger::log(message, messageLevel);
    }
    
private:
    int level;
};

class FileLogger : public Logger {
public:
    FileLogger(int level) : level(level) {}
    
    void log(const std::string& message, int messageLevel) override {
        if (messageLevel <= level) {
            std::cout << "File Logger: " << message << std::endl;
        }
        Logger::log(message, messageLevel);
    }
    
private:
    int level;
};

class ErrorLogger : public Logger {
public:
    ErrorLogger(int level) : level(level) {}
    
    void log(const std::string& message, int messageLevel) override {
        if (messageLevel <= level) {
            std::cout << "Error Logger: " << message << std::endl;
        }
        Logger::log(message, messageLevel);
    }
    
private:
    int level;
};

} // namespace chainofresponsibility
} // namespace behavioral 