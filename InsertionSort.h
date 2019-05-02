// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// pjoyjr


#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
//Header Guard

#include "Sort.h"

class InsertionSort : public Sort
{
    private:
        int b [50];
    public:
        //default Constructor
        InsertionSort();
        //default Destructor
        virtual ~InsertionSort();
        virtual void sortArray(int[]);

};
#endif // InsertionSort_H_INCLUDED
