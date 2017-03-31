//
// Created by aleafall on 16-11-21.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 21, maxm = 11, maxk = 1001;

int n, m, k, q;
struct Win {
    int popTime, endTime;
    queue<int> q;
}win[maxn];

int main() {
    int id;
    int dur[maxk], ans[maxk];
    cin >> n >> m >> k >> q;
    int Begin = 8 * 60, End = 17 * 60;
    for (int i = 0; i < n; ++i) {
        win[i].popTime = win[i].endTime = Begin;
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &dur[i]);
    }
    for (int i = 0; i < min(n * m, k); ++i) {
        int now = i % n;
        win[now].q.push(i);
        if (i < n) {
            win[i].popTime = dur[i];
        }
        win[now].endTime += dur[i];
        ans[i] = win[now].endTime;
    }
    if (n * m < k) {
        for (int i = n * m; i < k; ++i) {
            int u = -1, Min = INT32_MAX;
            for (int j = 0; j < n; ++j) {
                if (win[j].popTime < Min) {
                    Min = win[j].popTime;
                    u = j;
                }
            }
            win[u].q.pop();
            win[u].popTime += dur[win[u].q.front()];
            win[u].endTime += dur[i];
            ans[i] = win[u].endTime;
        }
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d", &id);
        id--;
        if (ans[id] - dur[id] < End) {
            printf("%02d:%02d\n", ans[id]/ 60, ans[id] % 60);
        } else {
            cout << "Sorry\n";
        }
    }
    return 0;
}
