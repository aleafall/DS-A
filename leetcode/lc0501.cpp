//
// Created by aleafall on 17-2-7.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findMode(TreeNode *root) {
		unordered_map<int,int> mp;
		vector<int> ans;
		preOrder(mp, root);
		int Max = 0;
		for (auto item:mp) {
			if (item.second > Max) {
				Max = item.second;
				ans.clear();
				ans.push_back(item.first);
			} else if (item.second == Max) {
				ans.push_back(item.first);
			}
		}
		return ans;
	}

	void preOrder(unordered_map<int, int> &mp, TreeNode *node){
		if (!node) {
			return;
		}
		if (mp.find(node->val)!=mp.end()) {
			mp[node->val]++;
		} else {
			mp[node->val] = 1;
		}
		preOrder(mp, node->left);
		preOrder(mp, node->right);
	}

};