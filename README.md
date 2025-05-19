# Design Patterns in C++

Welcome to our comprehensive guide on Design Patterns in C++! This repository demonstrates various design patterns through practical examples. Let's explore them by category.

## Creational Patterns

### Singleton Pattern
The Singleton pattern ensures a class has only one instance and provides a global point of access to it. Perfect for managing shared resources like database connections or configuration settings.

```cpp
Singleton& instance = Singleton::getInstance();
```

### Factory Method Pattern
The Factory Method pattern defines an interface for creating objects but lets subclasses decide which class to instantiate. Great for creating different types of notifications (SMS, Email, Push).

```cpp
auto notification = factory->createNotification();
```

### Abstract Factory Pattern
The Abstract Factory pattern provides an interface for creating families of related objects without specifying their concrete classes. Demonstrated through computer component creation (Windows vs Mac).

```cpp
auto cpu = factory->createCPU();
auto ram = factory->createRAM();
```

### Builder Pattern
The Builder pattern separates the construction of a complex object from its representation. Used here to build computer configurations step by step.

```cpp
Computer computer = Computer::Builder()
    .setCPU("Intel i7")
    .setRAM("16GB")
    .setStorage("1TB SSD")
    .build();
```

### Prototype Pattern
The Prototype pattern creates new objects by cloning an existing object. Perfect for creating copies of shapes with different properties.

```cpp
auto newShape = shape->clone();
```

## Structural Patterns

### Adapter Pattern
The Adapter pattern allows incompatible interfaces to work together. Demonstrated through a media player that can play different formats.

```cpp
mediaPlayer->play("mp4", "movie.mp4");
```

### Bridge Pattern
The Bridge pattern decouples an abstraction from its implementation. Shown through a remote control system for different devices.

```cpp
Remote remote(device);
remote.togglePower();
```

### Composite Pattern
The Composite pattern composes objects into tree structures. Implemented as a file system with files and directories.

```cpp
directory->add(file);
directory->display();
```

### Decorator Pattern
The Decorator pattern attaches additional responsibilities to objects dynamically. Used to create different coffee combinations.

```cpp
auto coffee = std::make_shared<MilkDecorator>(
    std::make_shared<SugarDecorator>(
        std::make_shared<SimpleCoffee>()
    )
);
```

### Facade Pattern
The Facade pattern provides a simplified interface to a complex subsystem. Demonstrated through a home theater system.

```cpp
homeTheater.watchMovie("Inception");
```

### Flyweight Pattern
The Flyweight pattern minimizes memory usage by sharing data. Used in a text editor to manage character rendering.

```cpp
textEditor.addCharacter('A', 12);
```

### Proxy Pattern
The Proxy pattern provides a surrogate for another object. Shown through lazy loading of images.

```cpp
image->display(); // Loads only when needed
```

## Behavioral Patterns

### Chain of Responsibility Pattern
The Chain of Responsibility pattern passes a request along a chain of handlers. Implemented as a logging system.

```cpp
logger->log("Error message", ERROR_LEVEL);
```

### Command Pattern
The Command pattern encapsulates a request as an object. Used in a remote control system.

```cpp
remoteControl.setCommand(command);
remoteControl.pressButton();
```

### Interpreter Pattern
The Interpreter pattern defines a grammar and interprets sentences in that language. Shown through a simple expression evaluator.

```cpp
expression->interpret(context);
```

### Iterator Pattern
The Iterator pattern provides a way to access elements of a collection sequentially. Demonstrated with a vector iterator.

```cpp
while (iterator.hasNext()) {
    auto item = iterator.next();
}
```

### Mediator Pattern
The Mediator pattern defines an object that encapsulates how objects interact. Implemented as a chat room.

```cpp
user->sendMessage("Hello!");
```

### Memento Pattern
The Memento pattern captures and restores an object's internal state. Used in a text editor for undo functionality.

```cpp
history.push(editor.createMemento());
```

### Observer Pattern
The Observer pattern defines a one-to-many dependency between objects. Demonstrated through a news agency system.

```cpp
newsAgency.attach(observer);
newsAgency.setNews("Breaking news!");
```

## Getting Started

1. Clone the repository
2. Build using CMake:
```bash
mkdir build
cd build
cmake ..
make
```

## Contributing

Feel free to contribute by:
1. Forking the repository
2. Creating a feature branch
3. Submitting a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details. 