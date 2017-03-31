//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const int Value = 10005;

struct Node {
    int data, addr, next;
    int order = -1;
    bool flag = 0;
} node[maxn];
bool cmp(Node a,Node b){
    if (a.order == -1 || b.order == -1) {
        return a.order > b.order;
    } else if (a.flag != b.flag) {
        return a.flag > b.flag;
    }
    return a.order < b.order;
}
int main(){
    int addr, head, n, m = 0, a = 0;
    bool vis[Value]={0};
    cin >> head >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &node[addr].data, &node[addr].next);
        node[addr].addr = addr;
    }
    int p = head;
    while (p != -1) {
        ++m;
        node[p].order = m;
        if (vis[abs(node[p].data)] == 0) {
            vis[abs(node[p].data)] = 1;
            node[p].flag = 1;
            ++a;
        }
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    for (int i = 0; i < m; ++i) {
        if (i == a - 1 || i == m - 1) {
            printf("%05d %d -1\n", node[i].addr, node[i].data);
        } else {
            printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
        }
    }
    return 0;
}