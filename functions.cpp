#include <iostream>

static int s_Variable; // this variable can only be used in this translation unit (functions.cpp file)
int s_Variable2; // this variable can only be used in this translation unit (functions.cpp file)

int tysAdd (int a, int b)
{
    return a+b;
}

void incrementByOne(int* value){
    (*value)++;
}

void incrementByOneRef(int& value){ // does the the same thing as the function above but uses a reference instead
    value++;
}

void loops() {

    // 3 loops: for, while, do while

    for (int i = 0; i < 5; i++){ // prints hello world 5 times
        std::cout << "Hello world" << std::endl;
    }

    bool condition = true;

    while (condition){ // use while when the condition variable already exists 
        condition = false;
    }

    do { // executes the code atleast once
        std::cout << "Hello world" << std::endl;
    } while (condition);

    // continue goes to the next iteration in the loop
    // break exits the loop
    // return exits the loop and the function

    std::cin.get(); // the console waits for the user to enter a value, it keeps the console open

}

void stringFunction(const std::string& str) // always pass strings as const(if you are't changing it) references, if you pass a class into a function, the program will make a copy of the class, which is expensive
{
    std::cout << str << std::endl;
}


static int nothing(){ // a static function is a function that is only used within a translation unit. Therefore, other files can not reference and use this function
    return 0;
}