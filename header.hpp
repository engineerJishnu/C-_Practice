//
//  header.hpp
//  test
//
//  Created by Jishnu Chakrabarti on 6/14/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//

#ifndef header_hpp
#define header_hpp

#include <stdio.h>
#include <iostream>
#include <thread>
#include <fstream>
#include <chrono>
#include <memory> // smart pointers


void logMessage(const char* message);

/* first time I solved linker problem in template in C++. Due to a weirdness in C++'s compilation model, you cannot separate out .h and .cpp files very cleanly for template functions / classes.Specifically, any translation unit (C++ source file) that wants to use a template class has to have access to the entire template definition. This is a strange quirk of the language, but unfortunately it's here to stay.
 One option is to put the implementation up in the header file rather than in the source. It did worked for me.
 */

template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

void doSomething(int Z);


// A callable object
class thread_obj {
public:
    //void operator()(int x);
    void operator()(int x);
};

class sheep{
public:
    sheep();
    ~sheep();
    void sheepSay(const char* name, int age);
    void intro();
    
private:
    const char* someName;
    int someAge;
};
// inheritance
class poorSheep:public sheep{
    public:
    const char* type;
    int weight;
    void inheritedIntro();
};

class Person {
private:
    const char* p_name;
    int p_age;
    
public:
    Person();
    // No matching constructor for initialization of 'Person'
   // Person(const char* p_name , int p_age);
    ~Person();
    void Display(const char* pName, int pAge);
    void shout();
};


#endif /* header_hpp */
