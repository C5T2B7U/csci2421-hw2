// // BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW2: 6936HW2->set1.h



// 


// FILE: set1.h
// From Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS PROVIDED: set (part of the namespace main_savitch_3)
//
// TYPEDEF and MEMBER CONSTANTS for the set class:
//   typedef ____ value_type
//     set::value_type is the data type of the items in the set. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     set::size_type is the data type of any variable that keeps track of how many items
//     are in a set.
//
//   static const size_type CAPACITY = _____
//     set::CAPACITY is the maximum number of items that a set can hold.
//
// CONSTRUCTOR for the set class:
//   set( )
//     Postcondition: The set has been initialized as an empty set.
//
// MODIFICATION MEMBER FUNCTIONS for the set class:
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the set.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the set, then one copy has been removed;
//     otherwise the set is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the set.
//
//   void operator +=(const set& addend)
//     Precondition:  
//     Postcondition: Each item in addend has been added to this set.
//
// CONSTANT MEMBER FUNCTIONS for the set class:
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the set.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the set.
//
// NONMEMBER FUNCTIONS for the set class:
//   set operator +(const set& b1, const set& b2)
//     Precondition:  b1.size( ) + b2.size( ) <= set::CAPACITY.
//     Postcondition: The set returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the set class:
//    Assignments and the copy constructor may be used with set objects.

#ifndef MAIN_SAVITCH_SET1_H
#define MAIN_SAVITCH_SET1_H


#include <cstdlib>  // Provides size_t


namespace main_savitch_3
{
    class set
    {

    public:

        // TYPEDEFS and MEMBER CONSTANTS
	// * For VC++ 6.0 we are using size_t instead of std::size_t. And we
	// * have defined CAPACITY using an enum instead of a static member
	// * constant. See www.cs.colorado.edu/~main/vc6.html for details.
        typedef int value_type;
        typedef size_t size_type;
	enum { CAPACITY = 30 }; 

        // CONSTRUCTOR
        set( ) { used = 0; }

        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);

        // DO NOT VIOLATE THE ASSERT IN THIS FUNCTION VIA UNION OPERATOR YOU HAVE BEEN WARNED!!!!!!!!!!1
            // THIS ASSERT IS AS FOLLOWS:
            // assert(size( ) < CAPACITY);
            // IF SIZE IS EQUAL TO CAPACITY YOU CANNOT INSERT ANYTHING
        void insert(const value_type& entry);

		void operator +=(const set& addend);
		void operator -=(const set& addend);

        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }


/*
        size_type count(const value_type& target) const;
        For example, instead of the set's count function, you'll want a constant member function such as this:

        bool set::contains
        (const value_type& target) const;
        // Postcondition: The return value is true if
        // target is in the set; otherwise the return
        // value is false.

*/
        bool contains(const value_type& target) const;
        // Postcondition: The return value is true if
        // target is in the set; otherwise the return
        // value is false.


		friend std::ostream &operator << (std::ostream&os, const set& arg_set);


    private:
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
    };



    // NONMEMBER FUNCTIONS for the set class
	set operator +(const set& b1, const set& b2);
	set operator -(const set& b1, const set& b2);

	// FUNCTION: FILE INPUT
	bool validInput(set& arg_setA, set& arg_setB);
		// Precondition: An appropriately formatted input.dat must be in the working directory
		// Postcondition: Returns true if valid data was correctly read from file and tokenized

	bool validDataTokenize(std::string arg_string, set &arg_set);
		// Precondition: Data was correctly read from file
		// Postcondition: Returns true if data is valid after inserting data into set object
}

#endif
