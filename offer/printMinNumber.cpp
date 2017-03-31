//
// Created by aleafall on 17-2-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		string ans;
		if (numbers.empty()) {
			return ans;
		}
		sort(numbers.begin(), numbers.end(), cmp);
		for (auto &&item:numbers) {
			cout << "enter" << endl;
            ans+=to_string(item);
		}
		return ans;
	}

	static bool cmp(int a, int b) {
		return to_string(a) + to_string(b) < to_string(b) + to_string(a);
	}
};

int main(){
	Solution solution;
	vector<int> vi{3,32,321};
	string ans = solution.PrintMinNumber(vi);
	cout << ans << endl;
}
