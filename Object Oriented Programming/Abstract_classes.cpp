#include"test.hpp"
class Shape {
public:
    virtual double calculateArea() const = 0;  // Pure virtual function

    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void test_Abstract_classes()
{
    Shape* shape1 = new Rectangle(5, 3);
    Shape* shape2 = new Circle(2.5);

    std::cout << "the area of Rectangle is " << shape1->calculateArea() << std::endl;
    std::cout << "the area of Circle is " << shape2->calculateArea() << std::endl;

    delete shape1;
    delete shape2;


    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();  // Output: "Woof!"
    animal2->makeSound();  // Output: "Meow!"

    delete animal1;
    delete animal2;
}


