//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <stack>

using namespace std;

const int maxn = 31;

int pre[maxn], in[maxn];
struct Node {
    int data;
    Node *left, *right;
} *root;
int n, index = 0;

Node *create(int preL,int preR,int inL,int inR){
    if (inL > inR) {
        return NULL;
    }
    Node *root = new Node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->left = create(preL + 1, preL + numLeft, inL, k - 1);
    root->right = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}
void postOrder(Node *root){
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    --index;
    if (index) {
        cout << root->data << ' ';
    } else {
        cout << root->data << endl;
    }
}
int main(){
    cin >> n;
    int m = 0;
    stack<int> st;
    string op;
    int v;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> op;
        if (op == "Push") {
            cin >> v;
            st.push(v);
            pre[m++] = v;
        } else {
            in[index++] = st.top();
            st.pop();
        }
    }
    root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}

