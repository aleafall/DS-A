//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 11;

int n, index = 0;
struct Node {
    int left=-1, right=-1;
} node[maxn];

void levelOrder(int v){
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ++index;
        if (index<n) {
            cout << x << " ";
        } else {
            cout << x << endl;
        }
        if (node[x].right != -1) {
            q.push(node[x].right);
        }
        if (node[x].left != -1) {
            q.push(node[x].left);
        }
    }
}
void inOrder(int v){
    if (v == -1) {
        return;
    }
    inOrder(node[v].right);
    --index;
    if (index) {
        cout << v << " ";
    } else {
        cout << v << endl;
    }
    inOrder(node[v].left);
}
int main(){
    string s1, s2;
    int root = 0;
    bool vis[10] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        if (s1 != "-") {
            node[i].left = s1[0] - '0';
            vis[node[i].left] = 1;
        }
        if (s2 != "-") {
            node[i].right = s2[0] - '0';
            vis[node[i].right] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            root = i;
            break;
        }
    }
    levelOrder(root);
    inOrder(root);
    return 0;
}