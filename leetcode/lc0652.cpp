//
// Created by t-xiuyan on 8/24/2017.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
		unordered_map<string,vector<TreeNode*>> mp;
		vector<TreeNode*> ans;
		serialize(root, mp);
		for (auto &&item :mp) {
			if (item.second.size() > 1) {
				ans.push_back(item.second[0]);
			}
		}
		return ans;
	}
	string serialize(TreeNode *node,unordered_map<string,vector<TreeNode*>> &mp){
		if (!node) {
			return "";
		}
		string now = "(" + serialize(node->left, mp) + to_string(node->val) + serialize(node->right, mp) + ")";
		mp[now].push_back(node);
		return now;
	}

};
