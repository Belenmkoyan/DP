#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Singleton instance in use!" << std::endl;
    }
};


Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getInstance();
    s2->showMessage();

    if (s1 == s2) {
        std::cout << "Both are the same instance." << std::endl;
    }

    return 0;
}
