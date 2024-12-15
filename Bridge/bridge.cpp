#include <iostream>

class Color {
    public:
        virtual void applyColor() = 0;
        virtual ~Color() = default;
};

class RedColor : public Color{
    public:
        void applyColor() override {
            std::cout<< "Red"<< std::endl;
        }
};

class BlueColor :public Color {
    public:
        void applyColor() override {
            std::cout<< "Blue"<< std::endl;
        }
};

class Shape {
    protected:
        Color* color;
    public:
        Shape(Color* c) : color(c){}
        virtual ~Shape(){
            delete color;
        }

        virtual void draw () = 0 ;

        void changeColor(Color* newColor) {
            delete color;  
            color = newColor;
        }

};

class Circle : public Shape {
public:
    Circle(Color* c) : Shape(c) {}

    void draw() override {
        std::cout << "Drawing a Circle. ";
        color->applyColor();
    }
};

class Rectangle : public Shape {
public:
    Rectangle(Color* c) : Shape(c) {}

    void draw() override {
        std::cout << "Drawing a Rectangle. ";
        color->applyColor();
    }
};

int main() {
    Shape* circle = new Circle(new RedColor());
    Shape* rectangle = new Rectangle(new BlueColor());

    circle->draw();       
    rectangle->draw();  

    circle->changeColor(new BlueColor());
    circle->draw();   
    
    rectangle->changeColor(new RedColor());
    rectangle->draw();       

    delete circle;
    delete rectangle;

    return 0;
}
