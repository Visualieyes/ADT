Vector-ADT
Implementing a Vector ADT with C-struct.



ADT:            intvector.c
Implementation: intvector.h  
Test Driver:    ivec-test.c

Review the vector ADT interface (API) defined in intvector.h The .h (header) file defines the "public interface" for a vector – it contains only definitions, no implementation details go here! • Review the new data type, IntVector, defined as a struct o a vector is composed of an int representing its dimension (length of the vector) + a pointer to an array of int representing the vector coordinate • Review the function proto-types for the vector operations. o Notice each operation's function name starts with "ivec" – this is a way of "namespacing" IntVector operations. o Add a comment above each proto-type to say what you think the function does. Be as precise as possible. • Notice the special "object constructor" function, ivecFromArray() o This function "hides" how IntVector objects are implemented, providing better encapsulation. • You may want to add a function to read a vector from a File – if so, your function should read the vector data into an array, and then call ivecFromArray() to actually construct the vector object.

Implement the vector ADT algorithms in intvector.c The .c (source) file defines the "private implementation" for a vector – it defines the algorithms (functions) for all the vector operations! • The implementation for the IntVector constructor has been provided, along with a "stub" for the Print operation. • Build the project like this: > gcc intvector.c ivec-test.c -o lab4.exe • Notice the program does not properly print the vector object, and it reports that none of the tests passed. Your job is to get this test program working so it produces meaningful output and passes all tests. • Start by implementing ivecPrint()– print a nice, visual representation for the vector – you wrote this code already in a previous lab (but don't print a newline!) • Now implement each of the remaining operations. For each operation, you will find a commented out test ivec-test.c -- uncomment the test to check if your code is working. • You are done when the test driver reports that all tests passed.
