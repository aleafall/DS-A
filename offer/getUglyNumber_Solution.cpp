//
// Created by aleafall on 17-2-23.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		int cnt = 0, a[3]{2, 3, 5};
		set<long long > st;
		long long cur = 0;
		st.insert(1);
		while (cnt < index) {
			cur = *st.begin();
			st.erase(st.begin());
			for (int i = 0; i < 3; ++i) {
				st.insert(cur * a[i]);
			}
			++cnt;
		}
		return (int) cur;
	}
};

int main(){
	Solution solution;
	for (int i = 0; i < 10; ++i) {
		cout << solution.GetUglyNumber_Solution(i + 1) << endl;
	}
	return 0;
}
