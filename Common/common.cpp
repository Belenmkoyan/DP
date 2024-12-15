#include <iostream>
#include <string>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

class ShapeFactory {
public:
    Shape* getShape(const std::string& shapeType) {
        if (shapeType == "Circle") {
            return new Circle();
        } else if (shapeType == "Rectangle") {
            return new Rectangle();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactory shapeFactory;

    Shape* circle = shapeFactory.getShape("Circle");
    if (circle) {
        circle->draw();
        delete circle;
    }

    Shape* rectangle = shapeFactory.getShape("Rectangle");
    if (rectangle) {
        rectangle->draw();
        delete rectangle;
    }

    return 0;
}
