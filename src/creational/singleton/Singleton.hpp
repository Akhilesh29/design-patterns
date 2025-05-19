#pragma once
#include <mutex>
#include <memory>
#include <iostream>

namespace creational {
namespace singleton {

class Singleton {
public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static method to get the instance
    static Singleton& getInstance();

    // Example method
    void doSomething() {
        std::cout << "Singleton is doing something!" << std::endl;
    }

private:
    // Private constructor
    Singleton() = default;
    
    // Static instance
    static std::unique_ptr<Singleton> instance;
    static std::mutex mutex;
};

} // namespace singleton
} // namespace creational 