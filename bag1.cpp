// FILE: bag1.cpp
// From Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS IMPLEMENTED: bag (see bag1.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.





// DEBUG
#include <iostream>
using std::cout;
using std::endl;





#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "bag1.h"
using namespace std;

namespace main_savitch_3
{
    // (Omitted for VC++ 6.0) const set::size_type set::CAPACITY;

    set::size_type set::erase(const value_type& target)
    {
		size_type index = 0;
		size_type many_removed = 0;

		while (index < used)
		{
			if (data[index] == target)
			{
			--used;
			data[index] = data[used];
			++many_removed;
			}
			else
			++index;
		}

		return many_removed;
    }




    bool set::erase_one(const value_type& target)
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




    void set::insert(const value_type& entry)
    // Library facilities used: cassert
    {   
        assert(size( ) < CAPACITY);

		// IF OBJECT DOES NOT CONTAIN ENTRY
		if (!this->contains(entry))
		{

			// THEN RUN PREEXISTING INSERT SUBROUTINE
///*DEBUG*/ cout << "      NOT DUPLICATE: " << entry << endl;
			data[used] = entry;
			++used;
		}

    }




    void set::operator +=(const set& addend)
    // Library facilities used: algorithm, cassert
    {
		assert(size( ) + addend.size( ) <= CAPACITY);
	
		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
    }




/*
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


	bool set::contains(const value_type& target) const
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





    set operator +(const set& b1, const set& b2)
    // Library facilities used: cassert
    {
        set answer;

        assert(b1.size( ) + b2.size( ) <= set::CAPACITY);

        answer += b1; 
        answer += b2;
        return answer;
    }
}
