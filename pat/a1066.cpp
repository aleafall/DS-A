//
// Created by aleafall on 16-12-10.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
} *root, *null;

void updateHeight(Node *node) {
    node->height = max(node->left->height, node->right->height) + 1;
}

void L(Node *&node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    updateHeight(node);
    updateHeight(temp);
    node = temp;
}

void R(Node *&node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    updateHeight(node);
    updateHeight(temp);
    node = temp;
}

void insert(Node *&node, int data) {
    if (node == null) {
        node = new Node;
        node->data = data;
        node->height = 1;
        node->left = node->right = null;
        return;
    }
    if (data < node->data) {
        insert(node->left, data);
        updateHeight(node);
        if (node->left->height - node->right->height > 1) {
            if (node->left->left->height - node->left->right->height == 1) {
                R(node);
            } else if (node->left->left->height - node->left->right->height == -1) {
                L(node->left);
                R(node);
            }
        }
    } else {
        insert(node->right, data);
        updateHeight(node);
        if (node->right->height - node->left->height > 1) {
            if (node->right->right->height - node->right->left->height == 1) {
                L(node);
            } else if (node->right->right->height - node->right->left->height == -1) {
                R(node->right);
                L(node);
            }
        }
    }
}

void init() {
    null = new Node;
    null->height = 0;
    root = null;
}

int main() {
    init();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        insert(root, x);
    }
    cout << root->data << endl;
    return 0;
}
