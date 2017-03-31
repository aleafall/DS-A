//
// Created by aleafall on 17-2-7.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode *root) {
		unordered_map<int, int> mp;
		vector<int> ans;
		int Max = 0;
		posOrder(mp, root);
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

	void posOrder(unordered_map<int, int> &mp, TreeNode *node){
		if (!node) {
			return;
		}
		posOrder(mp, node->left);
		posOrder(mp, node->right);
		if (node->left) {
			node->val += node->left->val;
		}
		if (node->right) {
			node->val += node->right->val;
		}
		if (mp.find(node->val) != mp.end()) {
			mp[node->val]++;
		} else {
			mp[node->val] = 1;
		}
	}
};
