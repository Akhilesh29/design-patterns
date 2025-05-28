#pragma once
#include <string>
#include <memory>
#include <iostream>


// here we create each object step by step by using methods rather then using consturctor
namespace creational {
namespace builder {

class Computer {
public:
    class Builder {
    public:
        Builder& setCPU(const std::string& cpu) {
            this->cpu = cpu;
            return *this;
        }
        
        Builder& setRAM(const std::string& ram) {
            this->ram = ram;
            return *this;
        }
        
        Builder& setStorage(const std::string& storage) {
            this->storage = storage;
            return *this;
        }
        
        Computer build() {
            return Computer(cpu, ram, storage);
        }
        
    private:
        std::string cpu;
        std::string ram;
        std::string storage;
    };
    
    void display() const {
        std::cout << "Computer Configuration:" << std::endl;
        std::cout << "CPU: " << cpu << std::endl;
        std::cout << "RAM: " << ram << std::endl;
        std::cout << "Storage: " << storage << std::endl;
    }
    
private:
    Computer(const std::string& cpu, const std::string& ram, const std::string& storage)
        : cpu(cpu), ram(ram), storage(storage) {}
        
    std::string cpu;
    std::string ram;
    std::string storage;
};

} // namespace builder
} // namespace creational 
