//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <vector>
#include <map>

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
    map<int,int> mp;

    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        preOrder(root, 0);
        for (auto item:mp) {
            ans.push_back(item.second);
        }
        return ans;
    }

    void preOrder(TreeNode *root, int level){
        if (root == NULL) {
            return;
        }
        if (mp.find(level) == mp.end()) {
            mp[level] = root->val;
        }
        preOrder(root->right, level + 1);
        preOrder(root->left, level + 1);
    }
};
