// home_work_наследование_персона.cpp 

#include <iostream>
#include <string>


class Person {
protected:
    std::string _fio;
    int _age;

public:
    Person() {}

    Person(std::string fio, int age) :
    _fio {fio} , _age{age}
    {}

    std::string getFio() {
        return _fio;
    }

    int getAge() const {
        return _age;
    }
    
    ~Person(){}
};

class Student : public Person {

private:
    int _numGroup;
    int _course;

public:
    Student() {}
    Student(std::string fio, int age, int numGroup, int course) :
        Person{ fio, age },
        _numGroup{ numGroup },
        _course { course }
    {}

    int getNumGroup() const {
        return _numGroup;
    }

    int getGroup() const {
        return _course;
    }

    friend std::istream& operator>> (std::istream& in, Student& stud);
    friend std::ostream& operator<< (std::ostream& out, const Student& stud);

    ~Student() {}
};

class Teacher : public Person {
private:
    std::string _schoolSub;

public:
    Teacher() {}
    Teacher(std::string fio, int age, std::string schoolSub) : Person {fio, age}, 
        _schoolSub{ schoolSub } {}
    
    std::string getSchoolSub() {
        return _schoolSub;
    }
    friend std::istream& operator>>(std::istream& in, Teacher& teach);
    friend std::ostream& operator<< (std::ostream& out, const Teacher& teach);
    
    ~Teacher() {}
};

std::istream& operator>> (std::istream& in, Teacher& teach) {
    in >> teach._fio;
    in >> teach._age;
    in >> teach._schoolSub;

    return in;
}
std::istream& operator>> (std::istream& in, Student& stud) {
    in >> stud._fio;
    in >> stud._age;
    in >> stud._numGroup;
    in >> stud._course;

    return in;
}

std::ostream& operator<< (std::ostream& out, const Teacher& teach) {
    out << "Teacher: FIO - " << teach._fio << std::endl << "Age - " << teach._age << std::endl
        << "School Subject - " << teach._schoolSub << std::endl;

    return out;
}
std::ostream& operator<< (std::ostream& out, const Student& stud) {
    out << "Student: FIO - " << stud._fio << std::endl << "Age - " << stud._age << std::endl
        << "Number of Group - " << stud._numGroup << std::endl << "Course - " << stud._course
        << std::endl;

    return out;
}
int main()
{
    const int SIZE = 2;
    std::cout << "Create list of students " << std::endl;

    Student* arrStud = new Student[SIZE];

    int countStud = 2;
    int countTeach = 2;

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter students name, age, group number and course : " << std::endl;
        std::cin >> arrStud[i];
        countStud--;
        std::cout << "Remains to enter student " << countStud << std::endl;
    }

    for (int j = 0; j < SIZE; ++j) {
        std::cout << arrStud[j];
    }

    std::cout << std::endl;
    std::cout << std::endl;

    Teacher* arrTeach = new Teacher[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter teachers name, age and name of subject : " << std::endl;
        std::cin >> arrTeach[i];
        countTeach--;
        std::cout << "Remains to enter teachers " << countTeach << std::endl;
    }

    std::cout << std::endl;

    for (int j = 0; j < SIZE; ++j) {
        std::cout << arrTeach[j];
    }
    

    delete[] arrStud;
    delete[] arrTeach;

    return 0;
}

