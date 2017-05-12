//
// Created by aleafall on 17-4-21.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1 = getV(version1), v2 = getV(version2);
		int t = (int) v1.size() - (int) v2.size();
		vector<int> &v = t > 0 ? v2 : v1;
		for (int i = 0; i < abs(t); ++i) {
			v.push_back(0);
		}
		cout << "size " << v1.size() << " " << v2.size() << endl;
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] > v2[i]) {
				return 1;
			} else if (v1[i] < v2[i]) {
				return -1;
			}
		}
		return 0;
	}

	vector<int> getV(string &v) {
		vector<int> vi;
		stringstream ss(v);
		string now;
		while (getline(ss, now, '.')) {
			if (!now.empty()) {
				vi.push_back(atoi(now.c_str()));
			}
		}
		cout << "vi ";
		for (int i = 0; i < vi.size(); ++i) {
			cout << vi[i] << " ";
		}
		cout << endl;
		return vi;
	};
};

int main() {
	string s1 = "1";
	string s2 = "1.0.1";
	Solution solution;
	cout << solution.compareVersion(s1, s2) << endl;
	return 0;
}
