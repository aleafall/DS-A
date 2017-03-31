//
// Created by aleafall on 17-2-23.
//


#include <iostream>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number <=2) {
			return number;
		}
		return rectCover(number - 1) + rectCover(number - 2);
	}
};
