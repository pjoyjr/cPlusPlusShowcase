// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// pjoyjr


#ifndef BUBBLESORT_H
#define BUBBLESORT_H
//Header Guard

#include "Sort.h"

class BubbleSort : public Sort
{
    public:
        //default Constructor
        BubbleSort();
        //default Destructor
        virtual ~BubbleSort();
        virtual void sortArray(int[]);

};
#endif // BubbleSort_H_INCLUDED
