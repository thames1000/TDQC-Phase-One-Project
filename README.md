# JQR Phase One Project
## Table of Content
1. [About Phase 1](#1)
2. [Stack Objectives](#2)
3. [Using CMake](#3)
4. [Using GTest](#4)
5. [CMake and your text editor](#5)

## About Phase 1 <a name="1"></a>
Alright team, for the JQR Phase 1 project you will be working on getting up to 
speed on using [CMake](https://cmake.org/). In class, you have used Make which is 
great. On most Linux systems, CMake will create a Makefile to compile your project. 
But CMake can do a lot more than that like manage dependencies, and build different 
versions of your code with ease and even run other tools. It is also one of the most supported build systems 
when it comes to IDE integration. Meaning that IDEs like [CLion](https://www.jetbrains.com/clion/) 
and [Visual Studio](https://visualstudio.microsoft.com/vs/) rely on CMake to have
a meaningful understanding of your project to provide intelligent refactoring and 
guidance. 

With that said, the main focus for this JQR phase is to:
- Build a "generic" stack in C (This is a JQR item)
- Set up your project using CMake
- Write unit tests in GTest
- Set up your text editor of choice with CMake

## Stack Objectives <a name="2"></a>
The library you are building is a "generic" stack. What is generic? In modern languages
a generic is a structure that takes in *any* data type. As you know, if you have a array
of `ints`, you cannot add a character in the array and expect it to work properly like Python. 
Only one data type can be in the array. To avoid repeating yourself to support ALL data
types (i.e `init_str_array()` `init_int_array()` `init_long_int_array()`) you create
generics which sets up the structure to be of the initial data type. 

One problem though, C has only recently created a Generic macro. You will not be 
using this macro, instead you will be using `void pointers`. Void pointers is how
C is able to make "generics" by just not knowing the type being used at all. Instead,
what is stored is an address to a memory block of unknown type. That means that 
the library you are writing has no idea what kind of data it is dealing with. It 
just knows about the address. 

Keep in mind that sometimes the library WILL need to know about the data like
if you are making comparisons between pointers. To get around this you can pass
in a function pointer to your library. The function pointer will then cast the 
void pointers to their actual types to make the comparison.

Two great videos that I have personally used for these concepts are:
- [Generics data types in C](https://www.youtube.com/watch?v=RG7D2_pay0U)
- [C Tutorial: void *, generic data-structures, and functions](https://www.youtube.com/watch?v=AUYYN3mqSGU&t=3531s)

The stack you create must support the following. Keep in mind that these are JQR
items, so please do your best so that you do not have to rewrite it when it gets
checked off by your mentors. 
- [ ] Creating a stack with n number of items
- [ ] Navigating through a stack to find the nth item
- [ ] Adding an item in a stack
- [ ] Removing selected items from a stack
- [ ] Removing all items from the stack
- [ ] Destroying a stack
- [ ] Preventing a stack overrun

I have already created a header file in `include` with the functions it must support. 
Feel free to modify them as you wish except for the `struct typedef`. That typedef
is to make the internal structure `opaque`. This means that users of your library 
cannot access the internal structure. They must use your functions to manipulate the stack.

## Using CMake <a name="3"></a>
As mentioned in the introduction, you will be using CMake to build your projects not Makefile.
You should all have gotten access to O'Reilly books. I highly recommend reading
[Modern CMake for C++](https://www.amazon.com/Modern-CMake-Discover-approach-packaging/dp/1801070059). I 
highly advise you to pay attention to even the parts that do not entirely relate to 
CMake like how linking and compilation works. These are topics that you will be 
tested on for your JQR. This is a fantastic book and will bring you up to speed. 

I have already created most of the skeleton for you projects. All you will have to do 
is create the CMakeLists.txt for you `stack` directory. Everything else is set up
for you. Make sure to name your library `stack`. 

## Using GTest <a name="4"></a>
GTest is an extremely popular testing framework for C++. Not all features work
for C, but it is still good enough for C. I have already submoduled the framework
and have created the CMake file for you. All you will need to worry about is 
learning how to use GTest. Some great resources to use:

- [Googletest Primer](https://google.github.io/googletest/primer.html)
- [Parameterized testing with Gtest](https://www.sandordargo.com/blog/2019/04/24/parameterized-testing-with-gtest)

You will want to create thorough tests for your libraries. This will ensure that when 
you refactor that nothing is going to break. Get in the habit of writing unit tests
as your project evolves. Do not wait until your project is made to test and do not rely
on a main function to test your code. Do everything on your unit tests.

## CMake and your text editor <a name="5"></a>
One of the most annoying parts about developing with build systems is having to leave
you text editing window to jump to your terminal to run the lines you need to either 
run or debug your code. This does not have to be the case, though. IDEs and even
VSC have methods for automating your builds with shortcuts. As a requirement
you will set up your text editors to utilize your CMake to build your projects
automatically without using the terminal. 

To prove that you have your text editors set up properly, add screenshots showcasing
the build and running of your program and the integrated debugger running. 

For editors like CLion and VSC, the support for CMake is built in and expected. They
should automatically detect your root CMake file and start providing you with 
running configurations for your project. With editors like VSC, it takes a bit of
work to set up. There is a great write-up on the Microsoft page to get you set up.

- [CMake on VSC](https://code.visualstudio.com/docs/cpp/cmake-linux)
