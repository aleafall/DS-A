//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int main(){
    int n, p, ans = 0;
    int a[maxn];
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int i = 0, j = 0;
    while (j<n) {
        if ((long long) p * a[i] >= a[j]) {
            ans = max(ans, j - i + 1);
            j++;
        } else {
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}

