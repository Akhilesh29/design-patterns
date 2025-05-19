#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace structural {
namespace composite {

// Component
class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;
    virtual void display(int depth = 0) const = 0;
    virtual void add(std::shared_ptr<FileSystemComponent> component) {
        throw std::runtime_error("Cannot add to leaf component");
    }
    virtual void remove(std::shared_ptr<FileSystemComponent> component) {
        throw std::runtime_error("Cannot remove from leaf component");
    }
};

// Leaf
class File : public FileSystemComponent {
public:
    File(const std::string& name) : name(name) {}
    
    void display(int depth = 0) const override {
        std::cout << std::string(depth, '-') << "File: " << name << std::endl;
    }
    
private:
    std::string name;
};

// Composite
class Directory : public FileSystemComponent {
public:
    Directory(const std::string& name) : name(name) {}
    
    void display(int depth = 0) const override {
        std::cout << std::string(depth, '-') << "Directory: " << name << std::endl;
        for (const auto& component : components) {
            component->display(depth + 2);
        }
    }
    
    void add(std::shared_ptr<FileSystemComponent> component) override {
        components.push_back(component);
    }
    
    void remove(std::shared_ptr<FileSystemComponent> component) override {
        auto it = std::find(components.begin(), components.end(), component);
        if (it != components.end()) {
            components.erase(it);
        }
    }
    
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> components;
};

} // namespace composite
} // namespace structural 