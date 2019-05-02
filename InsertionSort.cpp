// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// pjoyjr

#include "InsertionSort.h"
#include <iostream>

//Default Constructor
InsertionSort::InsertionSort(){
    }

//Deconstructor
InsertionSort::~InsertionSort()
{

}
void InsertionSort::sortArray(int a[]){
   std::cout << "\nInsertion Sort: ";
   for (int i = 1; i < 50; i++) //start off at 2nd number in array
   {
       int compared = a[i]; 
       int j = i-1;
       while (j >= 0 && a[j] < compared) //while compared number is greater than one before
       {
           a[j+1] = a[j]; //move smaller number 1 spot later into array
           j = j-1; //see if number is greater than the number before
       }
       a[j+1] = compared; // put compared number into a[j+1]
   }
   for(int i = 0; i < 50; i++ ){ //print array of sorted numbers.
		std::cout << a[i];
		if(i !=49){
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}
