//
// Created by aleafall on 16-12-4.
//

#include <iostream>

using namespace std;

const int maxn = 21;

struct Node {
    int left = -1, right = -1;
} node[maxn];

int max_index = 0, last = 0;

void preOrder(int v, int index) {
    if (v == -1) {
        return;
    }
    if (index > max_index) {
        max_index = index;
        last = v;
    }
    preOrder(node[v].left, 2 * index);
    preOrder(node[v].right, 2 * index + 1);
}

int main() {
    int n, x, root = 0;
    bool vis[maxn] = {0};
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        if (s1 != "-") {
            x = atoi(s1.c_str());
            node[i].left = x;
            vis[x] = 1;
        }
        if (s2 != "-") {
            x = atoi(s2.c_str());
            node[i].right = x;
            vis[x] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            root = i;
            break;
        }
    }
    preOrder(root, 1);
    if (max_index == n) {
        cout << "YES " << last << endl;
    } else {
        cout << "NO " << root << endl;
    }
    return 0;
}
