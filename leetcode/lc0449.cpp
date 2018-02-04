//
// Created by aleafall on 17-10-14.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		string ans;
		if (!root) {
			return ans;
		}
		vector<TreeNode*> v;
		v.push_back(root);
		for (int i = 0; i < v.size(); ++i) {
			auto now = v[i];
			if (!now) {
				continue;
			}
			v.push_back(now->left);
			v.push_back(now->right);
		}
		while (!v.empty() && !v.back()) {
			v.pop_back();
		}
		for (int i = 0; i < v.size(); ++i) {
			if (i) {
				ans += ",";
			}
			ans+=v[i]?to_string(v[i]->val):"#";
		}
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		if (data.empty()) {
			return NULL;
		}
		vector<string> values;
		int index = 0;
		while (index < data.size()) {
			string now;
			for (; index < data.size() && data[index] != ','; ++index) {
				now += data[index];
			}
			++index;
			values.push_back(now);
		}
		TreeNode *root = new TreeNode(stoi(values.front()));
		queue<TreeNode*> q;
		q.push(root);
		bool isLeft = 1;
		for (int i = 1; i < values.size(); ++i) {
			if (values[i] != "#") {
				TreeNode *node = new TreeNode(stoi(values[i]));
				if (isLeft) {
					q.front()->left = node;
				} else {
					q.front()->right = node;
				}
				q.push(node);
			}
			if (!isLeft) {
				q.pop();
			}
			isLeft = !isLeft;
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
