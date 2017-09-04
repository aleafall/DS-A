//
// Created by t-xiuyan on 7/23/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		for (int i=0;i<s.size();){
			int j=i;
			while(j<s.size()&&s[j]!=' '){
				++j;
			}
			reverse(s.begin()+i,s.begin()+j);
			i=j;
		}
		return s;
	}
};
int main() {
	Solution solution;
	string s = "Let's take LeetCode contest";
	cout << solution.reverseWords(s) << endl;
	system("pause");
    return 0;
}
