#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace creational {
namespace factory {

// Product interface
class Notification {
public:
    virtual ~Notification() = default;
    virtual void notifyUser() = 0;
};

// Concrete Product 
class SMSNotification : public Notification {
public:
    void notifyUser() override {
        std::cout << "Sending an SMS notification" << std::endl;
    }
};

class EmailNotification : public Notification {
public:
    void notifyUser() override {
        std::cout << "Sending an email notification" << std::endl;
    }
};

class PushNotification : public Notification {
public:
    void notifyUser() override {
        std::cout << "Sending a push notification" << std::endl;
    }
};

// Creator (Factory) interface
class NotificationFactory {
public:
    virtual ~NotificationFactory() = default;
    virtual std::unique_ptr<Notification> createNotification() = 0;
};

// Concrete Creators
class SMSNotificationFactory : public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<SMSNotification>();
    }
};

class EmailNotificationFactory : public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<EmailNotification>();
    }
};

class PushNotificationFactory : public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<PushNotification>();
    }
};

} // namespace factory
} // namespace creational 
