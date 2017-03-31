//
// Created by aleafall on 16-10-3.
//

#include<iostream>
#include<map>

using namespace std;
struct Node {
    int data;
    Node *lchild, *rchild;
} *root;
map<int, int> mp;

void preOrder(Node *root, int depth) {
    if (root == NULL) return;
    if (mp.find(depth) != mp.end()) mp[depth]++;
    else mp[depth] = 1;
    preOrder(root->lchild, depth + 1);
    preOrder(root->rchild, depth + 1);
}

void insert(Node *&root, int data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        return;
    }
    if (data <= root->data) insert(root->lchild, data);
    else insert(root->rchild, data);
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(root, x);
    }
    preOrder(root, 1);
    int n1, n2;
    if (mp.size() > 1) {
        map<int, int>::iterator it = --mp.end();
        n1 = it->second;
        n2 = (--it)->second;
    } else {
        n1 = 1;
        n2 = 0;
    }
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
    return 0;
}

