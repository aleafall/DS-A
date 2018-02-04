//
// Created by aleafall on 17-11-5.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
	multiset<int> s1, s2;

	void insert(int num) {
		if (!s2.empty() && num > *s2.begin()) {
			s2.insert(num);
		} else {
			s1.insert(num);
		}
		adjust();
	}

	void del(int num) {
		if (s1.count(num)) {
			s1.erase(s1.find(num));
		} else {
			s2.erase(s2.find(num));
		}
		adjust();
	}

	void adjust() {
		while (s1.size() > s2.size() + 1) {
			auto end = s1.end();
			end--;
			s2.insert(*end);
			s1.erase(end);
		}
		while (s2.size() > s1.size()) {
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
	}

	double getMed(int k) {
		if (k & 1) {
			auto end = s1.end();
			end--;
			return *end;
		} else {
			auto end1 = s1.end();
			end1--;
			auto beg2 = s2.begin();
			return *end1*0.5 + *beg2*0.5;
		}
	}

public:
	vector<double> medianSlidingWindow(vector<int> &nums, int k) {
		vector<double> ans;
		for (int i = 0; i < nums.size(); ++i) {
			insert(nums[i]);
			if (i >= k - 1) {
				ans.push_back(getMed(k));
				del(nums[i - k + 1]);
			}
		}
		return ans;
	}
};


int main() {
    multiset<int> st;
	st.insert(2);
	st.insert(2);
	cout << "size " << st.size() << endl;
	st.erase(2);
	cout << st.count(2) << endl;
	st.erase(2);
	cout << st.count(2) << endl;
    return 0;
}
