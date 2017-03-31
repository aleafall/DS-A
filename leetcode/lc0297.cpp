//
// Created by aleafall on 16-11-11.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
        string s;
        vector<TreeNode*> q;
        q.push_back(root);
        for (size_t i = 0; i <q.size() ; ++i) {
            TreeNode *node = q[i];
            if (node == NULL) {
                continue;
            }
            q.push_back(node->left);
            q.push_back(node->right);
        }
        while (!q.empty() && q[q.size() - 1] == NULL) {
            q.pop_back();
        }
        if (q.empty()) {
            return s;
        }
        for (size_t i = 0; i <q.size() ; ++i) {
            if (i) {
                s += ",";
            }
            if (q[i]) {
                s += to_string(q[i]->val);
            } else {
                s += "null";
            }

        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        vector<string> vs;
        size_t index = 0;
        while (index < data.size()) {
            string now;
            for (; index < data.size() && data[index] != ','; ++index) {
                now += data[index];
            }
            ++index;
            vs.push_back(now);
        }
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(atoi(vs[0].c_str()));
        q.push(root);
        bool isLeft = 1;
        for (size_t i = 1; i < vs.size(); ++i) {
            if (vs[i] != "null") {
                TreeNode *node = new TreeNode(atoi(vs[i].c_str()));
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