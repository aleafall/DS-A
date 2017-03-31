//
// Created by aleafall on 17-2-25.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> vi;
	void Insert(int num) {
		vi.push_back(num);
	}

	double GetMedian() {
		sort(vi.begin(), vi.end());
		int mid = (int) ((vi.size()) / 2);
		return (vi.size() & 1) ? vi[mid] : (vi[mid-1] + vi[mid]) / 2.0;
	}

};

int main(){
	vector<int> vi{5, 2, 3, 4, 1, 6, 7, 0, 8};
	Solution solution;
	for (int i = 0; i < vi.size(); ++i) {
		solution.Insert(vi[i]);
		cout << solution.GetMedian() << endl;
	}
	return 0;
}