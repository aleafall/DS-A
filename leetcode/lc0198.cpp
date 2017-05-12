//
// Created by aleafall on 17-3-14.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int ans = 0;
		/*vector<int> dp(nums.size(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = nums[i];
			*//*for (int j = 0; j < i; ++j) {
				if (i != j + 1) {
					dp[i] = max(dp[i], dp[j] + nums[i]);

				}
			}*//*
			if (i > 2) {
				dp[i] = max(dp[i], max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]));
			} else if (i > 1) {
				dp[i] = max(dp[i], nums[i] + dp[i - 2]);
			}
			ans = max(ans, dp[i]);
		}*/
		int pre = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int temp = max(pre + nums[i], ans);
			pre = ans;
			ans = temp;
		}
		return ans;
	}
};
void perm(string &str,int index,vector<string> &ans){
	if (index >= str.size()) {
		cout << str << endl;
		ans.push_back(str);
		return;
	}
	for (int i = index; i < str.size(); ++i) {
		swap(str[index], str[i]);
		perm(str, index + 1, ans);
		swap(str[index], str[i]);
	}
}
vector<string> per(string &str){
	vector<string> ans;
	perm(str, 0, ans);
	return ans;
}

int main(){
	string str = "123";
	auto vs = per(str);
	return 0;
}