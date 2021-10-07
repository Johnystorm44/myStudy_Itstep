#include <iostream>
#include <string.h>

class Pet {

protected:
    std::string _name;
    int _age;
    std::string _breed;
public:
    Pet(std::string name, int age, std::string breed) : 
        _name{name}, _age{age}, _breed{breed} 
    {}

    virtual void showPet() = 0;
};

class Dog : public Pet {
private :
    double _length;
    double _weight;
public:
    Dog(std::string name, int age, std::string breed, double length, double weight) : 
        Pet(name, age, breed), _length {length}, _weight {weight} {}
    void showPet() {
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Age: " << _age << std::endl;
        std::cout << "Breed: " << _breed << std::endl;
        std::cout << "Length: " << _length << std::endl;
        std::cout << "Weight: " << _weight << std::endl;
     }
};

class Cat : public Pet {
private:
    std::string _hairColor;
    double _lengthTail;
public:
    Cat(std::string name, int age, std::string breed, std::string hairColor, double lengthTail) 
        : Pet(name, age, breed), _hairColor{hairColor}, _lengthTail{lengthTail}
    {}
    void showPet() {
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Age: " << _age << std::endl;
        std::cout << "Breed: " << _breed << std::endl;
        std::cout << "Hair Color: " << _hairColor << std::endl;
        std::cout << "Length of tail: " << _lengthTail << std::endl;
    }
};

class Parrot : public Pet {
private:
    std::string _color;
    int _lengthBeak;
public:
    Parrot(std::string name, int age, std::string breed,std::string color, int lengthBeak) 
        : Pet(name, age, breed), _color{color}, _lengthBeak{lengthBeak}
    {}
    void showPet() {
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Age: " << _age << std::endl;
        std::cout << "Breed: " << _breed << std::endl;
        std::cout << "Color: " << _color << std::endl;
        std::cout << "Length of beak: " << _lengthBeak << std::endl;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");

    Dog Ray("Рей", 7, "Стаффордширский терьер", 30, 90);
    Ray.showPet();
    std::cout << std::endl;
    Cat Timofey("Тимофей", 3, "Британец", "Серый", 27);
    Timofey.showPet();
    std::cout << std::endl;
    Parrot Kesha("Кеша", 5, "Волнистый попугай", "Белый", 3);
    Kesha.showPet();
    std::cout << std::endl;

    return 0;
}


