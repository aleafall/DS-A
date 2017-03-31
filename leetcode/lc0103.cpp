//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode *> q;
        bool flag = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> now;
            size_t len = q.size();
            for (size_t i = 0; i < len; ++i) {
                TreeNode *temp = q.front();
                q.pop();
                now.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            if (flag) {
                reverse(now.begin(), now.end());
            }
            flag = !flag;
            ans.push_back(now);
        }
        return ans;
    }
};
