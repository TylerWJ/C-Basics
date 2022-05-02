#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class Person {
    public: 

        // Constructor
        Person();
        Person(std::string initFirstName, std::string initLastName);
        Person(std::string initFirstName, std::string initLastName, int initAge);

        // Destructor
        ~Person();

        // Public test variable
        std::string test;
        
        // First Name
        std::string getfirstName() const;
        void setFirstName(std::string newFirstName);

        // Last Name 
        std::string getLastName();
        void setLastName(std::string newLastName);

        // Age
        int getAge();
        void setAge(int newAge);

        // Email
        std::string getEmail();
        void setEmail(std::string newEmail);

    private: // this is the default

        std::string m_FirstName;
        std::string m_LastName;
        int m_Age;
        std::string m_Email;
        mutable int m_DubugCount; // const classes can change this variable

};

#endif