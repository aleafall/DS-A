//
// Created by aleafall on 17-4-20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		string ans = getHundred(num % 1000);
		vector<string> v = {"Thousand", "Million", "Billion"};
		for (int i = 0; i < 3; ++i) {
			num /= 1000;
			ans = num % 1000 ? getHundred(num % 1000) + " " + v[i] + " " + ans : ans;
		}
		while (ans.back() == ' ') {
			ans.pop_back();
		}
		return ans.empty() ? "Zero" : ans;
	}

	string getHundred(int num) {
		vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
		                     "Nineteen"};
		vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		string ans;
		int a = num / 100, b = num % 100, c = num % 10;
		ans = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
		ans = a ? v1[a] + " Hundred" + (ans.empty() ? "" : " " + ans) : ans;
		return ans;
	}
};

int main(){
	Solution solution;
	cout << solution.numberToWords(1234567) << endl;
}
