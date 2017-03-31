//
// Created by aleafall on 16-10-18.
//

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int ans=root->val;
        inOrder(root,k,ans);
        return ans;
    }
    void inOrder(TreeNode *node,int &k,int &ans){
        if (node==NULL) return;
        inOrder(node->left,k,ans);
        k--;
        if (k==0) {
            ans=node->val;
            return;
        }
        inOrder(node->right,k,ans);
    }
};

int main(){
    TreeNode *root=new TreeNode(2);
    TreeNode *node=new TreeNode(1);
    root->left=node;
    Solution *solution=new Solution;
    cout<<solution->kthSmallest(root,1)<<endl;
    delete root;
    delete node;
    delete solution;
    return 0;
}