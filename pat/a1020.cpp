//
// Created by aleafall on 16-11-22.
//

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 31;
int index=0,n;
int post[maxn], in[maxn];
struct Node {
    int data;
    Node *left, *right;
};

Node *create(int inL, int inR, int postL, int postR){
    if (inL > inR) {
        return NULL;
    }
    Node *root = new Node;
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->left = create(inL, k - 1, postL, postL + numLeft - 1);
    root->right = create(k + 1, inR, postL + numLeft, postR - 1);
    return root;
}

void travel(Node *root){
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        ++index;
        if (index < n) {
            cout << node->data << " ";
        } else {
            cout << node->data << endl;
        }
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}
int main(){
    cin >> n;
    for (int i = 0; i <n ; ++i) {
        cin >> post[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    Node *root = create(0, n - 1, 0, n - 1);
    travel(root);
    return 0;
}
