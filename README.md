# Overview

A collection of standard data structures implemented in C.

# Supported Data Structures

Data Structure | Source | Comments | Design
---------------|--------|----------|---------
Singly Linked List | sll.h, sll.c  | void * for generic type stored at each node. | Minimal.
Singly Linked List | msll.h, msll.c | Macro generated code for generic types.     | Macro/Experimental.
Doubly Linked List | dll.h, dll.c  | void * for generic type stored at each node. | Minimal.
Circularly Linked List | cll.h, cll.c | void * for generic type stored at each node. | Minimal.
Stack | lstk.h, lstk.c | void * for generics. | Adapter (singly linked list).
Stack | astk.h, astk.c | void * for generics. | Minimal. Array based.
Queue | aq.h, aq.c     | void * for generics. | Minimal. Array based.
Queue | lq.h, lq.c     | void * for generics. | Adapter (singly linked list).

# TODO

1. The makefile is becoming too large and ad hoc. There are separate targets
for each test program, however the compilation steps for each of them
are basically the same. It is also unclear if the benefit of using a makefile,
such as compiling only the modules that have changed, is worth it here.
The flexibility of using a Python script may outweigh the benefits of the makefile.

UPDATE 2020/07/10 -- Investigating replacing make with meson. Also, rearranging the 
repository directory structure for greater clarity. 

2. The test programs themselves for each data structure are largely the
same. There should be a unified testing framework for testing the data
structures so that I only have to write one testing program and plugin
the appropriate data structure. At least there should be a unified testing
framework for each of the types of stacks, lists, etc. I think this can best
be accomplished with a few simple macros and a header file. The rest must be
specific to the data structure under consideration.

3. Need to be careful regarding naming. Names may have to be more specific
in order to avoid conflicts. This is also true for variables and macro
naming.
