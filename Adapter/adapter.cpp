#include <iostream>

class mediaPlayer {
public:
    virtual void play() = 0;
};

class playerMP3 : mediaPlayer {
public:
    void play() override {
        std::cout<< "play MP3"<<std::endl;
    }
} ;

class PlayerMP4 {
public:
    void playMP4(){
        std::cout<< "play MP4"<<std::endl;
    }
};

class adapter : mediaPlayer{
public:
    adapter(PlayerMP4 player){
        mp4 = player;

    };
    void play() override {
        mp4.playMP4();
    }
private:
    PlayerMP4 mp4;


};

int main(){
    playerMP3 p1;
    PlayerMP4 p2;
    p1.play();
    
    adapter a(p2);
    a.play();

    return 0;

}
