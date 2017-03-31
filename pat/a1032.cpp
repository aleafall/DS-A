//
// Created by aleafall on 16-11-24.
//

#include <iostream>

using namespace std;

const int maxn = 100001;

struct Node {
    int next;
    char data;
} node[maxn];
bool vis[maxn] = {0};

int main() {
    int head1, head2, n, addr;
    cin >> head1 >> head2 >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &addr);
        scanf("%c %d", &node[addr].data, &node[addr].next);
    }
    int p = head1;
    while (p != -1) {
        vis[p] = 1;
        p = node[p].next;
    }
    p = head2;
    while (p != -1) {
        if (vis[p]) {
            printf("%05d\n", p);
            return 0;
        }
        p = node[p].next;
    }
    cout << p << endl;
    return 0;
}
