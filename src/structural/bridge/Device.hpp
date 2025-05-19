#pragma once
#include <string>
#include <iostream>

namespace structural {
namespace bridge {

// Implementation interface
class Device {
public:
    virtual ~Device() = default;
    virtual bool isEnabled() const = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual int getVolume() const = 0;
    virtual void setVolume(int percent) = 0;
    virtual int getChannel() const = 0;
    virtual void setChannel(int channel) = 0;
};

// Concrete Implementations
class TV : public Device {
public:
    TV() : enabled(false), volume(50), channel(1) {}
    
    bool isEnabled() const override { return enabled; }
    
    void enable() override {
        enabled = true;
        std::cout << "TV is enabled" << std::endl;
    }
    
    void disable() override {
        enabled = false;
        std::cout << "TV is disabled" << std::endl;
    }
    
    int getVolume() const override { return volume; }
    
    void setVolume(int percent) override {
        volume = percent;
        std::cout << "TV volume set to " << percent << std::endl;
    }
    
    int getChannel() const override { return channel; }
    
    void setChannel(int channel) override {
        this->channel = channel;
        std::cout << "TV channel set to " << channel << std::endl;
    }
    
private:
    bool enabled;
    int volume;
    int channel;
};

class Radio : public Device {
public:
    Radio() : enabled(false), volume(50), channel(1) {}
    
    bool isEnabled() const override { return enabled; }
    
    void enable() override {
        enabled = true;
        std::cout << "Radio is enabled" << std::endl;
    }
    
    void disable() override {
        enabled = false;
        std::cout << "Radio is disabled" << std::endl;
    }
    
    int getVolume() const override { return volume; }
    
    void setVolume(int percent) override {
        volume = percent;
        std::cout << "Radio volume set to " << percent << std::endl;
    }
    
    int getChannel() const override { return channel; }
    
    void setChannel(int channel) override {
        this->channel = channel;
        std::cout << "Radio channel set to " << channel << std::endl;
    }
    
private:
    bool enabled;
    int volume;
    int channel;
};

// Abstraction
class Remote {
public:
    Remote(std::shared_ptr<Device> device) : device(device) {}
    
    void togglePower() {
        if (device->isEnabled()) {
            device->disable();
        } else {
            device->enable();
        }
    }
    
    void volumeDown() {
        device->setVolume(device->getVolume() - 10);
    }
    
    void volumeUp() {
        device->setVolume(device->getVolume() + 10);
    }
    
    void channelDown() {
        device->setChannel(device->getChannel() - 1);
    }
    
    void channelUp() {
        device->setChannel(device->getChannel() + 1);
    }
    
protected:
    std::shared_ptr<Device> device;
};

// Refined Abstraction
class AdvancedRemote : public Remote {
public:
    AdvancedRemote(std::shared_ptr<Device> device) : Remote(device) {}
    
    void mute() {
        device->setVolume(0);
    }
};

} // namespace bridge
} // namespace structural 