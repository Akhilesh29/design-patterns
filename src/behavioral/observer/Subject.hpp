#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace behavioral {
namespace observer {

// Observer
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

// Subject
class Subject {
public:
    virtual ~Subject() = default;
    
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }
    
    void detach(std::shared_ptr<Observer> observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }
    
    void notify(const std::string& message) {
        for (const auto& observer : observers) {
            observer->update(message);
        }
    }
    
private:
    std::vector<std::shared_ptr<Observer>> observers;
};

// Concrete Subject
class NewsAgency : public Subject {
public:
    void setNews(const std::string& news) {
        this->news = news;
        notify(news);
    }
    
private:
    std::string news;
};

// Concrete Observers
class NewsChannel : public Observer {
public:
    NewsChannel(const std::string& name) : name(name) {}
    
    void update(const std::string& message) override {
        std::cout << name << " received news: " << message << std::endl;
    }
    
private:
    std::string name;
};

} // namespace observer
} // namespace behavioral 