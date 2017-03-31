//
// Created by aleafall on 16-11-25.
//

#include <iostream>
#include <vector>

using namespace std;

int n, index = 0;

struct Node {
    int data;
    Node *left, *right;
} *root;

vector<int> pre, preMirror;

void preOrder(Node *root){
    if (!root) {
        return;
    }
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    ++index;
    if (index<n){
        cout << root->data << " ";
    } else {
        cout << root->data << endl;
    }
}
void postMirrorOrder(Node *root){
    if (!root) {
        return;
    }
    postMirrorOrder(root->right);
    postMirrorOrder(root->left);
    ++index;
    if (index<n){
        cout << root->data << " ";
    } else {
        cout << root->data << endl;
    }
}
void preMirrorOrder(Node *root){
    if (!root) {
        return;
    }
    preMirror.push_back(root->data);
    preMirrorOrder(root->right);
    preMirrorOrder(root->left);
}
void insert(Node *&root, int data){
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}
int main(){
    int v;
    vector<int> ori;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        insert(root, v);
        ori.push_back(v);
    }
    preOrder(root);
    if (pre == ori) {
        cout << "YES\n";
        postOrder(root);
    } else if (preMirrorOrder(root), preMirror == ori) {
        cout << "YES\n";
        postMirrorOrder(root);
    } else {
        cout << "NO\n";
    }
    return 0;
}