//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode *pre = NULL, *cur = NULL;
        st.push(root);
        while (!st.empty()) {
            cur = st.top();
            if ((cur->left == NULL && cur->right == NULL) || (pre && (pre == cur->left || pre == cur->right))) {
                ans.push_back(cur->val);
                st.pop();
                pre=cur;
            } else {
                if (cur->right) {
                    st.push(cur->right);
                }
                if (cur->left) {
                    st.push(cur->left);
                }
            }
        }
        return ans;
    }
};
