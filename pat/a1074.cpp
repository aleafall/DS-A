//
// Created by aleafall on 16-11-29.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

struct Node {
    int addr, data, next;
    bool flag = 0;
    int order = 0;
} node[maxn];

bool cmp(Node a, Node b) {
    if (a.flag != b.flag) {
        return a.flag > b.flag;
    } else {
        return a.order < b.order;
    }
}

int main() {
    int head, addr, n, k, m = 0;
    cin >> head >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &node[addr].data, &node[addr].next);
        node[addr].addr = addr;
        node[addr].order = i;
    }
    int p = head;
    while (p != -1) {
        ++m;
        node[p].flag = 1;
        node[p].order = m;
        p = node[p].next;
    }

    sort(node, node + maxn, cmp);
    vector<Node> vi;
    for (int i = 0; i < m; ++i) {
        vi.push_back(node[i]);
    }
    for (int i = 0; i + k <= m; i += k) {
        reverse(vi.begin() + i, vi.begin() + i + k);
    }
    for (int i = 0; i < m; ++i) {
        if (i < m - 1) {
            printf("%05d %d %05d\n", vi[i].addr, vi[i].data, vi[i + 1].addr);
        } else {
            printf("%05d %d -1\n", vi[i].addr, vi[i].data);
        }
    }
    return 0;
}
