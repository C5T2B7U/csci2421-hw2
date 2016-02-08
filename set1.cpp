// BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW2: 6936HW2->set1.cpp




// FILE: set1.cpp
// From Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS IMPLEMENTED: set (see set1.h for documentation)
// INVARIANT for the set class:
//   1. The number of items in the set is in the member variable used;
//   2. For an empty set, we do not care what is stored in any of data; for a
//      non-empty set the items in the set are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.





// DEBUG
#include <iostream>
#include <fstream>  // FULL USAGE
#include <string>   // FULL USAGE
#include <cctype>   // FOR isdigit, iswhite
#include <cstdlib>  // FOR atoi


using std::cout;
using std::endl;


#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "set1.h"
//using namespace std;



// BEGIN NAMESPACE
namespace main_savitch_3
{

	// (Omitted for VC++ 6.0) const set::size_type set::CAPACITY;


	// REPLACE ORIGINAL set ERASE FUNCTION:
	set::size_type set::erase(const value_type &target)
	{
		size_type many_removed = 0;

		// IF TARGET ERASED THEN RETURN 1
		if (this->erase_one(target)) ++many_removed;
		return many_removed;
	}


	bool set::erase_one(const value_type &target)
	{
		size_type index; // The location of target in the data array

		// First, set index to the location of target in the data array,
		// which could be as small as 0 or as large as used-1. If target is not
		// in the array, then index will be set equal to used.
		index = 0;
		while ((index < used) && (data[index] != target))
			++index;

		if (index == used)
			return false; // target isn�t in the set, so no work to do.

		// When execution reaches here, target is in the set at data[index].
		// So, reduce used by 1 and copy the last item onto data[index].
		--used;
		data[index] = data[used];
		return true;
	}


	void set::insert(const value_type &entry)
	// Library facilities used: cassert
	{

		// DO NOT VIOLATE THIS ASSERT VIA UNION OPERATOR YOU HAVE BEEN WARNED!!!!!!!!!!1
		assert(size() < CAPACITY);

		// IF OBJECT DOES NOT CONTAIN ENTRY
		if (!this->contains(entry))
		{
			// THEN RUN PREEXISTING INSERT SUBROUTINE
///*DEBUG*/ cout << "      NOT DUPLICATE: " << entry << endl;
			data[used] = entry;
			++used;
		}
	}




	void set::operator +=(const set& arg_set)
	// Library facilities used: algorithm, cassert
	{

		// OLD ASSERT NO LONGER VALID
		// assert(size( ) + arg_set.size( ) <= CAPACITY);

		// OLD METHOD NO LONGER VALID
		// copy(arg_set.data, arg_set.data + arg_set.used, data + used);
		// used += arg_set.used;

		size_type i;

		for (i = 0; i < arg_set.size(); ++i)
			this->insert(arg_set.data[i]);
	}



	void set::operator -=(const set& arg_set)
	{

		set *bufferSet;
		size_type i, loopVal;

		bufferSet = this;
		loopVal = bufferSet->used;

///*DEBUG*/ cout << "USED = " << bufferSet->used << endl;

		for (i = 0; i < loopVal; ++i)
		{

///*DEBUG*/ cout << "I = " << i << "     DATA = " << bufferSet->data[i] << endl;

			if (arg_set.contains(bufferSet->data[i]))
			{

///*DEBUG*/ cout << "ERASING DATA[I] = " << bufferSet->data[i] << endl;

				this->erase(bufferSet->data[i]);
			}
		}
	}





	/*	// FUNCTION HAS BEEN REPLACED WITH set::contains
    set::size_type set::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }
*/



	bool set::contains(const value_type &target) const
	{

///*STUB*/ cout << "\nRAN contains() - RETURN TRUE\n";
///*DEBUG*/ return true;

		// RUN MODIFIED PREEXISTING SUBROUTINE
		bool answer;
		size_type i;

		answer = false;

		for (i = 0; i < used; ++i)
			if (target == data[i])
				answer = true;

		return answer;
	}





    set operator +(const set& s1, const set& s2)
    // Library facilities used: cassert
    {
        set answer;

		// OLD ASSERT NO LONGER VALID
        // assert(b1.size( ) + b2.size( ) <= set::CAPACITY);

		answer += s1;
        answer += s2;
        return answer;
    }




	set operator -(const set& s1, const set& s2)
	// Library facilities used: cassert
	{
		set answer;

		answer = s1;
		answer -= s2;
		return answer;
	}





	std::ostream &operator << (std::ostream&os, const set& arg_set)
	{
		os << '{';

		set::size_type i;

		for (i = 0; i < arg_set.used; ++i)
		{
			os << arg_set.data[i];
			if (i != arg_set.used - 1)
				os << ", ";
		}

		os << '}';
		return os;
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



// END NAMESPACE
}

