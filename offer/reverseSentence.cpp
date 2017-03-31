//
// Created by aleafall on 17-2-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.empty()) {
			return str;
		}
		reverse(str.begin(), str.end());
		int i = 0;
		while (i < str.size()) {
			int j=i;
			while (str[j] != ' ' && j < str.size()) {
				++j;
			}
			reverse(str.begin() + i, str.begin() + j);
			i = j + 1;
		}
		return str;
	}
	void split(const string &str,vector<string> &words,char c){
		size_t pos1 = 0, pos2 = str.find(c);
		while (pos2 != string::npos) {
			words.push_back(str.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
			pos2 = str.find(c, pos1);
		}
		if (pos1 != str.size()) {
			words.push_back(str.substr(pos1));
		}
	}

};

int main(){
	Solution solution;
	string str = "I am a student.";
	string ans = solution.ReverseSentence(str);
	cout << ans << endl;
}
