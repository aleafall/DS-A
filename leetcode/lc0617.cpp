//
// Created by t-xiuyan on 6/16/2017.
//

#include <iostream>
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
	unordered_map<int,int> mp;
	TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
		if (!t1 && !t2) {
			return nullptr;
		}
		add(t1);
		add(t2);
		return createTree(1);
	}
	void add(TreeNode *node,int index){
		if (!node) {
			return;
		}
		mp[index]+=node->val;
		add(node->left,index*2);
		add(node->right,index*2+1);
	}
	TreeNode *createTree(int index){
		if (!mp.count(index)) {
			return nullptr;
		}
		TreeNode *node=new TreeNode(mp[index])	;
		node->left=createTree(index*2);
		node->right=createTree(index*2+1);
		return node;
	}
};