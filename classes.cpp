#include "classes.h"

Person::Person(){ // called when object is initialized
    test = "";
}

// Person::Person(const std::string initTest) : test(initTest){}

Person::Person(std::string initFirstName, std::string initLastName){ // called when object is initialized
    m_FirstName = initFirstName;
    m_LastName = initLastName;
}

Person::Person(std::string initFirstName, std::string initLastName, int initAge)
    : m_FirstName(initFirstName), m_LastName(initLastName), m_Age(initAge)
{ // the second way to initialize variables, it initializes it in the order it was declared in the class
}

// IMPORTANT: Member initalizer lists (the second way to initialize class variables) are better because it only creates one instance of each member class variable, the first method creates one instance then replaces it. Primitive types do not matter.

Person::~Person(){ // called when the object goes out of scope
    // ex. delete variables/free space on the heap
}

// Getter and Setter Method (methods are functions within a class)

std::string Person::getfirstName() const { // const guarentees that you are not changing any class variables besides variables with the keyword "mutable"
    m_DubugCount++; // a const function can only alter mutable variables
    return m_FirstName;
} // const methods can be called with const objects

void Person::setFirstName(std::string newFirstName) {
    m_FirstName = newFirstName; 
}

std::string Person::getLastName() {
    return m_LastName;
}

void Person::setLastName(std::string newLastName) {
    m_LastName = newLastName; 
}

int Person::getAge() {
    return m_Age;
}

void Person::setAge(int newAge) { // getters and setters allow you to add additional restrictions
    if(newAge > 0 && newAge < 150) {
        m_Age = newAge; 
    }
}

std::string Person::getEmail() {
    return m_Email;
}

void Person::setEmail(std::string newEmail) {
    m_Email = newEmail; 
}