//
// Created by aleafall on 16-9-28.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, a[maxn];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= i + 1)
            ans = i + 1;
        else break;
    }
    cout << ans << endl;
    return 0;
}
