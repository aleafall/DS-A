//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100005;

int main() {
    int nc, np;
    int a[maxn] = {0}, b[maxn] = {0};
    cin >> nc;
    for (int i = 0; i < nc; ++i) {
        scanf("%d", &a[i]);
    }
    cin >> np;
    for (int i = 0; i < np; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + nc);
    sort(b, b + np);
    int ans = 0;
    for (int i = 0; i < nc && i < np && a[i] < 0 && b[i] < 0; ++i) {
        ans += a[i] * b[i];
    }
    int i = nc - 1, j = np - 1;
    while (i >= 0 && j >= 0 && a[i] > 0 && b[j] > 0) {
        ans += a[i] * b[j];
        --i;
        --j;
    }
    cout << ans << endl;
    return 0;
}
