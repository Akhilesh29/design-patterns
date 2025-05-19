#pragma once
#include <string>
#include <iostream>

namespace structural {
namespace adapter {

// Target interface
class MediaPlayer {
public:
    virtual ~MediaPlayer() = default;
    virtual void play(const std::string& audioType, const std::string& fileName) = 0;
};

// Adaptee
class AdvancedMediaPlayer {
public:
    virtual ~AdvancedMediaPlayer() = default;
    virtual void playVlc(const std::string& fileName) = 0;
    virtual void playMp4(const std::string& fileName) = 0;
};

class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(const std::string& fileName) override {
        std::cout << "Playing vlc file: " << fileName << std::endl;
    }
    
    void playMp4(const std::string& fileName) override {
        // Do nothing
    }
};

class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(const std::string& fileName) override {
        // Do nothing
    }
    
    void playMp4(const std::string& fileName) override {
        std::cout << "Playing mp4 file: " << fileName << std::endl;
    }
};

// Adapter
class MediaAdapter : public MediaPlayer {
public:
    MediaAdapter(const std::string& audioType) {
        if (audioType == "vlc") {
            advancedMusicPlayer = std::make_unique<VlcPlayer>();
        } else if (audioType == "mp4") {
            advancedMusicPlayer = std::make_unique<Mp4Player>();
        }
    }
    
    void play(const std::string& audioType, const std::string& fileName) override {
        if (audioType == "vlc") {
            advancedMusicPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            advancedMusicPlayer->playMp4(fileName);
        }
    }
    
private:
    std::unique_ptr<AdvancedMediaPlayer> advancedMusicPlayer;
};

// Concrete Target
class AudioPlayer : public MediaPlayer {
public:
    void play(const std::string& audioType, const std::string& fileName) override {
        if (audioType == "mp3") {
            std::cout << "Playing mp3 file: " << fileName << std::endl;
        } else if (audioType == "vlc" || audioType == "mp4") {
            MediaAdapter mediaAdapter(audioType);
            mediaAdapter.play(audioType, fileName);
        } else {
            std::cout << "Invalid media type: " << audioType << std::endl;
        }
    }
};

} // namespace adapter
} // namespace structural 