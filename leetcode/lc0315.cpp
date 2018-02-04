//
// Created by aleafall on 17-9-21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	struct Node {
		Node(int x) {
			id = x;
			cnt = 0;
			left = NULL;
			right = NULL;
		}

		int id, cnt;
		Node *left, *right;
	}*root;
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> ans(nums.size());
		root = NULL;
		for (int i = nums.size()-1; i >= 0; --i) {
			insert(root, i, nums);
		}
		preOrder(root, ans);
		return ans;
	}
	void insert(Node *&node,int x,vector<int> &nums,int pre){
		if (!node) {
			node = new Node(x);
			node->cnt = pre;
			return;
		}
		node->cnt += pre;
		if (nums[node->id] > nums[x]) {
			node->cnt++;
			insert(node->left, x, nums,pre);
		} else {
			insert(node->right, x, nums);
		}
	}
	void preOrder(Node *node,vector<int> &ans){
		if (!node) {
			return;
		}
		ans[node->id] = node->cnt;
		preOrder(node->left, ans);
		preOrder(node->right, ans);
	}
};
