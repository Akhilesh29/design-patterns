#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace behavioral {
namespace memento {

// Memento
class EditorMemento {
public:
    EditorMemento(const std::string& content) : content(content) {}
    
    std::string getContent() const {
        return content;
    }
    
private:
    std::string content;
};

// Originator
class Editor {
public:
    void setContent(const std::string& content) {
        this->content = content;
    }
    
    std::string getContent() const {
        return content;
    }
    
    std::shared_ptr<EditorMemento> createMemento() {
        return std::make_shared<EditorMemento>(content);
    }
    
    void restore(std::shared_ptr<EditorMemento> memento) {
        content = memento->getContent();
    }
    
private:
    std::string content;
};

// Caretaker
class History {
public:
    void push(std::shared_ptr<EditorMemento> memento) {
        mementos.push_back(memento);
    }
    
    std::shared_ptr<EditorMemento> pop() {
        if (mementos.empty()) {
            return nullptr;
        }
        auto memento = mementos.back();
        mementos.pop_back();
        return memento;
    }
    
private:
    std::vector<std::shared_ptr<EditorMemento>> mementos;
};

} // namespace memento
} // namespace behavioral 