#include <iostream>
#include <memory>
#include <string>
// Component interface
class Coffee {
    public:
        virtual double cost() const = 0 ;
        virtual std::string description() const = 0;
        virtual ~Coffee() = default;
};
// Concrete Component: Basic Notifier 
class Espresso : public Coffee {
    public:
        double cost() const override{
                return 1.50;
        }

        std::string description() const override {
            return "Espresso"; 
        }
};

class Latte : public Coffee {
    public:
        double cost() const override {
            return 2.50;
        }

        std::string description() const override{
            return "Latte";
        }
};
// Abstract Decorator
class CoffeeDecorator : public Coffee {
    protected:
        std::shared_ptr<Coffee> wrappedCoffee;
    public:
    explicit CoffeeDecorator(std::shared_ptr<Coffee> coffee) 
        : wrappedCoffee(std::move(coffee)) {}

    double cost() const override {
        return wrappedCoffee->cost();
    }

    std::string description() const override{
        return wrappedCoffee->description();
    }
};
class MilkCoffee : public CoffeeDecorator {
    public:
        explicit MilkCoffee(std::shared_ptr<Coffee> coffee) :
        CoffeeDecorator(std::move(coffee)){}

        double cost() const override {
        return wrappedCoffee->cost() + 0.50;
    }

    std::string description() const override {
        return wrappedCoffee->description() + ", Milk"; 
    }

};

int main() {
    std::shared_ptr<Coffee> myCoffee = std::make_shared<Espresso>();

    myCoffee = std::make_shared<MilkCoffee>(myCoffee); 

    std::cout << "Your order: " << myCoffee->description() << std::endl;
    std::cout << "Total cost: $" << myCoffee->cost() << std::endl;

    return 0;
}

