//
// Created by aleafall on 17-2-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool judge(const vector<int> &vi,int left,int right){
		if (left >= right) {
			return 1;
		}
		int middle = left;
		while (middle < right && vi[middle] < vi[right]) {
			++middle;
		}
		for (int i = middle; i < right; ++i) {
			if (vi[i] < vi[right]) {
				return 0;
			}
		}
		return judge(vi, left, middle-1) && judge(vi, middle, right-1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) {
			return 0;
		}
		return judge(sequence, 0, sequence.size() - 1);
	}
};

int main(){
	vector<int> vi{7,4,6,5};
	Solution solution;
	cout << solution.VerifySquenceOfBST(vi) << endl;
}