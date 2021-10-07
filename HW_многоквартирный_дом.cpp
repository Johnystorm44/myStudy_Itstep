#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

class Person {
private:
    char* _firstName;
    char* _secondName;
public:
    Person()
    {
        _firstName = nullptr;
        _secondName = nullptr;
    }
    Person(const char* firstName, const char* secondName)
    {
        _firstName = new char[strlen(firstName) + 1];
        strcpy(_firstName, firstName);
        _secondName = new char[strlen(secondName) + 1];
        strcpy(_secondName, secondName);
    }
    Person(const Person& other) {
        _firstName = new char[strlen(other._firstName) + 1];
        strcpy(_firstName, other._firstName);
        _secondName = new char[strlen(other._secondName) + 1];
        strcpy(_secondName, other._secondName);
    }

    void printHuman() {
        std::cout << _firstName << " " << _secondName << std::endl;
    }

    bool isEqual(const Person* other) {
        if (*_firstName == *other->_firstName && *_secondName == *other->_secondName) {
            return true;
        }
      else {
          return false;
      }
    }  
    ~Person() {
        delete[]_firstName;
        delete[]_secondName;
    }
};

class Apartment {
private:
    int _numberApart; 
    int _numberOfPeople;
    Person* _pPeople;
public:
    Apartment() {
        _numberApart = 0;
        _numberOfPeople = 0;
        _pPeople = new Person[_numberOfPeople];
    }

    Apartment(int numberApart) {
        _numberApart = numberApart;
        _numberOfPeople = 0;
        _pPeople = new Person[_numberOfPeople];
    }
    Apartment(int numberApart, const Person* people, int countOfPeople) : Apartment(numberApart) 
    {
        _numberOfPeople = countOfPeople;
        _pPeople = new Person[_numberOfPeople];
        for (int i = 0; i < countOfPeople; ++i) {
            _pPeople[i] = people[i];
        }
    }
    Apartment(const Apartment& other) {
        _numberApart = other._numberApart;
        _numberOfPeople = other._numberOfPeople;
        _pPeople = new Person[_numberOfPeople];
        for (int i = 0; i < other._numberOfPeople; ++i) {
            _pPeople[i] = other._pPeople[i];
        }
    }
    void printApartment() {
        std::cout << "Apartment number: " << _numberApart << std::endl;
        for (int i = 0; i < _numberOfPeople; ++i) {
            _pPeople[i].printHuman();
        }
    }
    void addPerson(const Person* people) 
    {
        Person* pNewPeople = new Person[_numberOfPeople + 1];
        for (int i = 0; i < _numberOfPeople; ++i) {
            pNewPeople[i] = _pPeople[i];
        }
        pNewPeople[_numberOfPeople] = *people;
        _pPeople = pNewPeople;
        ++_numberOfPeople;
    }
    Person* findPerson(const Person* people) {
        for (int i = 0; i < _numberOfPeople; ++i) {
            if (_pPeople[i].isEqual(people)) {
                return &_pPeople[i];
            }
        }
        std::cout << "Person is not found!!!" << std::endl;
        return nullptr;
    }

    void deletePerson(const Person* people) {
        for (int i = 0; i < _numberOfPeople; ++i) {
            if (_pPeople[i].isEqual(people)) {
                Person* pNewPeople = new Person[_numberOfPeople - 1];
                for (int j = 0; j < i; ++j) {
                    pNewPeople[j] = _pPeople[j];
                }
                for (int z = i; z < _numberOfPeople - 1; ++z) {
                    pNewPeople[z] = _pPeople[z + 1];
                }
                _pPeople = pNewPeople;
                --_numberOfPeople;
            }
        }
    }
};

class House {

private:
    char* _street;
    int _numberStreet;
    int _numberOfApartment;
    Apartment* _pApartment;

public:
    House() {
        _street = nullptr;
        _numberStreet = 0;
        _numberOfApartment = 0;
        Apartment* _pApartment = nullptr;
    }
    House(const char* street, int numberStreet, int numberOfApartment, Apartment* pApartment)
    {
        _street = new char[strlen(street) + 1];
        strcpy(_street, street);
        _numberStreet = numberStreet;
        _numberOfApartment = numberOfApartment;
        Apartment* _pApartment = new Apartment[_numberOfApartment];
        for (int i = 0; i < numberOfApartment; ++i) {
            _pApartment[i] = pApartment[i];
        }
    }
    House(const House& other) {
        _street = new char[strlen(other._street) + 1];
        strcpy(_street, other._street);
        _numberStreet = other._numberStreet;
        _numberOfApartment = other._numberOfApartment;
        _pApartment = new Apartment[_numberOfApartment];
        for (int i = 0; i < _numberOfApartment; ++i)
            _pApartment[i] = other._pApartment[i];
    }
    ~House() {
        delete[]_pApartment;
    }

    void printHouse() {
        std::cout << "Adress : " << _street << " " << _numberStreet << std::endl;
        std::cout << "Number of apartment: " << _numberOfApartment << std::endl;
    }

    Person* findPersonInHouse(const Person* person) {
        for (int i = 0; i < _numberOfApartment; ++i) {
            if (_pApartment[i].findPerson(person) != nullptr) {
                return _pApartment[i].findPerson(person);
            }
        }
        return nullptr;
    }
}; 

int main()
{
    Person human_1("Evgeny", "Ismagilov");
    human_1.printHuman();
    Person human_2("Sergey", "Sergeev");
    human_2.printHuman();
    Person human_3("Julia", "Ismagilova");
    human_3.isEqual(&human_1);
    human_3.printHuman();

    Apartment ap1(66);
    ap1.addPerson(&human_1);
    ap1.printApartment();
    ap1.findPerson(&human_3);
    ap1.deletePerson(&human_1);

    House bulding_1("50 years of October", 7, 9, &ap1);
    bulding_1.printHouse();

    return 0;
}


