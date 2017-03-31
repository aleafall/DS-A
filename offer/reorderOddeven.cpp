//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int i = 0, j = 0;
		while (i < array.size()) {
			while (i < array.size() && (array[i] & 1)) {
				++i;
			}
			for (j = i + 1; j < array.size() && !(array[j] & 1); ++j) {
				;
			}
			if (j < array.size()) {
				int temp = array[j];
				for (int k = j; k >= i; --k) {
					array[k] = array[k - 1];
				}
				array[i] = temp;
			}
			++i;
		}

	}
};

int main(){
	vector<int> vi;
	Solution solution;
	solution.reOrderArray(vi);
	for (auto item:vi) {
		cout << item << endl;
	}
	return 0;
}