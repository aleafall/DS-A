//
// Created by aleafall on 17-5-23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int hIndex(vector<int> &citations) {
		int left = 0, len = citations.size(), right = len - 1, mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (citations[mid] == (len - mid)) return citations[mid];
			else if (citations[mid] > (len - mid)) right = mid - 1;
			else left = mid + 1;
		}
		cout << "right " << right << endl;
		return len - (right + 1);
	}
};

int main() {
	vector<int> vi{1,1,1};
	Solution solution;
	cout << solution.hIndex(vi) << endl;
	return 0;
}
