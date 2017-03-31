//
// Created by aleafall on 16-12-4.
//

#include <iostream>

using namespace std;

const int maxn = 31;

struct Node {
    int data;
    Node *left=NULL, *right=NULL;
} *root;

int n, index = 0;
int pre[maxn], post[maxn];
bool flag = 1;

Node *create(int preL,int preR,int postL,int postR){
    if (preL > preR) {
        return NULL;
    }
    Node *node = new Node;
    node->data = pre[preL];
    if (preL == preR) {
        return node;
    }
    int k;
    for (k = preL + 1; k <= preR; ++k) {
        if (pre[k] == post[postR - 1]) {
            break;
        }
    }
    int numLeft = k - preL - 1;
    if (numLeft > 0) {
        node->left = create(preL + 1, k-1, postL,postL+numLeft-1);
        node->right = create(k, preR, postL + numLeft, postR - 1);
    } else {
        flag = 0;
        node->right = create(k, preR, postL + numLeft, postR - 1);
    }
    return node;
}
void inOrder(Node *node){
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    ++index;
    if (index < n) {
        cout << node->data << " ";
    } else {
        cout << node->data << endl;
    }
    inOrder(node->right);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i <n; ++i) {
        cin >> post[i];
    }
    root = create(0, n - 1, 0, n - 1);
    flag ? cout << "Yes\n" : cout << "No\n";
    inOrder(root);
    return 0;
}
