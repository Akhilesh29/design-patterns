#pragma once
#include <string>
#include <memory>
#include <iostream>

// {subject--> real subject-->proxy}

namespace structural {
namespace proxy {

// Subject
class Image {
public:
    virtual ~Image() = default;
    virtual void display() = 0;
};

// Real Subject
class RealImage : public Image {
public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk();
    }
    
    void display() override {
        std::cout << "Displaying " << filename << std::endl;
    }
    
private:
    void loadFromDisk() {
        std::cout << "Loading " << filename << " from disk" << std::endl;
    }
    
    std::string filename;
};

// Proxy
class ProxyImage : public Image {
public:
    ProxyImage(const std::string& filename) : filename(filename) {}
    
    void display() override {
        if (realImage == nullptr) {
            realImage = std::make_unique<RealImage>(filename);
        }
        realImage->display();
    }
    
private:
    std::string filename;
    std::unique_ptr<RealImage> realImage;
};

} // namespace proxy
} // namespace structural 
