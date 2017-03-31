//
// Created by aleafall on 16-11-23.
//

#include <iostream>

using namespace std;

const int maxn = 1000005;
int a[maxn], b[maxn];

int findMid(int a[], int b[], int m, int n, int k) {
    if (m > n) {
        return findMid(b, a, n, m, k);
    }
    if (m == 0) {
        return b[k - 1];
    }
    if (k == 1) {
        return min(a[0], b[0]);
    }
    int ia = min(m, k / 2);
    int ib = k - ia;
    if (a[ia - 1] < b[ib - 1]) {
        return findMid(a + ia, b, m - ia, n, k - ia);
    } else if (a[ia - 1] > b[ib - 1]) {
        return findMid(a, b + ib, m, n - ib, k - ib);
    } else {
        return a[ia - 1];
    }
}

int main() {
    int m, n;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    int mid = (m + n + 1) / 2;
    cout << findMid(a, b, m, n, mid) << endl;
    return 0;
}
