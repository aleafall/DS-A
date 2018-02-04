//
// Created by aleafall on 17-9-26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int index = 0;
		return getString(s, index);
	}
	string getString(string &s,int &index){
		string ans;
		while (index < s.size() && s[index] != ']') {
			if (isdigit(s[index])) {
				int cnt = 0;
				while (index < s.size() && isdigit(s[index])) {
					cnt = cnt * 10 + s[index++] - '0';
				}
				++index;
				string temp= getString(s, index);
				++index;
				while (cnt-- > 0) {
					ans += temp;
				}
			} else {
				ans += s[index++];
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	string s = "2[abc]3[cd]ef";
	cout << solution.decodeString(s) << endl;
    return 0;
}