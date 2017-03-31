//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

struct Node {
    int data, addr, next;
    bool flag = 0;
} node[maxn];

bool cmp(Node a, Node b){
    if (a.flag != b.flag) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main(){
    int n, head, addr;
    cin >> n >> head;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &node[addr].data, &node[addr].next);
        node[addr].addr = addr;
    }
    int p = head, cnt = 0;
    while (p != -1) {
        ++cnt;
        node[p].flag = 1;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    if (cnt == 0) {
        cout << "0 -1\n";
        return 0;
    }
    printf("%d %05d\n", cnt, node[0].addr);
    for (int i = 0; i < cnt; ++i) {
        if (i < cnt - 1) {
            printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
        } else {
            printf("%05d %d -1\n", node[i].addr, node[i].data);
        }
    }
    return 0;
}
