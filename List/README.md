Project 1: List ADT

Follow the project instructions below carefully, and submit your code as described here:

Hand-in 1 C source files:

intlist.c


Your solution will be tested by another program, so please ensure you:
upload each C source files separately (don't zip and submit your project folder)
name each C source file correctly - exactly as above, all lower-case


Grading Criteria:

each List operation executes correctly and produces correct return value with no undocumented side-effects (80 points)
source code adheres to Comp220 style guide, algorithms are DRY and not overly convoluted (20 points)
 
Project 1 Instructions (pdf) Project 1 Instructions (pdf)


Project 1 Instructions:


Capilano University Comp220 ASSIGNMENT 1 J. Fall

Comp 220 Assignment #1

Objectives:
 • to implement a simple list ADT using a dynamic array;
 • to review common array algorithms (linear search, count, reverse, etc.);
 • to introduce dynamic memory management using calloc() and free();

A List ADT
“In computer science, a list or sequence is an abstract data type that represents a
countable number of ordered values, where the same value may occur more than once.
An instance of a list is a computer representation of the mathematical concept of a finite
sequence.”

A List is among the most common and important data structures used in
programming – and it is a core foundation of the List Processing (LISP)2 programming paradigm!

While at first glance a list may sound similar to an array, these are distinctly different concepts.
An array is a basic, built-in, concrete data structure representing a block of contiguous memory
locations. In other words, an array is a language feature that allows you to allocate and access a
structured block of memory.

A list, on the other hand, is an abstraction for an ordered sequence of elements with operations
that allow you to append, insert, and remove items. The length of a list is always exactly the
number of elements it contains – logically, it expands and contracts based on the elements it
contains (note: this is a logical abstraction, not necessarily a physical implementation detail!).

Lists often also have a set of higher-order operations associated with them, like searching,
sorting, or reversing the elements in the sequence.

Lists are a key data structure in many problems, and we will look at them in more detail later in
the term. For your first project we will program a List ADT using a "resizable array"3
implementation.

Getting Started:
1. Download the starter project: https://tinyurl.com/comp220-assign1

2. Unpack the project in your development environment and inspect the list of files:
 • intlist.h – the C "header" file containing the IntList ADT specification
 • ilist-test-*.c – 3 different programs for testing the code your write (see below)
 • grades*.txt – sample data files to go with the ilist-test-app program.
 • Makefile – a makefile for the project – build instructions for the 3 programs.
 
3. Add a new C source file with a proper comment block at top (as per style guide):
 • intlist.c – the C "source" file that will contain your IntList implementation
 
 1 https://en.wikipedia.org/wiki/List_(abstract_data_type)
 2 https://en.wikipedia.org/wiki/Lisp_(programming_language)
 3 https://en.wikipedia.org/wiki/Dynamic_array

 Building (compiling and linking) the project
 The starter project comes with 3 different main programs:
 • ilist-test-basic.c – a basic, interactive test driver that you may find useful while you
    are developing, testing, and debugging your code (more on this below).
 • ilist-test-app.c – a sample application of the IntList ADT for assembling and
   reporting on grades. It is sometimes helpful to see how the ADT will be used to
   perform a useful task – the purpose here is to provide a real-world example of how
   your IntList ADT might be used to solve a larger problem.
 • ilist-test-unit.c – an automated unit-test suite. Unit testing4 is a critical component
   of modern software development5. This program contains a fairly complete unittest
   suite for the IntList ADT, similar to the one used to grade your work.
   To build any of these programs, run the compiler specifying both the intlist.c module
   AND the main program source file you want built. For example:
   > gcc intlist.c ilist-test-basic.c -o test.exe
   
You will notice that the project files will compile, but that the linker fails with "undefined
reference" errors. The linker is saying it cannot find the definition for each of the
functions called by the main program – you haven't written them yet!!
Recommendation: review the code in the basic testing program (ilist-test-basic.c), and
comment out ALL of the actual test logic. Now you should be able to build the program,
as above, but it won't actually do anything. As you implement each of the List functions
(see Tips and Hints below), uncomment the code that tests that function, and/or add some
additional code of your own to help you test and debug your code thoroughly.
I recommend that you defer building the test-app and unit-test programs until after you
are fairly sure your have the implementation complete. The correctness of your project
will be automatically graded by a program similar to the unit test suite, so be sure all the
tests in this suite pass before submitting your code.

4 https://en.wikipedia.org/wiki/Unit_testing

5 https://en.wikipedia.org/wiki/Test-driven_development


Understanding the Specification

This term you will be learning to read and write informal specifications – a short, precise
description of a functions you need to implement. These specifications can be quite
confusing at first, but as you become accustomed to reading them, you'll find they
provide a concise and precise way to specify the problem you need to solve.

I start every new project by designing and writing such a specification for myself!

The specification for the IntList module is found in intlist.h.

This code defines a small struct specifying the data items required to represent one list.

The code then specifies a documented function proto-type for each function required to
build the complete project and receive full marks.

This is called an "interface specification", commonly referred to as an "API"6. It
specifies everything a programmer would need to know to USE this module. It specifies
precisely WHAT the module does – it's external behaviour. Note that it says nothing
about HOW the module is implemented – nothing about its internal algorithms nor data
structure – all of that is "hidden"7 from the programmer using the module.

In the interface documentation, you will notice a few keywords written in ALL CAPS
that have special meaning and form part of the "interface contract"8 :

 • PRE: this is called the "pre-condition" – it defines a condition that MUST be true
        before the function is called. These should be enforced with an assert()
        statement, whenever possible.
        
 • POST: this is called the "post-condition" – it defines any side-effects of calling the
         function by specifying conditions that will be true AFTER the function is called.
         These are only relevant for non-pure functions with side-effects.
         
 • RETURN: if the return value requires a more complete description, this defines
           exactly what is returned by the function in every possible situation.

Note that in every case, this documentation is written for the client of the service – the
programmer who will be using the module to build an application. Thus, this
documentation refers only to publicly visible parts of the API, never to the internal,
implementation details.

6 https://en.wikipedia.org/wiki/Application_programming_interface
7 https://en.wikipedia.org/wiki/Information_hiding
8 https://en.wikipedia.org/wiki/Design_by_contract


Hints, Tips, and Strategies for completing the project

It is likely that your experience up to now has been to write complete programs from start
to finish – thinking of the main() function as the starting point for your efforts. In this
project, I am showing you that real programming doesn't actually work that way – here
I've given you 3 different main programs that each do different things, all using the same
library module – and you have to implement that underlying module! You may have
never thought about programming from this angle before, and it can be a significant
challenge, so here is some advice on how to proceed:
 
 • Start by READING the code provided.
   Ask questions about anything in that code you don't understand. In particular, be sure
   you understand the meaning of every symbol and every word in the IntList
   specification (intlist.h). If not, ask!
   Read the sample application code (ilist-test-app.c) to gain an understanding of how a
   program might use the module you are about to write.
   
 • Draw some memory block diagrams of the program in progress.
   Use the techniques we've seen in class to imagine how the IntList data structure
   will change over time as the application program executes.
   Record the values for each of the IntList struct's fields as you trace the program.
 
 • Write, test, and debug one function at a time.
   Start with the Constructor – this should be an easy function to write since it simply
   initializes an IntList struct to represent an empty list, and returns it.
   Uncomment the part of the test driver (ilist-test-basic.c) that calls the constructor and
   run that test, debug until it works before moving on.
   
   The tests in this driver are sequenced more-or-less in the order I did my
   implementation. You don't have to develop in the same sequence – choose a
   sequence that makes sense to you, but only work on one function at a time. I strongly
   recommend you write the Print operation early – very useful for debugging!
   
 • Develop some private helper functions.
   One of the challenges in this assignment is managing the List memory so the list can
   grow as needed. As mentioned above, the technique we are implementing is called
   "resizeable array". I found it useful to implement a couple helper functions to keep
   the resizeable array logic separate from my main List handling logic:
   
   o // expand list capacity. 
     void ilistGrow( IntList *list );
     
   o // shift list elements, from index onward, 1 place to right,
     // "creating" an "empty" slot at pos. index.
     void ilistShiftRight( IntList *list, int index );

   o // shift list elements following index 1 place to left,
     // "overwriting" the item at pos. index, shortening list by 1
     void ilistShiftLeft( IntList *list, int index );


 • Check the list capacity before adding new elements!
   One of the key services / abstractions your List ADT provides is it frees the client
   from having to worry about array constraints. That's because YOU have done all the
   worrying for them! Before adding a new item to the list, always check that there is
   still capacity, and if not, grow the list's capacity before adding the item.
   
 • Define a "block size" for expanding capacity.
   Expanding the list capacity will be an "expensive" operation (from a program
   efficiency perspective), so we don't want to do this for every element. Instead, define
   a constant for the "block size" (10 would be a reasonable value to use during
   development) and expand the list capacity by blocks of memory this size, as needed.
   Note: you never need to "shrink" the list capacity!
 
 • Don't create any memory leaks or leave any dangling pointers!

We will learn more about dynamic memory management over the term, but the golden
rules of all dynamic memory management are:
 1. Always free() memory when you are done with it!
 2. Always set dangling pointers9 to NULL!
 
• KISS – Keep It Simple Students!
Students have a tendency to over-think and over-complicate things. The longest
algorithm in my solution is 5 or 6 lines of code. You may not want to write your code
so concisely (and don't feel you must – your code will be evaluated for it's correctness,
style, and DRY10ness, but not on the number of lines) – but this does tell you that there
is absolutely nothing complicated about any of these algorithms – they each have a
simple, straight-forward solution that any student who completed Comp120 should be
able to solve.
9 https://en.wikipedia.org/wiki/Dangling_pointer
10 https://en.wikipedia.org/wiki/Don%27t_repeat_yourself

