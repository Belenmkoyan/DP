#include <iostream>
#include <vector>

class Shape {
    public:
        Shape(int x, int y) {
            this->x = x;
            this->y = y;
        }
        virtual void move(int x, int y) {
            this->x = x;
            this->y = y;
            std::cout << "Shape moved to (" << x << ", " << y << ")\n";
        }
        virtual ~Shape() = default;

    private:
        int x, y;
};

class Circle : public Shape { 
    public:
        Circle(int x, int y, int radius) : Shape(x, y) {
            this->radius = radius;
        }
    private:
        int radius;
};

class Rectangle : public Shape {
    public:
        Rectangle(int x, int y, int height, int width) : Shape(x, y) {
            this->height = height;
            this->width = width;
        }
    private:
        int height, width;
};

class CompositeGroup : public Shape { 
    private:
        std::vector<Shape*> shapes;
    public:
        CompositeGroup(int x, int y) : Shape(x, y) {}

        void addShape(Shape* shape) {
            shapes.push_back(shape);
        }

        void move(int x, int y) override {
            std::cout << "Moving composite group to (" << x << ", " << y << ")\n";
            for (auto& shape : shapes) {
                shape->move(x, y);
            }
        }
};

int main() {
    Circle* circle1 = new Circle(10, 10, 5);
    Rectangle* rectangle1 = new Rectangle(20, 20, 30, 40);


    CompositeGroup* group = new CompositeGroup(0, 0);
    group->addShape(circle1);
    group->addShape(rectangle1);

    group->move(100, 200);

    delete circle1;
    delete rectangle1;
    delete group;

    return 0;
}
