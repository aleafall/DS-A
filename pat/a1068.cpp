//
// Created by aleafall on 16-11-29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10005;

int n, a[maxn], m, total = 0;
vector<int> vi, path;

void DFS(int index, int sum) {
    if (!path.empty()) {
        return;
    }
    if (sum >= m) {
        if (sum == m) {
            path = vi;
        }
        return;
    }
    for (int i = index; i < n; ++i) {
        vi.push_back(a[i]);
        DFS(i + 1, sum + a[i]);
        vi.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        total += a[i];
    }
    if (total < m) {
        printf("No Solution\n");
        return 0;
    }
    sort(a, a + n);
    DFS(0, 0);
    if (path.empty()) {
        printf("No Solution\n");
    } else {
        for (int i = 0; i < path.size(); ++i) {
            if (i < path.size() - 1) {
                printf("%d ", path[i]);
            } else {
                printf("%d\n", path[i]);
            }
        }
    }
    return 0;
}
