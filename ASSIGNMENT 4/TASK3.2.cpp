#include <iostream>
#include <string>
using namespace std;
class Address {
string city;
public:
Address(string c) : city(c) {
cout << "Address ";
}
};
class Person {
protected:
string name;
Address home;

public:
Person(string n, string c)
: name(n), home(c) {
cout << "Person ";
}
};
class Course {
string courseName;
public:
Course(string c) : courseName(c) {
cout << "Course ";
}
};
class Student : public Person {
Course course;
public:
Student(string n, string a, string c)
: Person(n, a), course(c) {
cout << "Student ";
}
};
int main() {
Student s("Kavi", "Salem", "C++");
}
