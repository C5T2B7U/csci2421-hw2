// BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW2: 6936HW2->main.cpp


/*
Homework 2

Refer to the documenting and submitting homework from here.
Set Class

Modify the bag1.h and bag1.cpp to implement the "set" class for integers
 described in project 5 at page 149. You have to use bag1 code and extend it
 for this homework. To verify your set class, write a main function that
 takes two sets of integers from an input file input.dat, and store them into
 separate sets, and apply following two operations.

First, combine the two into one set by using + (union) operator, and print
 out the union set. The + operator must remove all duplicates and store one
 copy of any item. You also need to implement a subtraction operator (A-B
 means removing all elements of B from A) and print out the result. So the
 main function takes two sets of integers and print the result of + and - operation.

A sample input.dat may look like this. Note that we assume the input file
 includes only two sets of integer numbers, each number is separated by
 white spaces and sets are separated by a newline character.

 3  4  5  7  5 16 7 12 11 12  3  9  9  8  1 12
15  4  3  6 1 12  3 12 7  8 19  9 11 12  8  5 -4  -100

Assume that all inputs are integers and anything else should be rejected with
 an error message.

Include a run-time asymptotic analysis of main member functions in the readme
 file. You can write your readme file in html or pdf format.

Grading guideline

    Correct and complete functionality 60%
    Run-time analysis 10%
    Reasonable fault tolerance, i.e. it should not crash often. 10%
    Makefile and Readme 10%
    Documentation and comments in the code 10%

Due on Feb. 8th at 4PM.
 */


/*
 * 5. A bag can contain more than one copy of an item.
 * For example, the chapter describes a bag that contains the number 4 and two copies of the number 8.
 * This bag behavior is different from a set, which can contain only a single copy of any given item.
 * Write a new container class called set, which is similar to a bag, except that a set can contain only one copy of any given item.
 * You'll need to change the interface a bit.
 * For example, instead of the bag's count function, you'll want a constant member function such as this:
 *
 * bool set::contains
 * (const value_type& target) const;
 * // Postcondition: The return value is true if
 * // target is in the set; otherwise the return
 * // value is false.
 *
 * Make an explicit statement of the invariant of the set class.
 * Do a time analysis for each operation.
 * At this point, an efficient implementation is not needed.
 * For example, just adding a new item to a set will take linear time because you'll need to check that the new item isn't already present.
 * Later we'll explore more efficient implementations (including the implementation of set in the C++ Standard Library).
 * You may also want to add additional operations to your set class, such as an operator for subtraction.
 */




/*
To verify your set class, write a main function that
 takes two sets of integers from an input file input.dat, and store them into
 separate sets, and apply following two operations.

First, combine the two into one set by using + (union) operator, and print
 out the union set. The + operator must remove all duplicates and store one
 copy of any item. You also need to implement a subtraction operator (A-B
 means removing all elements of B from A) and print out the result. So the
 main function takes two sets of integers and print the result of + and - operation.
 */




#include <iostream>

using std::cout;
//using std::cin;
using std::endl;


#include "set1.h"
using namespace main_savitch_3;




int main()
{

    // EXIT CODE
    int exitCode;
    exitCode = 0;

    // DECLARE SET A, SET B
    set setA, setB;

    // INPUT FROM FILE; STORE AS TWO SETS
    // Assume that all inputs are integers and anything else should be rejected with an error message.
    if (validInput(setA, setB))
    {

/*DEBUG*/ cout << "\nINPUT VALID\n\n";

        cout << "setA = " << setA << endl;
		cout << "setB = " << setB << endl;

		cout << endl;


		set setC, setD;
		// UNION SET A + SET B; PRINT RESULT

		cout << "setA + setB ==> " << endl << setA + setB << endl << endl;

		setC = setA;
		setC += setB;
		cout << "setC = setA; setC += setB; ==> " << endl << setC << endl;

		cout << endl;


        // SUBTRACT SET A - SET B; PRINT RESULT
		cout << "setA - setB ==> " << endl << setA - setB << endl << endl;

		setD = setB;
		setD -= setA;
		cout << "setD = setB; setD -= setA; ==> " << endl << setD << endl;

		cout << endl;

		cout << "ASSIGNMENT COMPLETE" << endl;

        // EXIT WITH DEFAULT EXIT CODE
    }
    // ELSE DISPLAY ERROR
    else
    {
        cout
            << "WARNING: INVALID DATA OR INPUT FILE IS NOT ACCESSIBLE" << endl
            << "THIS PROGRAM EXPECTS ONLY INTEGERS AND WHITESPACE ON LINES 1 AND 2 OF input.dat" << endl
            << "PLEASE FIX THE INPUT FILE BEFORE RUNNING THE PROGRAM AGAIN" << endl
            << "HAVE A NICE DAY" << endl;

        // EXIT WITH EXIT CODE 1111
        exitCode = 1111;
    }

///*DEBUG*/ cout << "END" << endl;
    return exitCode;
}




