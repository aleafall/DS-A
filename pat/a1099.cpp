//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 105;

int a[maxn], index = 0;
struct Node {
    int data, left, right;
} node[maxn];
void DFS(int v){
    if (v == -1) {
        return;
    }
    DFS(node[v].left);
    node[v].data = a[index++];
    DFS(node[v].right);
}
void levelOrder(int v){
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        --index;
        if (index) {
            cout << node[now].data << " ";
        } else {
            cout << node[now].data << "\n";
        }
        if (node[now].left != -1) {
            q.push(node[now].left);
        }
        if (node[now].right != -1) {
            q.push(node[now].right);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node[i].left >> node[i].right;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    DFS(0);
    levelOrder(0);
    return 0;
}
