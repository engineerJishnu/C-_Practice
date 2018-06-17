//main.cpp
//  test
//
//  Created by Jishnu Chakrabarti on 6/14/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//
#include "header.hpp"

/*template <typename T>
void print(T value) {
    std::cout << value << std::endl;
} */

int main() {
    // insert code here...
    //system("clear");
    //--------------welcome message--------------------------
    logMessage("Hello World! Welcome to the C++ programming in MacBook Air");
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    // lamda functions
    [](){ logMessage("Bjarne you are chutia and its coming from lamda - anonymous function");}();
    //-----------------lamda with reference-------------------
    int a;
    logMessage("Please enter any number...and press ENTER key");
    std::cin >> a;
    
    /* here I want to check whether the operator has entered number or not.
    if not, then it will display that please enter a valid number
     */
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "\nBad entry. Please enter a NUMBER: " << std::endl;
        std::cin >> a;
    }
    std::cout << "You have entered = " << a << std::endl;
    [&a]() {
        int count = 0;
        while(count < 10){
            a++;
            std::cout << "The incremental value i++ = " << a << std::endl;
            count++;
            // unistd not available and hence usleep() doesnt works here.
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        }();
    /*---------------------writing the text to a txt file------------------------
    std::ofstream file("file.txt");
    here what happened is that the file.txt was created and string was copied in it. but unfortunately
     I couldn't find the location of the txt file. hence I gave the path where I wish the txt file to be created.
    */
    std::ofstream file("/Users/jishnuchakrabarti/Documents/c++/test/test/file.txt");
    
    file << "Hello, world! Welcome to C++ programming." << std::endl;
     //--------------------templates created in header file.---------------------
    logMessage("examples of the Template");
    print("Bjarne Tumi ekta gadha");
    print(420);
    print(3.14f);
    
    //-----------------------multi threading examples-----------------------------
    logMessage("CPP program to demonstrate multithreading using three different callables");
    logMessage("Threads 1, 2 and 3 operating independently.\n");
    
    // This thread is launched by using function pointer as callable
    std::thread th1(doSomething, 3);
    
    // This thread is launched by using function object as callable
    // std::thread th2(thread_obj(),2);
    std::thread th2(thread_obj(),3);
    
    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            std::cout << std::this_thread::get_id() << " Thread using lambda expression as callable " << i+1 << " times.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    };
    
    // This thread is launched by using lamda expression as callable
    std::thread th3(f,3);
    
    // Wait for thread t1 to finish
    th1.join();
    
    // Wait for thread t2 to finish
    th2.join();
    
    // Wait for thread t3 to finish
    th3.join();
    //-------------------object oriented programming using simple class sheep with private members
    sheep object1;
    object1.intro();
    object1.sheepSay("Bjarne ", 6);
    
    poorSheep inheritedObj1;
    inheritedObj1.inheritedIntro();
    inheritedObj1.sheepSay("Inherited Class = jishnu", 10);
    
    //----------------------pointers & DMM------------------------
    int number = 100;
    int *pnumber = NULL;
    pnumber = &number;
    
    std::cout << "the simple pointer...." << std::endl;
    std::cout << "The number = " << number << "\nThe address of number = " << &number << "\nThe content of *pnumber = " << *pnumber << std::endl;
    std::cout << "The new & delete keyword..." << std::endl;
    int *newPointer = new int(500); // new type(parameter)
    std::cout << "The value of the newPointer = new int(500) = " << *newPointer << std::endl;
    std:: cout << "before ending the program we need to free the memory by using keyword delete" << std::endl;
    delete newPointer; // not "*newPointer" as we are freeing the memory address.
    
    std::cout << "The small step to smart pointer using shared pointer keyword. here we have use #include <memory> in the header." << std::endl;
    
    std::shared_ptr<int> smartPointer(new int(1000));
    std::cout << "The value of smartPointer which is shared one of type int is " << *smartPointer << std::endl;
    // "*smartPointer" will give the value i.e. content of whereas "smartPointer" will give the address.
    
    // incase of you are not initializing smart pointer later.....
    std::shared_ptr<int> smartpointer2;
    smartpointer2.reset(new int(500));
    std::cout << "The value of smartpointer which is shared one of type int and initialized later using .reset " << *smartpointer2 << std::endl;
    
    std::shared_ptr<double> sharedptr1(new double(3.14));
    std::shared_ptr<double> sharedptr2, sharedptr3;
    sharedptr2 = sharedptr1;
    sharedptr3 = sharedptr1;
    std::cout << "the sharedptr1 = " << *sharedptr1 << std::endl;
    std::cout << "the sharedptr2 = sharedptr1. so now sharedptr2 = " << *sharedptr2 << std::endl;
    std::cout << "the sharedptr3 = sharedptr1. so now sharedptr3 = " << *sharedptr3 << std::endl;
    
    std::unique_ptr<double> uniquePtr(new double(567.098));
    std::cout << "the uniquePtr(new double(567.098)) = " << *uniquePtr << std::endl;
    
    std::cout << "The above is simplest example of using using pointer and shared pointer with parameter." << std::endl;
    std::cout << "Now I will apply smart pointer with struct, class, functions" << std::endl;
    //-----------------smart pointer with class-----------------------------
    
    std::unique_ptr<Person> smartPerson(new Person());
    smartPerson -> Display("Bjarne", 70);
    smartPerson -> shout(); // if I am using dot(.) inplace of ->, it gives an error.
    std::shared_ptr<Person> smartPerson2(new Person());
    smartPerson2 -> Display("JISHNU", 45);
    //------------------------------------------------------------------------
    std::string someString = "It's John Wick's Car!\n";
    copy(someString.begin(), someString.end(), std::ostream_iterator<char>(std::cout));
    
    
    //---------------press enter key to end the main function----------------
    logMessage("Exiting main() function......");
    //std::cin.get();
    return 0;
}
