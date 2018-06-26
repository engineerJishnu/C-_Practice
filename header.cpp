//
//  header.cpp
//  test
//
//  Created by Jishnu Chakrabarti on 6/14/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//
#include "header.hpp"

void logMessage(const char* message) {
    std::cout << message << std::endl;
}

//-----------------------------------------
void doSomething(int Z)
{
    for (int i = 0; i < Z; i++) {
        std::cout << "\nThread using function doSomething() as callable." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}
//-----------------------------------------
//void thread_obj::operator()(int x)
void thread_obj:: operator()(int x)
    {
        for (int i = 0; i < x; i++)
            std::cout << "\nThread using function object as  callable." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

//-----------------------------------------
sheep::sheep() {
    logMessage("This is constructor - object has been created");
}

sheep::~sheep(){
    //logMessage("This is destructor - object has been destroyed");
}

void sheep::sheepSay(const char* name, int age){
    // members in this class are private
    someName = name;
    someAge = age;
    std::cout << someName << "  " << someAge << std::endl;
}

void sheep::intro(){
    logMessage("This is the example of simple class pointer in C++....");
}

void poorSheep::inheritedIntro(){
    logMessage("This is the example of simple inherited class in C++....");
}
//-----------------------------------------
void Person::Display(const char* pName, int pAge) {
    p_name = pName;
    p_age = pAge;
    
    std::cout << "the name is " << p_name << " and the age is " << p_age << std::endl;
}

void Person::shout() {
    std::cout << "ooooooooohhhhhhh yeaaaaaaah" << std::endl;
}
 Person::Person() {
     // do nothing
 }

// No matching constructor for initialization of 'Person'
//Person::Person(const char* p_name , int p_age): p_name(0), p_age(0) {
    // do nothing
//}
/*Person::Person(const char* p_name , int p_age): p_name(p_name), p_age(p_age) {
    
}*/
Person::~Person(){
    // do nothing
}

