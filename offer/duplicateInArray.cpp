//
// Created by aleafall on 17-2-26.
//

#include <iostream>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (!numbers || !length) {
			return 0;
		}
		for (int i = 0; i < length; ++i) {
			int index = numbers[i] < 0 ? numbers[i] + length : numbers[i];
			if (numbers[index] < 0) {
				*duplication = numbers[index] + length;
				return 1;
			} else {
				numbers[index] -= length;
			}
		}
		return 0;
	}
};
