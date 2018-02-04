//
// Created by t-xiuyan on 8/26/2017.
//

#include <iostream>
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
	vector<vector<int>> ans;
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<int> vi;
		DFS(vi, root, 0, sum);
		return ans;
	}
	void DFS(vector<int> vi,TreeNode *node,int part,int sum){
		if (!node) {
			return;
		}
		vi.push_back(node->val);
		part += node->val;
		if (!node->left && !node->right && part == sum) {
			ans.push_back(vi);
			return;
		}
		DFS(vi, node->left, part, sum);
		DFS(vi, node->right, part, sum);
	}
};
