//
// Created by aleafall on 16-11-26.
//

#include <iostream>

using namespace std;

const int maxn = 100005;

int main() {
    int n, m, v1, v2, a[maxn];
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v1);
        a[i] = a[i - 1] + v1;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        if (v1 > v2) {
            swap(v1, v2);
        }
        printf("%d\n", min(a[v2 - 1] - a[v1 - 1], a[n] - a[v2 - 1] + a[v1 - 1]));
    }
    return 0;
}
