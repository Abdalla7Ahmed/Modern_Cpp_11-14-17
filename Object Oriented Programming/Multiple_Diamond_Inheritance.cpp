#include"test.hpp"

class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

class Mammal : virtual public Animal {
public:
    void move() {
        std::cout << "Mammal is moving." << std::endl;
    }
};

class Bird : virtual public Animal {
public:
    void fly() {
        std::cout << "Bird is flying." << std::endl;
    }
};

class Bat : public Mammal, public Bird {
public:
    void sleep() {
        std::cout << "Bat is sleeping." << std::endl;
    }
};

void test_Multiple_Diamond_Inheritance()
{
    Bat bat;
    bat.eat();   // Output: "Animal is eating."
    bat.move();  // Output: "Mammal is moving."
    bat.fly();   // Output: "Bird is flying."
    bat.sleep(); // Output: "Bat is sleeping."

}