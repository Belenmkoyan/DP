#include <iostream>
#include <string>

class House {
public:
    std::string foundation;
    std::string structure;
    std::string roof;
    std::string interior;

    void show() const {
        std::cout << "Foundation: " << foundation << std::endl;
        std::cout << "Structure: " << structure << std::endl;
        std::cout << "Roof: " << roof << std::endl;
        std::cout << "Interior: " << interior << std::endl;
    }
};

class HouseBuilder {
public:
    virtual ~HouseBuilder() {}
    virtual HouseBuilder* buildFoundation() = 0;
    virtual HouseBuilder* buildStructure() = 0;
    virtual HouseBuilder* buildRoof() = 0;
    virtual HouseBuilder* buildInterior() = 0;
    virtual House* getHouse() = 0;
};

class ConcreteHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    ConcreteHouseBuilder() { house = new House(); }

    HouseBuilder* buildFoundation() override {
        house->foundation = "Concrete foundation";
        return this; 
    }

    HouseBuilder* buildStructure() override {
        house->structure = "Wooden structure";
        return this;
    }

    HouseBuilder* buildRoof() override {
        house->roof = "Tile roof";
        return this;
    }

    HouseBuilder* buildInterior() override {
        house->interior = "Drywall and paint interior";
        return this;
    }

    House* getHouse() override {
        return house;
    }
};

class Director {
private:
    HouseBuilder* builder;
public:
    Director(HouseBuilder* b) : builder(b) {}

    void constructHouse() {
        builder->buildFoundation()
               ->buildStructure()
               ->buildRoof()
               ->buildInterior();
    }
};

int main() {
    HouseBuilder* builder = new ConcreteHouseBuilder();
    Director director(builder);
    director.constructHouse(); 

    House* house = builder->getHouse();
    std::cout << "House built:\n";
    house->show();  

    delete house;
    delete builder;

    return 0;
}
