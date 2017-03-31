//
// Created by aleafall on 16-11-11.
//

#include <iostream>
#include <algorithm>
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

class Solution {
public:
    TreeNode *first, *second, *pre;

    void recoverTree(TreeNode *root) {
        inOrder(root);
        swap(first->val, second->val);
    }

    void inOrder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        if (pre && pre->val > root->val) {
            if (first == NULL) {
                first = pre;
            }
            if (first) {
                second = root;
            }
        }
        pre = root;
        inOrder(root->right);
    }
};

int main() {
    vector<int> vi{1, 2, 4, 3, 5, 6};
    int first = 0, second = 0;
    for (size_t i = 0; i < vi.size(); ++i) {
        if (i && vi[i - 1] > vi[i]) {
            first = (int) i;
        } else if (i < vi.size() - 1 && vi[i] > vi[i + 1]) {
            second = (int) i;
        }
    }
    cout << vi[first] << " " << vi[second] << endl;
    return 0;
}