#pragma once
#include <vector>
#include <memory>
#include <iostream>

namespace behavioral {
namespace iterator {

// Iterator interface

template<typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// Concrete Iterator
template<typename T>
class VectorIterator : public Iterator<T> {
public:
    VectorIterator(const std::vector<T>& items) : items(items), position(0) {}
    
    bool hasNext() const override {
        return position < items.size();
    }
    
    T next() override {
        if (hasNext()) {
            return items[position++];
        }
        throw std::runtime_error("No more elements");
    }
    
private:
    const std::vector<T>& items;
    size_t position;
};

// Aggregate interface
template<typename T>
class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual std::unique_ptr<Iterator<T>> createIterator() = 0;
};

// Concrete Aggregate
template<typename T>
class VectorAggregate : public Aggregate<T> {
public:
    void add(const T& item) {
        items.push_back(item);
    }
    
    std::unique_ptr<Iterator<T>> createIterator() override {
        return std::make_unique<VectorIterator<T>>(items);
    }
    
private:
    std::vector<T> items;
};

} // namespace iterator
} // namespace behavioral 
