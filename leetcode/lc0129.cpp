//
// Created by aleafall on 16-11-9.
//

#include <iostream>
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
    int ans=0;

    int sumNumbers(TreeNode *root) {
        DFS(root, 0);
        return ans;
    }

    void DFS(TreeNode *root, int now){
        if (root == NULL) {
            return;
        }
        now=now*10+root->val;
        if (root->left == NULL && root->right == NULL) {
            ans+=now;
        }
        DFS(root->left, now);
        DFS(root->right, now);
    }


};

int main(){
    Solution solution;
    TreeNode *node[4];
    node[0] = new TreeNode(4);
    node[1] = new TreeNode(9);
    node[2] = new TreeNode(1);
    node[3] = new TreeNode(0);
    node[0]->left = node[1];
    node[0]->right = node[3];
    node[1]->right = node[2];
    cout<<solution.sumNumbers(node[0])<<endl;
    for (int i = 0; i < 4; ++i) {
        delete node[i];
    }
    return 0;
}
