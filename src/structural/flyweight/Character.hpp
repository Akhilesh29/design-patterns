#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>

namespace structural {
namespace flyweight {

// Flyweight
class Character {
public:
    virtual ~Character() = default;
    virtual void display(int fontSize) = 0;
};

// Concrete Flyweight
class CharacterImpl : public Character {
public:
    CharacterImpl(char symbol) : symbol(symbol) {}
    
    void display(int fontSize) override {
        std::cout << "Character: " << symbol << ", Font Size: " << fontSize << std::endl;
    }
    
private:
    char symbol;
};

// Flyweight Factory
class CharacterFactory {
public:
    std::shared_ptr<Character> getCharacter(char key) {
        auto it = characters.find(key);
        if (it == characters.end()) {
            characters[key] = std::make_shared<CharacterImpl>(key);
            return characters[key];
        }
        return it->second;
    }
    
private:
    std::unordered_map<char, std::shared_ptr<Character>> characters;
};

// Client
class TextEditor {
public:
    void addCharacter(char c, int fontSize) {
        auto character = factory.getCharacter(c);
        character->display(fontSize);
    }
    
private:
    CharacterFactory factory;
};

} // namespace flyweight
} // namespace structural 