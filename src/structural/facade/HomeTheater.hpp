#pragma once
#include <string>
#include <iostream>

namespace structural {
namespace facade {

// Subsystem classes
class Amplifier {
public:
    void on() {
        std::cout << "Amplifier is on" << std::endl;
    }
    
    void off() {
        std::cout << "Amplifier is off" << std::endl;
    }
    
    void setVolume(int level) {
        std::cout << "Amplifier volume set to " << level << std::endl;
    }
};

class Tuner {
public:
    void on() {
        std::cout << "Tuner is on" << std::endl;
    }
    
    void off() {
        std::cout << "Tuner is off" << std::endl;
    }
    
    void setFrequency(double frequency) {
        std::cout << "Tuner frequency set to " << frequency << std::endl;
    }
};

class DvdPlayer {
public:
    void on() {
        std::cout << "DVD Player is on" << std::endl;
    }
    
    void off() {
        std::cout << "DVD Player is off" << std::endl;
    }
    
    void play(const std::string& movie) {
        std::cout << "DVD Player playing " << movie << std::endl;
    }
    
    void stop() {
        std::cout << "DVD Player stopped" << std::endl;
    }
};

class Projector {
public:
    void on() {
        std::cout << "Projector is on" << std::endl;
    }
    
    void off() {
        std::cout << "Projector is off" << std::endl;
    }
    
    void setInput(const std::string& input) {
        std::cout << "Projector input set to " << input << std::endl;
    }
};

class Screen {
public:
    void up() {
        std::cout << "Screen is up" << std::endl;
    }
    
    void down() {
        std::cout << "Screen is down" << std::endl;
    }
};

class TheaterLights {
public:
    void on() {
        std::cout << "Theater lights are on" << std::endl;
    }
    
    void off() {
        std::cout << "Theater lights are off" << std::endl;
    }
    
    void dim(int level) {
        std::cout << "Theater lights dimmed to " << level << "%" << std::endl;
    }
};

// Facade
class HomeTheaterFacade {
public:
    HomeTheaterFacade(
        Amplifier& amp,
        Tuner& tuner,
        DvdPlayer& dvd,
        Projector& projector,
        Screen& screen,
        TheaterLights& lights
    ) : amp(amp), tuner(tuner), dvd(dvd),
        projector(projector), screen(screen), lights(lights) {}
    
    void watchMovie(const std::string& movie) {
        std::cout << "Get ready to watch a movie..." << std::endl;
        lights.dim(10);
        screen.down();
        projector.on();
        projector.setInput("DVD");
        amp.on();
        amp.setVolume(5);
        dvd.on();
        dvd.play(movie);
    }
    
    void endMovie() {
        std::cout << "Shutting down the home theater..." << std::endl;
        dvd.stop();
        dvd.off();
        amp.off();
        projector.off();
        screen.up();
        lights.on();
    }
    
private:
    Amplifier& amp;
    Tuner& tuner;
    DvdPlayer& dvd;
    Projector& projector;
    Screen& screen;
    TheaterLights& lights;
};

} // namespace facade
} // namespace structural 