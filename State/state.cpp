#include <iostream>

class FanState {
public:
    virtual void pressButton() = 0;
    virtual ~FanState() {}
};

class Fan;

class OffState : public FanState {
private:
    Fan* fan;
public:
    OffState(Fan* f) : fan(f) {}

    void pressButton() override;
};

class LowState : public FanState {
private:
    Fan* fan;
public:
    LowState(Fan* f) : fan(f) {}

    void pressButton() override;
};

class HighState : public FanState {
private:
    Fan* fan;
public:
    HighState(Fan* f) : fan(f) {}

    void pressButton() override;
};

class Fan {
private:
    FanState* currentState;
public:
    Fan() {
        currentState = new OffState(this);  
    }

    void setState(FanState* state) {
        currentState = state;
    }

    void pressButton() {
        currentState->pressButton();
    }

    ~Fan() {
        delete currentState;
    }
};

void OffState::pressButton() {
    std::cout << "Fan is now on Low speed." << std::endl;
    fan->setState(new LowState(fan));  
    delete this;  
}

void LowState::pressButton() {
    std::cout << "Fan is now on High speed." << std::endl;
    fan->setState(new HighState(fan));  
    delete this;  
}

void HighState::pressButton() {
    std::cout << "Fan is now off." << std::endl;
    fan->setState(new OffState(fan));  
    delete this; 
}

int main() {
    Fan fan;

    fan.pressButton(); 
    fan.pressButton(); 
    fan.pressButton(); 
    fan.pressButton(); 

    return 0;
}
