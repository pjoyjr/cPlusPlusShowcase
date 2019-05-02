// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// pjoyjr

#include "BubbleSort.h"

//Default Constructor
BubbleSort::BubbleSort(){
}

//Deconstructor
BubbleSort::~BubbleSort()
{

}

void BubbleSort::sortArray(int a[]){
    std::cout << "\nBubble Sort: ";
	for (int i = 0; i < 49; i++){ //start at beginning of array
		for (int j = 0; j < 49-i; j++){ //for comparing to the next number
			if (a[j] < a[j+1]){ //if the first number is smaller than the second number
				int temp = a[j]; //switch around
				a[j] = a[j+1];
				a[j+1] = temp;
		   }
	   }
	}
	for(int i = 0; i < 50; i++ ){ //print array of sorted numbers.
		std::cout << a[i];
		if(i !=49){
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}
