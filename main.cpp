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
#include <fstream>  // FULL USAGE
#include <string>   // FULL USAGE
#include <cctype>   // FOR isdigit, iswhite
#include <cstdlib>  // FOR atoi


using std::cout;
using std::cin;
using std::endl;


#include "bag1.h"
using namespace main_savitch_3;



// FUNCTION: FILE INPUT
bool validInput(set& arg_setA, set& arg_setB);



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

		setD = setA;
		setD -= setB;
		cout << "setD = setA; setD -= setB; ==> " << endl << setD << endl;

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




bool validDataTokenize(std::string arg_string, set &arg_set)
{


    // STRING BUFFER = "";
    std::string buffer = "";

    // VALIDITY
    int validFlag;
    validFlag = 1;



    // FOR X = 0 TO LENGTH() - 1
    for (int x = 0; x < arg_string.length(); x++)
    {


///*DEBUG*/ cout << "RAW:   x = " << x << "   [" << arg_string[x] << "] = [" << int(arg_string[x]) << "]     VALID = " << validFlag << endl;


        // IF (STRING[X] == '-') OR (STRING[X] IS DIGIT)
        if (arg_string[x] == '-' || std::isdigit(arg_string[x]))
        {

///*DEBUG*/ cout << "BUFFERING: " << arg_string[x] << endl;
            // THEN BUFFER += STRING[X]
            buffer += arg_string[x];
        }


        // ABORT LOOP IF INVALID DATA
        // ALL STRING[X] OTHER THAN '0' ... '9' AND '-' WILL RUN TEST
        // THEREFORE, ANY CHAR OTHER THAN WHITESPACE IS INVALID
        else if (!std::isspace(arg_string[x]))
        {

///*DEBUG*/ cout << "----------------INVALID DATA -> ABORT LOOP-----------------" << endl;

            // SET VALID FLAG FALSE
            validFlag = 0;

            // LET X EXCEED ENDCONDITION
            x = arg_string.length() + 1;

            // FOR LOOP TERMINATED; GOTO END
        }


            // ELSE IF BUFFER != "" THEN INSERT PREVIOUS INTEGER ON VALID WHITESPACE
        else if (buffer != "")
        {

///*DEBUG*/ cout << "NOW INSERTING: " << atoi(buffer.c_str()) << endl;

            // THEN SET.INSERT(ATOI(BUFFER.C_STR()))
            arg_set.insert(std::atoi(buffer.c_str()));

            // THEN BUFFER = ""
            buffer = "";
        }
        // LABEL: VALID INTEGER DATA CONTINUES EXECUTION HERE

    }

    // LABEL: END
    return validFlag;
}



bool validInput(set& arg_setA, set& arg_setB)
{

    // VALIDITY FLAG
    int validFlag;
    validFlag = 1;

    // OPEN FILE
    std::ifstream inputFile;
    inputFile.open("input.dat");

    // IF NOT FAIL
    if (!inputFile.fail())
    {
        std::string line1, line2;
        line1 = line2 = "";

        // GETLINE TO STRING 1
        getline(inputFile, line1);

        // GETLINE TO STRING 2
        getline(inputFile, line2);

        // GUARANTEE LAST NUMBER IN STRING INSERTED INTO SET BY ADDING WHITESPACE
        line1 += " ";
        line2 += " ";


/*DEBUG*/ cout << "\nLINE 1 = " << line1 << "\nLINE 2 = " << line2 << endl;

        // TEST VALIDITY; TOKENIZE STRINGS; INSERT TOKENS INTO OBJECTS
        if (!validDataTokenize(line1, arg_setA) || !validDataTokenize(line2, arg_setB))
        {
            validFlag = 0;
        }
    }
        // ELSE SET VALID FLAG FALSE
    else validFlag = 0;



    // CLOSE FILE
    inputFile.close();

    // RETURN VALID FLAG
    return validFlag;
}