//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        TreeLinkNode *cur;
        while (root->left) {
            cur=root;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            root = root->left;
        }
    }
};
