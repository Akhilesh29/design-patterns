#include "Singleton.hpp"

namespace creational {
namespace singleton {

std::unique_ptr<Singleton> Singleton::instance = nullptr;
std::mutex Singleton::mutex;

Singleton& Singleton::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = std::unique_ptr<Singleton>(new Singleton());
        }
    }
    return *instance;
}

} // namespace singleton
} // namespace creational 