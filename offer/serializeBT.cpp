//
// Created by aleafall on 17-2-24.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	char *Serialize(TreeNode *root) {
		string ans;
		if (!root) {
			return (char *) ans.c_str();
		}
		return (char *) ans.c_str();

	}
	void preOrder(TreeNode *root,string &ans){
		if (!ans.empty()) {
			ans += ',';
		}
		if (!root) {
			ans += '#';
			return;
		}
		ans += to_string(root->val);
		preOrder(root->left, ans);
		preOrder(root->right, ans);
	}

	TreeNode *Deserialize(char *str) {

	}
};

int main(){
	TreeNode *node[4];
	for (int i = 0; i < 4; ++i) {
		node[i] = new TreeNode(i + 1);
	}
	node[0]->left = node[1], node[0]->right = node[2];
	node[2]->left = node[3];
	Solution solution;
	char *str = solution.Serialize(node[0]);
	cout << str << endl;
	for (int i = 0; i < 4; ++i) {
		delete node[i];
	}
}