# C

#### Pointers:

1. 
    int main
    {
       int *i;
       *i = 10;
    }

The above code declares an integer pointer without being assigned an address. This means the variable "i" will contain a garbage value. "*i = 10" means we are putting the value "10" at the garbage address which might be or might not be in the process address space thus giving you a segmentation fault. The beauty of this bug is that it's won't always give you a segmentation fault because if you're lucky the garbage value might be an memory which belongs to your address space.

2. Ask them to explain the "signal" API call.
     Excerpt from the C manual:

    void (*signal(int sig, void (*func)(int)))(int);
         or in the equivalent but easier to read typedef'd version:
    typedef void (*sig_t) (int);
    sig_t signal(int sig, sig_t func);


#### Array and Strings

1. 
    int main()
    {
       char *array="hello, world";
       array[0]='A';
    }

The above program declares an array with content "hello, world". Next, we replace the 1st character with letter 'A'. Seem to work, but wait, there's a catch. String literals are always declared in the read only section of the executable. You can always "objdump" the C executable and see you yourself. The memory for above "array" variable will be declared in the Read-Only section. Thus the above code again gives you a segmentation fault every time it is executed.

2. Email address validation function(method) e.g. vishalchovatiya@hotmail.com

#### Memory Layout of C Program

If candidate know answer of this question means he/she knows in & out of C at memory level.

# C++

1. Initialization list, member variable & calling base class constructor 
2. Shallow copy & Deep copy
3. Interfaces
4. Virtual public inheritance 
5. Struct & class keyword in c++
6. Size of blank class
7. Mutable keyword
8. Auto keyword
9. Constant class
10. How time is print in systemC(conversion operator)
11. Sensitive class << overloading 
12. Exception handling
13. Diff between error & exception handling 
14. Dynamic_cast & static_cast
15. Bracket operators overloading 
16. Conversion operator
17. Calling order of Constructor destructor in inheritance
18. Template class & functions, how template works internally. Design generic array class that could be use for anything like bool, chat, float, object, etc.
19. Multiple inheritance 
20. Constructor/destructor calling order on array of objects
21. Object containing dynamic memory as argument & return type of function
22. Delete call destructor
24. Why we need late binding
25. Static member in class
26. Static data member & function of class
27. Increment/decrements operator over loading with prefix & postfix inc/decr operations 
28. Typeid method
29. virtual destructor
30. Access of derived class using base class pointer & vice versa
31. Why we need virtual functions : when want to redefined something like animal voice, theoretical & practical answer.
32. Why the size of blank class is 1 byte
33. Why dont we have virtual constructor.
34. Destructor overloading 
35. Behind the scene e c++ book Lippmann
36. Size of object containing function static member
37. Generic sorting function template 

https://www.toptal.com/c-plus-plus/interview-questions

http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors

http://www.sanfoundry.com/cplusplus-interview-questions-answers/

http://quiz.geeksforgeeks.org/commonly-asked-c-interview-questions-set-1/

http://quiz.geeksforgeeks.org/commonly-asked-c-interview-questions-set-2/

http://www.learncpp.com/cpp-tutorial/124-early-binding-and-late-binding/
