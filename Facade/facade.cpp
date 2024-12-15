#include <iostream>

class LightingSystem{
    public:
        void turnOn(){
            std::cout<< "Turns the lights on"<<std::endl;
        }

        void turnOff(){
            std::cout<< "Turns the lights off"<<std::endl;
        }

};
class AirConditioningSystem {
    public:
        void turnOn(){
            std::cout<< "Turns the air conditioner on"<<std::endl;
        }

        void turnOff(){
            std::cout<< "Turns the air conditioner off"<<std::endl;
        }

};
class SecuritySystem {
    public:
        void activate(){
            std::cout<< "Security System is activate"<<std::endl;
        }

        void desactivate(){
            std::cout<< "Security System is desactivate"<<std::endl;
        }

};
class EntertainmentSystem {
    public:
        void turn_TV_on(){
            std::cout<< "Turns TV on"<<std::endl;
        }

        void turn_TV_off(){
            std::cout<< "Turns TV off"<<std::endl;
        }

};

class SmartHomeFacade {
private:
    LightingSystem lighting;
    AirConditioningSystem airConditioning;
    SecuritySystem security;
    EntertainmentSystem entertainment;

public:
    void activateGoodMorningMode() {
        std::cout << "Activating Morning Mode"<<std::endl;
        lighting.turnOn();
        airConditioning.turnOn();
        security.desactivate();
        entertainment.turn_TV_on();
    }

    void activateNightMode() {
        std::cout << "Activating Night Mode"<<std::endl;
        lighting.turnOff();
        security.activate();
        entertainment.turn_TV_off();
    }
};

int main() {
    SmartHomeFacade smartHome;

    std::cout << "User selects Morning Mode"<<std::endl;
    smartHome.activateGoodMorningMode();

    std::cout << "User selects Night Mode"<<std::endl;
    smartHome.activateNightMode();

    return 0;
}


