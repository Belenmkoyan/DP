#include<iostream>
class Handler {
protected:
    Handler* nextHandler; 

public:
    Handler() : nextHandler(nullptr) {}

    void setNextHandler(Handler* next) {
        nextHandler = next;
    }

    virtual void handleRequest(const std::string& request) = 0;

    virtual ~Handler() {}
};

class BasicSupport : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "password reset") {
            std::cout << "Basic Support: Handled the request - " << request << std::endl;
        } else if (nextHandler) {
            std::cout << "Basic Support: Passing to next handler."<< std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "Basic Support: Cannot handle the request."<< std::endl;
        }
    }
};
class TechnicalSupport : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "system crash") {
            std::cout << "Technical Support: Handled the request - " << request << std::endl;
        } else if (nextHandler) {
            std::cout << "Technical Support: Passing to next handler."<< std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "Technical Support: Cannot handle the request."<< std::endl;
        }
    }
};

int main() {
    BasicSupport basic;
    TechnicalSupport technical;

    basic.setNextHandler(&technical);

    basic.handleRequest("password reset");
    basic.handleRequest("system crash");
    basic.handleRequest("billing issue");

    return 0;
}
