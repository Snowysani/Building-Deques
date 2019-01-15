//
//  main.cpp
//  Gallegos_Michael_PA2
//
//  Created by Michael Gallegos on 10/8/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//
/*
 For this programming assignment, you will implement a DEQUE whose size can grow as elements are inserted into the DEQUE.
 Specifically, you will implement a DEQUE with a doubly linked list.
 All of your functions should run in O(1) time.
Coding Portion​ (100 Points):
· ​Start with the following template:​ Deque.h​ and fill in all of the member functions.
 Do NOT modify the definition of the functions of the DEQUE or put the declarations in a different file.
 We will be compiling the code you turn in with a set of tests and need your code to have the correct interface to compile the results.
 
 Here is an example​ main.cpp​ that we will use to test the correctness of your data structure.
· ​For the Doubly Linked List, you will need to implement another class for the nodes in the Doubly Linked List.
· ​Be sure to test the correctness of your algorithms and implementations.
· ​Your code will be graded based on whether or not it compiles, runs, produces the expected output,
    produces correct output, and your coding style (does the code follow proper indentation/style and comments).
Grading Rubric
● Valid file name as per submission instructions: ​1 point
● Executable code: ​5 points
● Doubly Link List: ​20 points
● Each Function in Deque.h: ​50 points (5 points each)
● Correct output for all operation: ​8 points (1 point each)
● Organized and Readable code:​ 4 points
● All operation in O(1): ​12 points (1.5 point for each)
 */

#include <iostream>
#include "Deque.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Deque<int> intQ;
    
    printf ( "isEmpty(1): %d\n", intQ.isEmpty ( ) ? 1 : 0 );
    intQ.insertFirst ( 4 );
    printf ( "removeLast(4): %d\n", intQ.removeLast ( ) );
    intQ.insertFirst ( 5 );
    intQ.insertFirst ( 12 );
    intQ.insertLast ( 7 );
    intQ.insertLast ( 13 );
    printf ( "first(12): %d\n", intQ.first ( ) );
    printf ( "last(13): %d\n", intQ.last ( ) );
    printf ( "size(4): %d\n", intQ.size ( ) );
    printf ( "isEmpty(0): %d\n", intQ.isEmpty ( ) ? 1 : 0 );
    printf ( "removeLast(13) :%d\n", intQ.removeLast ( ) );
    printf ( "removeLast(7) :%d\n", intQ.removeLast ( ) );
    printf ( "removeLast(5) :%d\n", intQ.removeLast ( ) );
    printf ( "removeFirst(12) :%d\n", intQ.removeFirst ( ) );
    printf ( "size(0): %d\n", intQ.size ( ) );
    printf ( "isEmpty(1): %d\n", intQ.isEmpty ( ) ? 1 : 0 );
    return 0;
}
