//
// Created by aleafall on 17-4-8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSubStr(const string &s1, const string &s2){
		if (s1.empty()) {
			return 1;
		}
		int index = 0;
		for(auto &&item:s2) {
			if (item == s1[index]) {
				++index;
			}
		}
		return index >= s1.size();
	}
	void getHash(vector<int> &vi, const string &str){
		for (auto &&item:str) {
			++vi[item];
		}
	}
	bool isInterleave(string s1, string s2, string s3) {
		/*if (!isSubStr(s1, s3) || !isSubStr(s2, s3)) {
			return 0;
		}
		vector<int> v1(256, 0), v2(256, 0);
		getHash(v1, s1);
		getHash(v1, s2);
		getHash(v2, s3);
		return v1 == v2;*/

		if (s1.empty()) {
			return s2 == s3;
		}
		if (s2.empty()) {
			return s1 == s3;
		}
		int index1 = 0, index2 = 0, index3 = 0;
		for (auto &&item :s3) {
			if (s1[index1] == item) {
				++index1;
				++index3;
			} else if (s2[index2] == item) {
				++index2;
				++index3;
			}
		}
		return index1 >= s1.size() && index2 >= s2.size() && index3 >= s3.size();
	}
};
