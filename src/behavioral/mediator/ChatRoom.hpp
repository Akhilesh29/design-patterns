#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace behavioral {
namespace mediator {

// Colleague
class User {
public:
    User(const std::string& name) : name(name) {}
    
    virtual ~User() = default;
    virtual void sendMessage(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& message) = 0;
    
protected:
    std::string name;
};

// Concrete Colleague
class ChatUser : public User {
public:
    ChatUser(const std::string& name, class ChatRoom* chatRoom)
        : User(name), chatRoom(chatRoom) {}
    
    void sendMessage(const std::string& message) override;
    void receiveMessage(const std::string& message) override;
    
private:
    class ChatRoom* chatRoom;
};

// Mediator
class ChatRoom {
public:
    void addUser(std::shared_ptr<ChatUser> user) {
        users.push_back(user);
    }
    
    void sendMessage(const std::string& message, const std::string& sender) {
        for (const auto& user : users) {
            if (user->name != sender) {
                user->receiveMessage(sender + ": " + message);
            }
        }
    }
    
private:
    std::vector<std::shared_ptr<ChatUser>> users;
};

// Implementation of ChatUser methods
void ChatUser::sendMessage(const std::string& message) {
    chatRoom->sendMessage(message, name);
}

void ChatUser::receiveMessage(const std::string& message) {
    std::cout << name << " received: " << message << std::endl;
}

} // namespace mediator
} // namespace behavioral 