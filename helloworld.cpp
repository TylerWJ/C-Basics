#include <iostream>
#include <array>
#include <string>
#include "functions.h"
#include "classes.h"
#include "log.cpp"

//using namespace std;

#define tyler int; // replaces all 'tyler' with 'int'

class Printable
{
    public:
        virtual std::string GetClassName() = 0;
};

class Entity : public Printable {

    int privVar = 5; // classes default visibility is private

    protected:
        int subVar = 0; // all subclasses have access to this variable


    public:

        static int x, y; // every instance of this struct will have the same x and y value
        static int statVar;


        // virtual vs interface: virtual does not require the subclass to implement its own function to overrise the superclass, if it doesn't, the superclass function will be called instead. However, an interface requires a subclass to override the superclass' function
        virtual void GetName() // virtual creates a VTable, which makes it so that when you point to a SubEntity with an Entity declaration, the system still picks up that it is a SubEntity and calls SubEntity's GetName and not Entity's GetName. Also put, when a pointer of a base class points to an object of the derived class
        // basically virtual ensures that a function is overridden in the subclasses/derived classes
        {
            std::cout << "Entity" << std::endl;
        }

        static void Print() // can be called without an instance. This has to refer to static fields that do not vary based on instance.
        {
            std::cout << x << ", " << y << std::endl;
        }

        std::string GetClassName() override 
        {
            return "Entity";
        }
};  // note that since everything is static, there is no point to having a struct/class


int Entity::x;
int Entity::y; 
int Entity::statVar = 15; // you have to define static variables


class SubEntity : public Entity // dont need to add printable becuase Entity is already a subclass of printable
{
    const char* Name;

    public: 
        SubEntity()
        {
          std::cout << subVar << std::endl;
          subVar = 10;
          std::cout << subVar << std::endl;
          std::cout << statVar << std::endl;
          //privVar = 5;
        }

    void GetName() override
    // override is not requires, only virtual is but it is still good practice to include it 
    {
        std::cout << "SubEntity" << std::endl;
    }

    std::string GetClassName() override 
    {
        return "SubEntity";
    }
};

class IVehicle : public Printable // interface vehicle
{
    virtual void PrintName() = 0; // every class that implements IVehicle is required to implement it's own PrintName function
    //virtual ~IVehicle() = default; // virtual destructor for interface. This is needed when a base class points to a subclass, the declaration can be destructed
};

class Car : public IVehicle
{

    void PrintName() override 
    {
        std::cout << "Car" << std::endl;
    }

    std::string GetClassName() override 
    {
        return "Car";
    }
};

class Truck : public IVehicle
{
    void PrintName() override
    {
        std::cout << "Truck" << std::endl;
    }

    std::string GetClassName() override 
    {
        return "Truck";
    }
};


enum Options : char { // by default, enums are 32 bit integers, but you can change it by using ': char' for only 8 bits
// you can only assign it to integers, you can not assign it a float
    A, B, C // by default, when comparing, A is 0, B is 1, C is 2
    // A = 5, B, C // now by default, A is 5, B is 6, and C is 7
};

void PrintClassName(Printable* obj){
    std::cout << obj->GetClassName() << std::endl;
}

int main() {


    // if you dont return a value in main (and only in the main function) it will assume that the return value is 0

    // a compiler takes each translation unit or cpp file and converts it into an object file with machine code
    // a linker than takes all of these object files and links them together in one executable format


    // IVehicle* v1 = new IVehicle; // can not instantiate an interface
    Car aCar;
    Truck aTruck;

    IVehicle* v1 = new Car;
    IVehicle* v2 = new Truck;

    Entity* e = new Entity;
    SubEntity se; 


    PrintClassName(v1);
    PrintClassName(v2);
    PrintClassName(e);

    //delete v1;
    //delete v2;
    delete e;


    // int d = 5;
    // d++;
    // for (int i = d; i < 10; i++){
    //     cout << d << endl;
    // }

    //int* dPointer = &d;

    // extern int s_Variable1; // this throws an error because s_Variable is static
    extern int s_Variable2; // this pulls s_Variable2 from functions.cpp into helloworld.cpp

    // static outside of classes or struct means that the variable or function can only be used within that translation unit
    // static inside of a class or struct means that the field or method is the same for all instances of that class. 
        //  Static Field: If one instance changes the variable, the change occurs in all other instances as well.
        //  Static Method: The method can be called without an instance of the class, and the method can not refer to a class instance.

    Entity e1;
    e1.x = 1;
    e1.y = 2;
    // or
    Entity::x = 1;
    Entity::y = 2;

    Entity e2;
    e2.x = 3;
    e2.y = 4;
    // or
    Entity::x = 3;
    Entity::y = 4;

    e1.Print();
    e2.Print(); // same result: '3, 4'
    // or
    Entity::Print();

    // Options opt = 1; // error because value is not A, B or C
    Options opt = A; 


    Log log;
    // classes, structs are namespaces; however, enums are not name spaces
    log.SetLevel(Log::LevelInfo);
    log.Warn("Hello");
    log.Error("Hello");    
    log.Info("Hello");

    struct Vector3 {
        float x, y, z;
    };


    // sizeof(bool); // 1 byte
    // sizeof(int); // 4 bytes
    // sizeof(double); // 8 bytes

    // const keyword:

    const int* constPtr1 = new int; 
    // or
    int const* constPtr2 = new int; // cant change the contents of the pointer

    int* const constPtr3 = new int; // cant change the actual pointer

    const int* const constPtr4 = new int; // cant change the contents or the actual pointer


    // array on stack
    int example[5];
    example[0] = 2;
    example[4] = 4;
    // or
    *(example+4) = 4; // +4 is actually +4x4bytes because the poointer is type 'int'

    int count = sizeof(example) / sizeof(int); // 5 - only used for stack allocated arrays

    // better method to keep track of size

    
    static int exampleStat = 5;
    // static int exampleSize = 10; // you cant redefine a static variable
    exampleStat++;

    const int exampleSize = 5;

    for (int i = 0; i < 5; i++){
        static int statTest = 0; // after the first initialization, this line is skipped
        std::cout << statTest << std::endl; // 0, 1, 2, 3, 4
        statTest++;
    }

    // array on heap
    int* anotherEx = new int[exampleSize];


    for (int i=0; i < exampleSize; i++)
    {
        example[i] = 1;
        anotherEx[i] = 1;
    }

    delete[] anotherEx;


    // std lib array
    std::array<int, exampleSize> thirdArray;  // this is the safest option
    thirdArray.size(); // 5


    // strings

    char* name1 = "Tyler";
    const char* name2 = "Tyler"; // const because this is only a pointer with a set amount of memory, you can't append additional characters to it
    std::string name3 = std::string("Hello") + " Tyler";
    // or
    char name4[] = "Tyler";


    std::string name;
    
    std::cout << "Name: " << std::endl;
    std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;

    std::cout << "Characters in name: " << name.length() << std::endl;

    std::cout << "1st number: " << std::endl;
    int a, b;
    std::cin >> a;

    std::cout << "2nd number: " << std::endl;
    std::cin >> b;

    std::cout << "Sum: " << tysAdd(a,b) << std::endl;

    void* ptr = 0;
    void* ptr2 = NULL;
    void* ptr3 = nullptr;

    int var = 4;
    int* varPtr = &var; // this gets the memory address of the variable
    *varPtr = 5; // dereferences and sets a new value to the address stored in varPtr

    int& ref = var; // reference
    std::cout << var << std::endl;  // should be 5
    ref = 6;
    std::cout << var << std::endl;  // should be 6, changes to ref are changes to var because a reference is just a pointer to an already existing variable
    incrementByOne(&var);
    std::cout << var << std::endl;  // should be 7
    incrementByOne(&ref);
    std::cout << var << std::endl;  // should be 8
    incrementByOneRef(var);
    std::cout << var << std::endl;  // should be 9


    char* buffer = new char[8]; // creates a buffer of 8 bytes (each char is 1 byte) and it is pointing to the first char in the buffer
    memset(buffer, 0, 8); // sets all 8 bytes of the memory starting at the buffer pointer to the value 0

    // the new keyword calls a function called malloc (memory allocate)

    char** dptr = &buffer; // creates a double pointer, a pointer to a pointer

    delete[] buffer; // clears the allocated memory

    int value = 5; // allocated on the stack

    int* hvalue = new int; // allocated on the heap
    *hvalue = 5;

    delete hvalue;

    Vector3 vector; // allocated on the stack

    Vector3* hvector = new Vector3; // allocated on the heap

    delete hvector;


    const char* charPtr = "hello";
    std::cout << charPtr << std::endl;


    int array[3]; // the stack stores data consecutively and the pointer simply moves from the top to the bottom
    // for example, if you want to store an int, the pointer moves back 4 bytes (size of an int) and then ocupies that empty space
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;


    int* harray = new int[3];
    harray[0] = 0;
    harray[1] = 1;
    harray[2] = 1;

    delete[] harray;

    Person Tyler;

    Tyler.setFirstName("Tyler");
    Tyler.setLastName("Jones");
    Tyler.setAge(22);
    Tyler.setEmail("tylerwjones99@gmail.com");

    Tyler.test = "test";

    std::cout << Tyler.getfirstName() << std::endl;
    std::cout << Tyler.test << std::endl; 


    // stack memory gets freed after the scope is completed
    // heap memory can only be freed manually; therefore, values stored on the stack are like global variables

    // allocating memory on the stack is like one CPU instruction
    // allocating memory on the heap can be very expensive because the computer has to search existing memory for a free slot. If there isn't, more memory is needed and this is even more expensive

    int speed = 75;
    std::string message;
    if ( speed > 65 ) 
    {
        message = "You are going too fast!!!";
    } else 
    {
        message = "Great job!";
    }

    // Terminary operator
    message = speed > 65 ? "You are going too fast!!!" : "Great job!";

    return 0;
}

