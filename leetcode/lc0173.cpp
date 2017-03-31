//
// Created by aleafall on 16-10-17.
//

#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for binary tree
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode *root;
    BSTIterator(TreeNode *root) {
        this->root=root;
        while (!st.empty()) st.pop();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (root!=NULL||!st.empty());
    }

    /** @return the next smallest number */
    int next() {
        while (root!=NULL){
            st.push(root);
            root=root->left;
        }
        root=st.top();st.pop();
        TreeNode *ans=root;
        root=root->right;
        return ans->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(){

}