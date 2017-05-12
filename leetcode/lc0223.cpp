//
// Created by aleafall on 17-4-9.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int sumA = (D - B) * (C - A), sumB = (G - E) * (H - F);
		int xLeft = max(A, E), xRight = min(C, G), yLeft = max(B, F), yRight = min(D, H);
		int sumCommon = 0;
		if (xRight > xLeft && yRight > yLeft) {
			sumCommon = (xRight - xLeft) * (yRight - yLeft);
		}
		return sumA + sumB - sumCommon;
	}
};
