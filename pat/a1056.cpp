//
// Created by aleafall on 16-11-26.
//

#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1001;

struct Mice {
    int weight, order;
} mice[maxn];

int main(){
    int np, ng;
    queue<int> q;
    int order[maxn];
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; ++i) {
        scanf("%d", &mice[i].weight);
    }
    for (int i = 0; i < np; ++i) {
        scanf("%d", & order[i]);
        q.push(order[i]);
    }
    if (np == 1) {
        printf("1\n");
        return 0;
    }
    while (q.size() > 1) {
        int len = (int) q.size();
        int u, Max = -1, flag = (int) ceil(1.0 * len / ng + 1);
        for (int i = 0; i < len; ++i) {
            int x = q.front();
            mice[x].order = flag;
            q.pop();
            if (mice[x].weight > Max) {
                u = x;
                Max = mice[x].weight;
            }
            if ((i + 1) % ng == 0 || i == len - 1) {
                q.push(u);
                u = -1, Max = -1;
            }
        }
        if (q.size() == 1) {
            mice[q.front()].order = 1;
        }
    }
    for (int i = 0; i < np; ++i) {
        if (i < np - 1) {
            printf("%d ", mice[i].order);
        } else {
            printf("%d\n", mice[i].order);
        }
    }
    return 0;
}
